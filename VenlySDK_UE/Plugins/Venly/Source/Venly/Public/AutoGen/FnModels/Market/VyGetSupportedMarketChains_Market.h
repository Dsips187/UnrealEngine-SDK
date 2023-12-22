#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/VyEnums_generated.h"

#include "VyGetSupportedMarketChains_Market.generated.h"


//RESPONSE [None]
USTRUCT(BlueprintType)
struct FVyGetSupportedMarketChainsResponse : public FVyApiResponse, public FVyResponseTrait_VariantResult
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") TArray<EVyChain> Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetSupportedMarketChainsCompleteBP, FVyGetSupportedMarketChainsResponse, Result);
