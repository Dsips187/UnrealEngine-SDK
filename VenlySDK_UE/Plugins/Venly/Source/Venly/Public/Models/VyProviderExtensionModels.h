// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Models/VyCoreModels.h"

#include "AutoGen/FnModels/Wallet/VyCreateWallet_Wallet.h"
#include "AutoGen/FnModels/Wallet/VyGetWallet_Wallet.h"
#include "AutoGen/FnModels/Market/VyCreateSubUser_Market.h"
#include "AutoGen/FnModels/Market/VyGetUserProfile_Market.h"

#include "VyProviderExtensionModels.generated.h"

/**
* EXTENSION: HasWallet
*/
USTRUCT(BlueprintType)
struct FVyHasWalletResponse : public FVyApiResponse, public FVyResponseTrait_VariantResult
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadOnly, Category = "Venly") bool Result;
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnHasWalletCompleteBP, FVyHasWalletResponse, Result);
DECLARE_DELEGATE_OneParam(FVyOnHasWalletComplete, FVyHasWalletResponse);

/**
* EXTENSION: CreateWalletForUser
*/
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnCreateWalletForUserCompleteBP, FVyCreateWalletResponse, Result);
DECLARE_DELEGATE_OneParam(FVyOnCreateWalletForUserComplete, FVyCreateWalletResponse);

/**
* EXTENSION: GetWalletForUser
*/
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetWalletForUserCompleteBP, FVyGetWalletResponse, Result);
DECLARE_DELEGATE_OneParam(FVyOnGetWalletForUserComplete, FVyGetWalletResponse);

/**
* EXTENSION: HasMarketUser
*/
USTRUCT(BlueprintType)
struct FVyHasMarketUserResponse : public FVyApiResponse, public FVyResponseTrait_VariantResult
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadOnly, Category = "Venly") bool Result;
};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnHasMarketUserCompleteBP, FVyHasMarketUserResponse, Result);
DECLARE_DELEGATE_OneParam(FVyOnHasMarketUserComplete, FVyHasMarketUserResponse);

/**
* EXTENSION: CreateMarketUserForUser
*/
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnCreateMarketUserForUserCompleteBP, FVyCreateSubUserResponse, Result);
DECLARE_DELEGATE_OneParam(FVyOnCreateMarketUserForUserComplete, FVyCreateSubUserResponse);

/**
* EXTENSION: GetMarketUserForUser
*/
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetMarketUserForUserCompleteBP, FVyGetUserProfileResponse, Result);
DECLARE_DELEGATE_OneParam(FVyOnGetMarketUserForUserComplete, FVyGetUserProfileResponse);
