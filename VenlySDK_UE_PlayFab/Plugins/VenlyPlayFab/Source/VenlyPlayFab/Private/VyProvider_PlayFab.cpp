// Fill out your copyright notice in the Description page of Project Settings.


#include "VyProvider_PlayFab.h"
#include "Utils/VyResponseUtils.h"
#include "Playfab.h"
#include "VyCore.h"
#include "Core/PlayFabCloudScriptAPI.h"
#include "VyPlayfabUtils.h"
#include "Misc/VyProjectSettings.h"

using namespace PlayFab;
using namespace CloudScriptModels;

void UVyProvider_PlayFab::OnInitialize()
{
	const auto projectSettings = GetDefault<UVyProjectSettings>();
	if(projectSettings == nullptr)
	{
		UE_LOG(LogVenlyPlayFab, Error, TEXT("[PlayFab Provider] Venly Project setting not found..."))
			return;
	}

	//Retrieve function name
	CloudScriptFunctionName = projectSettings->PlayFabCloudFunction;
	CurrentEnvironment = projectSettings->Environment;
}

void UVyProvider_PlayFab::ProcessRequest(FVyRequestContext& Context, const FVyOnComplete_ResponseContext& OnComplete)
{
	const auto cloudScriptApi = IPlayFabModuleInterface::Get().GetCloudScriptAPI();

	//Build Request
	FExecuteFunctionRequest executeRequest;
	executeRequest.FunctionName = CloudScriptFunctionName;

	TSharedRef<FJsonObject> outJsonObject = MakeShared<FJsonObject>();
	auto requestData = Context.ToRequestData(CurrentEnvironment);
	if (VyJsonUtils::UStructToJsonObject(FVyRequestData::StaticStruct(), &requestData, outJsonObject))
	{
		executeRequest.FunctionParameter = FJsonKeeper{ outJsonObject };
	}
	else
	{
		auto _ = OnComplete.ExecuteIfBound(VyResponseUtils::CreateResponseContext_Failure(TEXT("PLAYFAB_PROVIDER"), TEXT("Failed to serialize Cloud Function Argument (FVyRequestData)")));
		return;
	}


	const auto callSuccess = cloudScriptApi->ExecuteFunction(
		executeRequest,
		UPlayFabCloudScriptAPI::FExecuteFunctionDelegate::CreateLambda(
			[OnComplete](const FExecuteFunctionResult& result)
			{
				//OnSuccess
				const auto response = VyPlayFabUtils::CloudScriptResultToResponseContext(result);
				auto _ = OnComplete.ExecuteIfBound(response);
			}),
		FPlayFabErrorDelegate::CreateLambda(
			[OnComplete](const FPlayFabCppError& error)
			{
				//OnError
				const auto response = VyPlayFabUtils::PlayFabErrorToResponseContext(error);
				auto _ = OnComplete.ExecuteIfBound(response);
			}));

	if(!callSuccess)
	{
		auto _ = OnComplete.ExecuteIfBound(VyResponseUtils::CreateResponseContext_Failure(TEXT("PLAYFAB_PROVIDER"), TEXT("ExecuteCloudScript function call failed. See log for more information (LogPlayFabCpp)")));
	}
}