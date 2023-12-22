#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/VyEnums_generated.h"

#include "VyGetSupportedNftChains_Nft.generated.h"


//RESPONSE [None]
USTRUCT(BlueprintType)
struct VENLY_API FVyGetSupportedNftChainsResponse : public FVyApiResponse, public FVyResponseTrait_VariantResult
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") TArray<EVyChain> Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetSupportedNftChainsCompleteBP, FVyGetSupportedNftChainsResponse, Result);
