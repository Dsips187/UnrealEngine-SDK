// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Providers/VyProviderBase.h"
#include "VyProvider_Beamable.generated.h"

class UVyBeamableProxy;

/**
 * 
 */
UCLASS()
class VENLYBEAMABLE_API UVyProvider_Beamable : public UVyProviderBase
{
	GENERATED_BODY()
	
public:
	virtual void ProcessRequest(FVyRequestContext& Context, const FVyOnComplete_ResponseContext& OnComplete) override;

protected:
	virtual void OnInitialize() override;

private:

	UPROPERTY()
	EVyEnvironment CurrentEnvironment{};
};
