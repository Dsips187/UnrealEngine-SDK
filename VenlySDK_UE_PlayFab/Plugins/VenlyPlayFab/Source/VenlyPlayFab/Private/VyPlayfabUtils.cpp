// Fill out your copyright notice in the Description page of Project Settings.


#include "VyPlayfabUtils.h"

#include "Models/VyCoreModels.h"
#include "Core/PlayFabCloudScriptAPI.h"
#include "Utils/VyResponseUtils.h"

DEFINE_LOG_CATEGORY(LogVenlyPlayFab);

namespace VyPlayFabUtils
{
	using namespace PlayFab;
	using namespace CloudScriptModels;

	FVyResponseContext PlayFabErrorToResponseContext(const FPlayFabCppError& error)
	{
		return VyResponseUtils::CreateResponseContext_Failure(FString::Printf(TEXT("PLAYFAB_ERROR::%s"), *error.ErrorName), error.ErrorMessage);
	}

	FVyResponseContext CloudScriptResultToResponseContext(const FExecuteFunctionResult& result)
	{
		if(result.Error != nullptr)
		{
			return VyResponseUtils::CreateResponseContext_Failure(result.Error->Error, result.Error->Message);
		}

		FVyServerResponse serverResponse{};
		const auto resultJson = result.FunctionResult.GetJsonValue()->AsObject();
		if(VyJsonUtils::JsonObjectToUStruct(resultJson.ToSharedRef(), &serverResponse))
		{
			return VyResponseUtils::CreateResponseContext_ServerResponse(serverResponse, TEXT("PLAYFAB_PROVIDER"));
		}

		return VyResponseUtils::CreateResponseContext_Failure(TEXT("PLAYFAB_PROVIDER"), TEXT("Failed to parse Azure Cloud Function sever response."));
	}
}
