#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Market/VyOfferDto.h"

#include "VyGetOffer_Market.generated.h"


//RESPONSE [update_merged]
USTRUCT(BlueprintType)
struct VENLY_API FVyGetOfferResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyOfferDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetOfferCompleteBP, FVyGetOfferResponse, Result);
