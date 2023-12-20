// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "Utils/VyLoggerDefines.h"

#include "GenericPlatform/GenericPlatformHttp.h"
#include "Models/VyCoreModels.h"
#include "Providers/VyProviderBase.h"
#include "Utils/VyJsonUtils.h"
#include "Utils/VyResponseUtils.h"

#include "VyCore.generated.h"

enum class EVyEnvironment : uint8;
enum class EVyProviderType : uint8;

/**
 * 
 */
UCLASS()
class VENLY_API UVyCore : public UEngineSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly)
	static UVyCore* Get() { return  GEngine->GetEngineSubsystem<UVyCore>(); }

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	void BeginPlay();
	void EndPlay();

	template<typename TResponseData, typename TResult, typename TCompleteCallback>
	void ExecuteRequest(FVyRequestContext& Context, TCompleteCallback OnComplete)
	{
		RegisterRequestContext(Context);

		FVyOnComplete_ResponseContext OnCompleteRaw = {};
		OnCompleteRaw.BindLambda([this, Context, OnComplete](FVyResponseContext ResponseContext)
			{
				UE_LOG(LogVenlyBackend, Log, TEXT("Request RESPONSE (ID=%lld | CODE=%i)"), Context.Id, ResponseContext.Code)
				UE_LOG(LogVenlyBackend, Verbose, TEXT("Request RESPONSE - Content=%s"), *ResponseContext.Content)

				TResponseData OutputResponse;
				VyResponseUtils::ParseResponse<TResponseData, TResult>(Context, ResponseContext, OutputResponse);
				const auto _complete = OnComplete.ExecuteIfBound(OutputResponse);

				SignalRequestComplete(Context.Id);
			});

		ProcessRequest(Context, OnCompleteRaw);
	}

	template<typename TResponseData, typename TResult, typename TCompleteCallback, typename TSuccessCallback, typename TFailCallback>
	void ExecuteRequest_BP(FVyRequestContext& Context, TCompleteCallback OnComplete, TSuccessCallback OnSuccess, TFailCallback OnFail)
	{
		RegisterRequestContext(Context);

		FVyOnComplete_ResponseContext OnCompleteRaw = {};
		OnCompleteRaw.BindLambda([this, Context, OnComplete, OnSuccess, OnFail](FVyResponseContext ResponseContext)
			{
				UE_LOG(LogVenlyBackend, Log, TEXT("Request RESPONSE_BP (ID=%lld | CODE=%i)"), Context.Id, ResponseContext.Code)
				UE_LOG(LogVenlyBackend, Verbose, TEXT("Request RESPONSE_BP - Content=%s"), *ResponseContext.Content)

				TResponseData OutputResponse;
				VyResponseUtils::ParseResponse<TResponseData, TResult>(Context, ResponseContext, OutputResponse);
				const auto _complete = OnComplete.ExecuteIfBound(OutputResponse);

				if (OutputResponse.Success) const auto _success = OnSuccess.ExecuteIfBound();
				else const auto _fail = OnFail.ExecuteIfBound();

				SignalRequestComplete(Context.Id);
			});

		ProcessRequest(Context, OnCompleteRaw);
	}

	void SetRequestState(FVyRequestId RequestId, EVyRequestState newState);
	const FVyRequestContext& GetRequestContext(FVyRequestId RequestId);
	FVyRequestContext& GetRequestContextRef(FVyRequestId RequestId);



	UFUNCTION(BlueprintCallable, Category="Venly|Core")
	static EVyEnvironment GetEnvironment() { return CurrentEnvironment; } //Todo: fix initialization of CurrentEnvironment
	//static EVyEnvironment GetEnvironment() { return CurrentEnvironment; }
	UFUNCTION(BlueprintCallable, Category = "Venly|Core")
	static EVyProviderType GetProviderType() { return CurrentProviderType; }

	UVyProviderBase* GetProvider() const { return Provider; }

private:
	long volatile* InFlightRequestIdCounter;

	void RegisterRequestContext(FVyRequestContext& Context);
	void SignalRequestComplete(FVyRequestId RequestId);
	void ProcessRequest(FVyRequestContext& Context, const FVyOnComplete_ResponseContext& OnComplete) const;
	bool CreateProvider(EVyProviderType ProviderType);

	TMap<FVyRequestId, FVyRequestContext> InFlightRequestContexts;
	TQueue<FVyRequestId> QueuedRequests;

	UPROPERTY()
	UVyProviderBase* Provider;

	UPROPERTY()
	UVyProviderBase* PublicProvider;

	UPROPERTY()
	bool HasProvider{ false };

	static EVyEnvironment CurrentEnvironment;
	static EVyProviderType CurrentProviderType;
};
