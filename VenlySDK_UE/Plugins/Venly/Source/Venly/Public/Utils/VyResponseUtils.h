// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Models/VyCoreModels.h"
#include "Interfaces/IHttpResponse.h"

namespace VyResponseUtils
{
	//Response Parsing Helpers
	void ParseResponseErrors(const FVyRequestContext& Context, const FVyResponseContext& ResponseContext, TArray<FVyResponseError>& OutErrors);
	void CreateResponseErrors(const FVyRequestContext& Context, const FString& Code, const FString& Message, TArray<FVyResponseError>& OutErrors);

	FVyResponseContext VENLY_API CreateResponseContext_Failure(const FString& ErrorCode, const FString& ErrorMessage, const FString& TraceMessage = TEXT(""));
	FVyResponseContext VENLY_API CreateResponseContext_Failure(int32 HttpErrorCode, const FString& ErrorCode, const FString& ErrorMessage, const FString& TraceMessage = TEXT(""));

	FVyResponseContext VENLY_API CreateResponseContext_ServerResponse(const FVyServerResponse& ServerResponse, const FString& ErrorCode = TEXT(""));

	/**
	 * @brief Parses the Response of an HTTP call into the given Response structure (includes error/validation checking)
	 * @tparam TApiResponse The type of the (wrapped) response structure (should derive from FVyApiResponse)
	 * @tparam TInnerResult The type of the result wrapped inside TApiResponse (if array, the type of a single element)
	 * @param Context The request context of the corresponding HTTP call
	 * @param ResponseContext The response context of the corresponding HTTP call
	 * @param OutResponse The deserialized result of the HTTP call
	 */
	template<typename TApiResponse, typename TInnerResult>
	void ParseResponse(const FVyRequestContext& Context, const FVyResponseContext& ResponseContext, TApiResponse& OutResponse)
	{
		//Gather Response Data 
		const auto ResponseCode = ResponseContext.Code;
		const auto ResponseContent = ResponseContext.Content;

		//Set Response Context
		OutResponse.ResponseContext = ResponseContext;

		//Parse JSON
		if (ResponseContext.IsContentEnveloped)
		{
			if (!DeserializeResponse_Enveloped<TInnerResult, TApiResponse>(Context, ResponseContent, OutResponse))
			{
				OutResponse.Success = false;
				CreateResponseErrors(Context, TEXT("Parsing Error"), TEXT("VyBackendCore::ParseResponse(...) - Failed to deserialize response into output type (enveloped)"), OutResponse.Errors);

				return;
			}
		}
		else
		{
			if (EHttpResponseCodes::IsOk(ResponseCode))
			{
				OutResponse.Success = true;
				if (!DeserializeResponse_NotEnveloped<TInnerResult, TApiResponse>(Context, ResponseContent, OutResponse))
				{
					OutResponse.Success = false;
					CreateResponseErrors(Context, TEXT("Parsing Error"), TEXT("VyBackendCore::ParseResponse(...) - Failed to deserialize response into output type"), OutResponse.Errors);

					return;
				}
			}
			else
			{
				//Parse Error
				OutResponse.Success = false;
				ParseResponseErrors(Context, ResponseContext, OutResponse.Errors);

				return;
			}
		}
	}

	//##############
	//RESULT AS VOID
	//##############
	/**
	 * @brief Helper Function to Deserialize a Non-Enveloped Response without a Result Parameter (VOID)
	 * Template Variation > Deserialize Response Content (NOT-ENVELOPED | VOID)
	 * This function does nothing because nothing needs to be deserialized (always true)
	 * @tparam TInnerResult Type of the Result parameter
	 * @tparam TApiResponse Wrapped result structure
	 * @param Context Request Context of the corresponding HTTP call
	 * @param JsonString JSON string representing the response content
	 * @param OutStruct The resulting response structure based on the inputted JSON string
	 * @return Flag indicating if the data was correctly deserialized
	 */
	template <typename TInnerResult, typename TApiResponse>
	std::enable_if_t<
		!std::is_base_of_v<FVyResponseTrait_VariantResult, TApiResponse>&&
		std::is_same_v<FVyApiUnitResponse, TApiResponse>,
		bool>
		DeserializeResponse_NotEnveloped(const FVyRequestContext& Context, const FString& JsonString, TApiResponse& OutStruct)
	{
		return true;
	}

	/**
	 * @brief Helper Function to Deserialize a Enveloped Response without a Result Parameter (VOID)
	 * Template Variation > Deserialize Response Content (ENVELOPED | VOID)
	 * @tparam TInnerResult Type of the Result parameter
	 * @tparam TApiResponse Wrapped result structure
	 * @param Context Request Context of the corresponding HTTP call
	 * @param JsonString JSON string representing the response content
	 * @param OutStruct The resulting response structure based on the inputted JSON string
	 * @return Flag indicating if the data was correctly deserialized
	 */
	template <typename TInnerResult, typename TApiResponse>
	std::enable_if_t<
		!std::is_base_of_v<FVyResponseTrait_VariantResult, TApiResponse>&&
		std::is_same_v<FVyApiUnitResponse, TApiResponse>,
		bool>
		DeserializeResponse_Enveloped(const FVyRequestContext& Context, const FString& JsonString, TApiResponse& OutStruct)
	{
		//USTRUCT Deserialization (skip array specialization)
		return VyJsonUtils::JsonObjectStringToUStruct(JsonString, &OutStruct);
	}

	//#################
	//RESULT AS USTRUCT
	//#################
	/**
	 * @brief Helper Function to Deserialize a Non-Enveloped Response with a USTRUCT Result parameter
	 * Template Variation > Deserialize Response Content (NOT-ENVELOPED | USTRUCT)
	 * @tparam TInnerResult Type of the Result parameter
	 * @tparam TApiResponse Wrapped result structure
	 * @param Context Request Context of the corresponding HTTP call
	 * @param JsonString JSON string representing the response content
	 * @param OutStruct The resulting response structure based on the inputted JSON string
	 * @return Flag indicating if the data was correctly deserialized
	 */
	template <typename TInnerResult, typename TApiResponse>
	std::enable_if_t<
		!std::is_base_of_v<FVyResponseTrait_VariantResult, TApiResponse> &&
		!std::is_same_v<FVyApiUnitResponse, TApiResponse>,
		bool>
		DeserializeResponse_NotEnveloped(const FVyRequestContext& Context, const FString& JsonString, TApiResponse& OutStruct)
	{
		//USTRUCT Deserialization
		return VyJsonUtils::DeserializeToUStruct<TInnerResult>(JsonString, OutStruct.Result);
	}

	/**
	 * @brief Helper Function to Deserialize a Enveloped Response with a USTRUCT Result parameter
	 * Template Variation > Deserialize Response Content (ENVELOPED | USTRUCT)
	 * @tparam TInnerResult Type of the Result parameter
	 * @tparam TApiResponse Wrapped result structure
	 * @param Context Request Context of the corresponding HTTP call
	 * @param JsonString JSON string representing the response content
	 * @param OutStruct The resulting response structure based on the inputted JSON string
	 * @return Flag indicating if the data was correctly deserialized
	 */
	template <typename TInnerResult, typename TApiResponse>
	std::enable_if_t<
		!std::is_base_of_v<FVyResponseTrait_VariantResult, TApiResponse> &&
		!std::is_same_v<FVyApiUnitResponse, TApiResponse>,
		bool>
		DeserializeResponse_Enveloped(const FVyRequestContext& Context, const FString& JsonString, TApiResponse& OutStruct)
	{
		//USTRUCT Deserialization
		return VyJsonUtils::DeserializeToUStruct<TInnerResult>(JsonString, OutStruct);
	}

	//#################
	//RESULT AS VARIANT (Manual Parsing)
	//#################
	/**
	 * @brief Helper Function to Deserialize a Non-Enveloped Response with a VARIANT (non-ustruct/primitives/...) Result parameter
	 * Template Variation > Deserialize Response Content (NOT-ENVELOPED | VARIANT)
	 * This variation also handles the optional SelectProperty mechanism
	 * @tparam TInnerResult Type of the Result parameter
	 * @tparam TApiResponse Wrapped result structure
	 * @param Context Request Context of the corresponding HTTP call
	 * @param JsonString JSON string representing the response content
	 * @param OutStruct The resulting response structure based on the inputted JSON string
	 * @return Flag indicating if the data was correctly deserialized
	 */
	template <typename TInnerResult, typename TApiResponse>
	std::enable_if_t<
		std::is_base_of_v<FVyResponseTrait_VariantResult, TApiResponse> &&
		!std::is_same_v<FVyApiUnitResponse, TApiResponse>,
		bool>
		DeserializeResponse_NotEnveloped(const FVyRequestContext& Context, const FString& JsonString, TApiResponse& OutStruct)
	{
		TSharedPtr<FJsonValue> JsonValue;
		const TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(JsonString);
		if (!FJsonSerializer::Deserialize(JsonReader, JsonValue)) return false;

		//Select Specific Property
		if (Context.UseSelectProperty)
		{
			return DeserializeSelectProperty<TInnerResult>(Context, JsonValue, OutStruct.Result);
		}

		return DeserializeJsonValue<TInnerResult>(JsonValue, OutStruct.Result);
	}

	/**
	 * @brief Helper Function to Deserialize a Enveloped Response with a VARIANT (non-ustruct/primitives/...) Result parameter
	 * Template Variation > Deserialize Response Content (ENVELOPED | VARIANT)
	 * This variation also handles the optional SelectProperty mechanism
	 * @tparam TInnerResult Type of the Result parameter
	 * @tparam TApiResponse Wrapped result structure
	 * @param Context Request Context of the corresponding HTTP call
	 * @param JsonString JSON string representing the response content
	 * @param OutStruct The resulting response structure based on the inputted JSON string
	 * @return Flag indicating if the data was correctly deserialized
	 */
	template <typename TInnerResult, typename TApiResponse>
	std::enable_if_t<
		std::is_base_of_v<FVyResponseTrait_VariantResult, TApiResponse> &&
		!std::is_same_v<FVyApiUnitResponse, TApiResponse>,
		bool>
		DeserializeResponse_Enveloped(const FVyRequestContext& Context, const FString& JsonString, TApiResponse& OutStruct)
	{
		TSharedPtr<FJsonObject> JsonObject;
		const TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(JsonString);
		if (!FJsonSerializer::Deserialize(JsonReader, JsonObject)) return false;

		if (!JsonObject->TryGetBoolField(TEXT("success"), OutStruct.Success)) return false; //find 'success' field
		if (!OutStruct.Success) return false; //no need to go any further (succes is FALSE) > Parse Error Fallback

		const auto resultField = JsonObject->TryGetField(TEXT("result")); //find 'result' field
		if (!resultField.IsValid()) return false; //no need to go any further (result is invalid)

		//Select Specific Property
		if (Context.UseSelectProperty)
		{
			return DeserializeSelectProperty<TInnerResult>(Context, resultField, OutStruct.Result);
		}

		return DeserializeJsonValue<TInnerResult>(resultField, OutStruct.Result);
	}

	//###########################
	//DESERIALIZE SELECT-PROPERTY
	//###########################
	/**
	 * @brief Helper function to Deserialize a JsonValue while selecting only a part of the Json content
	 * Template Variation > (NOT-ARRAY) OBJECT JsonValue 
	 * @tparam TInnerResult The type of a single element if TResult is an Array, if not, TInnerResult and TResult should be the same type
	 * @tparam TResult The requested type of the JsonValue after deserialization
	 * @param Context The request context of the corresponding HTTP Call
	 * @param JsonValue The value containing the data to be deserialized to the TResult type
	 * @param OutParam The result of the deserialized JsonValue
	 * @return 
	 */
	template<typename TInnerResult, typename TResult>
	std::enable_if_t<!TIsTArray<TResult>::Value, bool>
		DeserializeSelectProperty(const FVyRequestContext& Context, TSharedPtr<FJsonValue> JsonValue, TResult& OutParam)
	{
		if (JsonValue->Type != EJson::Object) return false;

		const auto selectPropertyField = JsonValue->AsObject()->TryGetField(Context.SelectPropertyName);
		if (!selectPropertyField.IsValid()) return false;
		return DeserializeJsonValue<TResult>(selectPropertyField, OutParam);
	}

	/**
	 * @brief Helper function to Deserialize a JsonValue while selecting only a part of the Json content
	 * Template Variation > (ARRAY) OBJECT/ARRAY JsonValue (Array of Objects, or, Object containing Array)
	 * @tparam TInnerResult The type of a single element if TResult is an Array, if not, TInnerResult and TResult should be the same type
	 * @tparam TResult The requested type of the JsonValue after deserialization
	 * @param Context The request context of the corresponding HTTP Call
	 * @param JsonValue The value containing the data to be deserialized to the TResult type
	 * @param OutParam The result of the deserialized JsonValue
	 * @return
	 */
	template<typename TInnerResult, typename TResult>
	std::enable_if_t<TIsTArray<TResult>::Value, bool>
		DeserializeSelectProperty(const FVyRequestContext& Context, TSharedPtr<FJsonValue> JsonValue, TResult& OutParam)
	{
		//array wrapped in object
		if (JsonValue->Type == EJson::Object)
		{
			const auto selectPropertyValue = JsonValue->AsObject()->TryGetField(Context.SelectPropertyName);
			if (!selectPropertyValue.IsValid()) return false;

			if (selectPropertyValue->Type != EJson::Array) return false; //must be array

			TArray<TSharedPtr<FJsonValue>>* JsonArray;
			if (selectPropertyValue->TryGetArray(JsonArray))
			{
				for (const auto subJsonValue : *JsonArray)
				{
					TInnerResult val;
					if (DeserializeJsonValue_Unit<TInnerResult>(subJsonValue, val))
					{
						OutParam.Add(val);
					}
					else
					{
						UE_LOG(LogVenlyBackend, Error, TEXT("DeserializeSelectPropertyArray()[Object] >> Failed to convert value to Target Value"))
							return false;
					}
				}

				return true;
			}
		}

		if (JsonValue->Type == EJson::Array)
		{
			//Array of Objects
			TArray<TSharedPtr<FJsonValue>>* JsonArray;
			if (JsonValue->TryGetArray(JsonArray))
			{
				for (const auto subJsonValue : *JsonArray)
				{
					TInnerResult val;
					if (DeserializeSelectProperty<TInnerResult>(Context, subJsonValue, val))
					{
						OutParam.Add(val);
					}
					else
					{
						UE_LOG(LogVenlyBackend, Error, TEXT("DeserializeSelectPropertyArray()[Array] >> Failed to convert value to Target Value"))
							return false;
					}
				}

				return true;
			}
		}

		return false;
	}

	//######################
	//DESERIALIZE JSON-VALUE
	//######################

	//DESERIALIZE JSON_VALUE [ARRAY]
	/**
	 * @brief Deserializes a JsonValue to an Array
	 * Template Variation >> Active if TResult is TArray (TResult = TArray<TInnerResult>)
	 * @tparam TInnerResult The type of a single element
	 * @tparam TResult The type of the outputted value
	 * @param JsonValue The JsonValue to deserialize
	 * @param OutParam The resulting value
	 * @return Flag indicating if the JsonValue was successfully deserialized
	 */
	template<typename TInnerResult, typename TResult>
	std::enable_if_t<TIsTArray<TResult>::Value, bool>
		DeserializeJsonValue(TSharedPtr<FJsonValue> JsonValue, TResult& OutParam)
	{
		if (JsonValue->Type != EJson::Array) return false;
		//return DeserializeJsonValue_Array<TInnerResult, TResult>(Context, JsonValue, OutParam);

		TArray<TSharedPtr<FJsonValue>>* JsonArray;
		if (JsonValue->TryGetArray(JsonArray))
		{
			for (const auto subJsonValue : *JsonArray)
			{
				TInnerResult val;
				if (DeserializeJsonValue_Unit<TInnerResult>(subJsonValue, val))
				{
					OutParam.Add(val);
				}
				else
				{
					UE_LOG(LogVenlyBackend, Error, TEXT("DeserializeJsonValue()[Array] >> Failed to convert value to Target Value"))
						return false;
				}
			}

			return true;
		}

		return false;
	}

	//DESERIALIZE JSON_VALUE [NOT_ARRAY]
	/**
	 * @brief Deserializes a JsonValue to a single/unit value
	 * Template Variation >> Active if TResult is NOT a TArray (TResult = TInnerResult)
	 * @tparam TInnerResult The type of a single element
	 * @tparam TResult The type of the outputted value (should be same as TInnerResult)
	 * @param JsonValue The JsonValue to deserialize
	 * @param OutParam The resulting value
	 * @return Flag indicating if the JsonValue was successfully deserialized
	 */
	template<typename TInnerResult, typename TResult>
	std::enable_if_t<!TIsTArray<TResult>::Value, bool>
		DeserializeJsonValue(TSharedPtr<FJsonValue> JsonValue, TResult& OutParam)
	{
		return DeserializeJsonValue_Unit<TResult>(JsonValue, OutParam);
	}

	//######################
	//DESERIALIZE JSON-VALUE (UNIT)
	//######################
	//DESERIALIZE JSON-VALUE >> BOOL
	/**
	 * @brief Deserialize a JsonValue to a Boolean
	 * @tparam TResult Type of the resulting value (template = bool)
	 * @param JsonValue The JsonValue to deserialize
	 * @param OutParam The resulting boolean value
	 * @return Flag indicating if the JsonValue was successfully deserialized
	 */
	template<typename TResult>
	std::enable_if_t<std::is_same_v<TResult, bool>, bool>
		DeserializeJsonValue_Unit(TSharedPtr<FJsonValue> JsonValue, TResult& OutParam)
	{
		return JsonValue->TryGetBool(OutParam);
	}

	//DESERIALIZE JSON-VALUE >> ENUM
	/**
	 * @brief Deserialize a JsonValue to an enum Type
	 * @tparam TResult Type of the resulting value (template = Enum class)
	 * @param JsonValue The JsonValue to deserialize
	 * @param OutParam The resulting enum value
	 * @return Flag indicating if the JsonValue was successfully deserialized
	 */
	template<typename TResult>
	std::enable_if_t<TIsEnumClass<TResult>::Value, bool>
		DeserializeJsonValue_Unit(TSharedPtr<FJsonValue> JsonValue, TResult& OutParam)
	{
		return VyUtils::TryJsonValueToEnum(JsonValue, OutParam);
	}

	//DESERIALIZE JSON-VALUE >> FSTRING
	/**
	 * @brief Deserialize a JsonValue to a FString
	 * @tparam TResult Type of the resulting value (template = FString)
	 * @param JsonValue The JsonValue to deserialize
	 * @param OutParam The resulting FString value
	 * @return Flag indicating if the JsonValue was successfully deserialized
	 */
	template<typename TResult>
	std::enable_if_t<std::is_same_v<TResult, FString>, bool>
		DeserializeJsonValue_Unit(TSharedPtr<FJsonValue> JsonValue, TResult& OutParam)
	{
		return JsonValue->TryGetString(OutParam);
	}
}
