// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Providers/VyProviderBase.h"
#include "VyProvider_PlayFab.generated.h"

class UPlayFabAuthenticationContext;
/**
 * 
 */
UCLASS()
class VENLYPLAYFAB_API UVyProvider_PlayFab : public UVyProviderBase
{
	GENERATED_BODY()

public:
	virtual void ProcessRequest(FVyRequestContext& Context, const FVyOnComplete_ResponseContext& OnComplete) override;

protected:
	virtual void OnInitialize() override;

private:

	UPROPERTY()
	FString CloudScriptFunctionName{};

	UPROPERTY()
	EVyEnvironment CurrentEnvironment{};
};
