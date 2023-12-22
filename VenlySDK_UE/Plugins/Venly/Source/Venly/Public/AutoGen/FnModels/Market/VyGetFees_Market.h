#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Market/VyOfferFeeDto.h"

#include "VyGetFees_Market.generated.h"


//RESPONSE [OfferFeeDto]
USTRUCT(BlueprintType)
struct FVyGetFeesResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyOfferFeeDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetFeesCompleteBP, FVyGetFeesResponse, Result);
