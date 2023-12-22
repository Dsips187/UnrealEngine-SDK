// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VyProviderBase.h"
#include "VyLoggerDefines.h"
#include "VyProvider_DevMode.generated.h"

/**
 * 
 */
UCLASS()
class VENLY_API UVyProvider_DevMode : public UVyProviderBase
{
	GENERATED_BODY()

public:

	virtual void ProcessRequest(FVyRequestContext& Context, const FVyOnComplete_ResponseContext& OnComplete) override;
	virtual void OnRequestComplete(FVyRequestId Id) override;

protected:
	virtual void OnInitialize() override;

private:
	TMap<FVyRequestId, TUnrealRequestPtr> InFlightRequests;
	TQueue<FVyRequestId> QueuedRequests;

	void QueueRequest(FVyRequestId RequestId);
	void CheckQueuedRequests();
	void ExecuteRequest(FVyRequestId RequestId);

	bool IsAuthTokenValid();
	FVyAuthToken AuthToken;

	FString ClientId;
	FString ClientSecret;
	bool AuthTokenRetrievalFailed{ false };
};