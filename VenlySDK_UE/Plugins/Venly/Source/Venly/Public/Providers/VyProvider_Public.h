// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VyProviderBase.h"
#include "VyProvider_Public.generated.h"

/**
 * 
 */
UCLASS()
class VENLY_API UVyProvider_Public : public UVyProviderBase
{
	GENERATED_BODY()

public:

	virtual void ProcessRequest(FVyRequestContext& Context, const FVyOnComplete_ResponseContext& OnComplete) override;
	virtual void OnRequestComplete(FVyRequestId RequestId) override;

private:
	TMap<FVyRequestId, TUnrealRequestPtr> InFlightRequests;
	void ExecuteRequest(FVyRequestId RequestId);
};
