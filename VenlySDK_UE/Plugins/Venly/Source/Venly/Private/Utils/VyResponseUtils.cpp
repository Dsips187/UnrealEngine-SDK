// Fill out your copyright notice in the Description page of Project Settings.


#include "Utils/VyResponseUtils.h"

namespace VyResponseUtils
{
	void ParseResponseErrors(const FVyRequestContext& Context, const FVyResponseContext& ResponseContext, TArray<FVyResponseError>& OutErrors)
	{
		OutErrors.Empty();

		const auto ResponseCode = ResponseContext.Code;
		const auto ResponseContent = ResponseContext.Content;

		if (ResponseContent.IsEmpty())
		{
			CreateResponseErrors(Context, EHttpResponseCodes::GetDescription(static_cast<EHttpResponseCodes::Type>(ResponseCode)).ToString(), TEXT("Unsuccesful Response Code Received"), OutErrors);
			return;
		}

		TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
		if (!FJsonSerializer::Deserialize(TJsonReaderFactory<TCHAR>::Create(ResponseContent), JsonObject) && JsonObject.IsValid())
		{
			CreateResponseErrors(Context, TEXT("Parsing Error"), TEXT("VyBackendCore::ParseResponseError(...) - Failed to parse received error json"), OutErrors);
			return;
		}

		if (Context.ResponseEnveloped)
		{
			const auto ErrorField = JsonObject->GetArrayField("errors");
			if (!FJsonObjectConverter::JsonArrayToUStruct(ErrorField, &OutErrors))
			{
				CreateResponseErrors(Context, TEXT("Conversion Error"), TEXT("VyBackendCore::ParseResponseError(...) - Failed to convert JsonObject to TArray<FVyResponseError> (envelopped)"), OutErrors);
			}

			return;
		}
	}

	void CreateResponseErrors(const FVyRequestContext& Context, const FString& Code, const FString& Message, TArray<FVyResponseError>& OutErrors)
	{
		OutErrors.Empty();
		OutErrors.Add(FVyResponseError{ Code, Message });
	}

	FVyResponseContext CreateResponseContext_Failure(int32 HttpErrorCode, const FString& ErrorCode, const FString& ErrorMessage, const FString& TraceMessage)
	{
		FVyResponseContext responseCtx{};
		responseCtx.Code = HttpErrorCode;

		FVyApiResponse failResponse{};
		failResponse.Success = false;
		failResponse.Errors.Add(
			FVyResponseError{
				ErrorCode,
				ErrorMessage,
				TraceMessage
			});

		if (!FJsonObjectConverter::UStructToJsonObjectString(failResponse, responseCtx.Content, 0, 0, 0, nullptr, false))
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to Create FailResponseContext... (UStructToJsonObjectString)"))
		}

		return responseCtx;
	}

	FVyResponseContext CreateResponseContext_Failure(const FString& ErrorCode, const FString& ErrorMessage, const FString& TraceMessage)
	{
		return CreateResponseContext_Failure(EHttpResponseCodes::Denied, ErrorCode, ErrorMessage, TraceMessage);
	}

	FVyResponseContext CreateResponseContext_ServerResponse(const FVyServerResponse& ServerResponse, const FString& ErrorCode)
	{
		if(!ServerResponse.Success)
		{
			return VyResponseUtils::CreateResponseContext_Failure(ServerResponse.StatusCode, ErrorCode, ServerResponse.ErrorMessage);
		}

		if (ServerResponse.IsDataEncoded)
		{
			FString decodedData{};
			FBase64::Decode(ServerResponse.Data, decodedData);
			return { ServerResponse.StatusCode, decodedData, ServerResponse.IsRawResponse};
		}
		
		return { ServerResponse.StatusCode, ServerResponse.Data, ServerResponse.IsRawResponse };
	}
}
