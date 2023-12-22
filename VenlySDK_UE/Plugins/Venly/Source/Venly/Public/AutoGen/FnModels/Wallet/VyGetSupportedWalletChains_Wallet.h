#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/VyEnums_generated.h"

#include "VyGetSupportedWalletChains_Wallet.generated.h"


//RESPONSE [#type]
USTRUCT(BlueprintType)
struct VENLY_API FVyGetSupportedWalletChainsResponse : public FVyApiResponse, public FVyResponseTrait_VariantResult
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") TArray<EVyChain> Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetSupportedWalletChainsCompleteBP, FVyGetSupportedWalletChainsResponse, Result);
