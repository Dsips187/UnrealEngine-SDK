// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"

#include "Utils/VyLoggerDefines.h"
#include "Models/VyCoreModels.h"

#include "VyAuthAPI.generated.h"

class UVyCore;

USTRUCT(BlueprintType)
struct FVyGetAuthTokenResponse : public FVyApiResponse
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyAuthToken Result;
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetAuthTokenCompleteBP, FVyGetAuthTokenResponse, Result);
DECLARE_DELEGATE_OneParam(FVyOnGetAuthTokenComplete, FVyGetAuthTokenResponse);

/**
 * 
 */
UCLASS(NotBlueprintType)
class VENLY_API UVyAuthAPI : public UEngineSubsystem
{
	GENERATED_BODY()

	/**
	 * @brief Initialize this subsystem
	 */
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UPROPERTY()
	UVyCore* VenlyCore;

public:
	/** Used by a helper blueprint node so that you can easily chain requests in BP-land. */
	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category = "Venly|Auth")
	static UVyAuthAPI* Get() { return GEngine->GetEngineSubsystem<UVyAuthAPI>(); }

	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category = "Venly|Auth")
	void BP_GetAuthToken(const FString& ClientId, const FString& ClientSecret, const FVyOnGetAuthTokenCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);

	void CPP_GetAuthToken(const FString& ClientId, const FString& ClientSecret, const FVyOnGetAuthTokenComplete& OnComplete) const;
	void CPP_GetAuthToken(const FString& ClientId, const FString& ClientSecret, EVyEnvironment Environment, const FVyOnGetAuthTokenComplete& OnComplete) const;
};
