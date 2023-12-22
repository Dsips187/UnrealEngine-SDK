#pragma once

#include "Models/VyCoreModels.h"

#include "VyIsValidWalletAddress_Wallet.generated.h"


//RESPONSE [None]
USTRUCT(BlueprintType)
struct VENLY_API FVyIsValidWalletAddressResponse : public FVyApiResponse, public FVyResponseTrait_VariantResult
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") bool Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnIsValidWalletAddressCompleteBP, FVyIsValidWalletAddressResponse, Result);
