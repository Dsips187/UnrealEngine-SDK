#pragma once

#include "Models/VyCoreModels.h"

#include "VyGetTransactionFees_Wallet.generated.h"


//RESPONSE [#type]
USTRUCT(BlueprintType)
struct FVyGetTransactionFeesResponse : public FVyApiResponse, public FVyResponseTrait_VariantResult
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FString Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetTransactionFeesCompleteBP, FVyGetTransactionFeesResponse, Result);
