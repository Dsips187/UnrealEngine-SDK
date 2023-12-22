// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "VyProvider_Beamable.h"
#include "BeamBackend/BeamErrorResponse.h"
#include "VyBeamableProxy.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogVenlyBeamable, Log, All);

USTRUCT(BlueprintType)
struct FVyBeamableMicroserviceResponse
{
	GENERATED_BODY()

	FVyBeamableMicroserviceResponse() {}
	FVyBeamableMicroserviceResponse(const FString& _Result) { Success = true; Result = _Result; }
	FVyBeamableMicroserviceResponse(const FBeamErrorResponse& _Error) { Success = false; Error = _Error; }

	UPROPERTY(BlueprintReadWrite, Category = "Venly|Beamable") bool Success{ false };
	UPROPERTY(BlueprintReadWrite, Category = "Venly|Beamable") FString Result{};
	UPROPERTY(BlueprintReadWrite, Category = "Venly|Beamable") FBeamErrorResponse Error{};
};

DECLARE_DELEGATE_OneParam(FVyOnExecuteProviderRequestComplete, FVyBeamableMicroserviceResponse)
DECLARE_DELEGATE_TwoParams(FVyOnExecuteProviderRequest, FString, FVyOnExecuteProviderRequestComplete)

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FVyOnExecuteProviderRequestBP, FString, Request, int64, RequestId);

/**
 * 
 */
UCLASS()
class VENLYBEAMABLE_API UVyBeamableProxy : public UEngineSubsystem
{
	GENERATED_BODY()

public:

	//CPP Land
	static UVyBeamableProxy* Get()
	{
		return GEngine->GetEngineSubsystem<UVyBeamableProxy>();
	}

	FVyOnExecuteProviderRequest OnExecuteRequest{};

	//BP Land
	UFUNCTION(BlueprintCallable)
	void SignalRequestSuccess(int64 RequestId, const FString& ResponseData);

	UFUNCTION(BlueprintCallable)
	void SignalRequestError(int64 RequestId, const FBeamErrorResponse& ErrorData);

	UFUNCTION(BlueprintCallable)
	void BindExecuteRequest(const FVyOnExecuteProviderRequestBP& handler);

private:

	TMap<int64, FVyOnComplete_ResponseContext> TrackedRequests;

	UPROPERTY()
	FVyOnExecuteProviderRequestBP OnExecuteRequestHandlerBP{};

	void ExecuteRequest(FVyRequestContext& Context, EVyEnvironment Env, const FVyOnComplete_ResponseContext& OnComplete);
	void SignalRequestComplete(int64 RequestId, const FVyBeamableMicroserviceResponse& ExecuteReponse);

	friend class UVyProvider_Beamable;
};