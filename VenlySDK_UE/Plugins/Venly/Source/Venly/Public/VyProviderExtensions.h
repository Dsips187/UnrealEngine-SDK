// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "Utils/VyLoggerDefines.h"
#include "Models/VyCoreModels.h"
#include "Models/VyProviderExtensionModels.h"

#include "VyProviderExtensions.generated.h"

class UVyCore;

/**
 * 
 */
UCLASS()
class VENLY_API UVyProviderExtensions : public UEngineSubsystem
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
	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly, Category = "Venly|Provider")
	static UVyProviderExtensions* Get() { return GEngine->GetEngineSubsystem<UVyProviderExtensions>(); }

	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category = "Venly|Provider")
	void BP_HasWallet(const FVyOnHasWalletCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	void CPP_HasWallet(const FVyOnHasWalletComplete& OnComplete) const;

	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category = "Venly|Provider")
	void BP_CreateWalletForUser(const FVyCreateWalletRequest& Params, const FVyOnCreateWalletForUserCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	void CPP_CreateWalletForUser(const FVyCreateWalletRequest& Params, const FVyOnCreateWalletForUserComplete& OnComplete) const;
	
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category = "Venly|Provider")
	void BP_GetWalletForUser(const FVyOnGetWalletForUserCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	void CPP_GetWalletForUser(const FVyOnGetWalletForUserComplete& OnComplete) const;

	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category = "Venly|Provider")
	void BP_HasMarketUser(const FVyOnHasMarketUserCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	void CPP_HasMarketUser(const FVyOnHasMarketUserComplete& OnComplete) const;

	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category = "Venly|Provider")
	void BP_CreateMarketUserForUser(const FVyCreateSubUserRequest& Params, const FVyOnCreateMarketUserForUserCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	void CPP_CreateMarketUserForUser(const FVyCreateSubUserRequest& Params, const FVyOnCreateMarketUserForUserComplete& OnComplete) const;

	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category = "Venly|Provider")
	void BP_GetMarketUserForUser(const FVyOnGetMarketUserForUserCompleteBP& OnComplete, const FVyOnSuccessBP& OnSuccess, const FVyOnFailBP& OnFail);
	void CPP_GetMarketUserForUser(const FVyOnGetMarketUserForUserComplete& OnComplete) const;
};
