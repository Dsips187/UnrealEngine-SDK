#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/Models/Market/VyOfferPreparationDto.h"

#include "VyPrepareOfferTransaction_Market.generated.h"


/*
* Optional query to prepare an offer transaction
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyQuery_PrepareOfferTransaction : public FVyQuery
{
	GENERATED_BODY();
	/**The ID of the wallet to prepare the offer transaction for*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString WalletId;
};

//RESPONSE [OfferPreparationDto]
USTRUCT(BlueprintType)
struct VENLY_API FVyPrepareOfferTransactionResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyOfferPreparationDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnPrepareOfferTransactionCompleteBP, FVyPrepareOfferTransactionResponse, Result);
