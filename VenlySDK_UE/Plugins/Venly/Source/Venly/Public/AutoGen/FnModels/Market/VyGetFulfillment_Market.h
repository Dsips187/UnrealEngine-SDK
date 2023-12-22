#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Market/VyFulfillmentDto.h"

#include "VyGetFulfillment_Market.generated.h"


//RESPONSE [findById_merged]
USTRUCT(BlueprintType)
struct FVyGetFulfillmentResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyFulfillmentDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetFulfillmentCompleteBP, FVyGetFulfillmentResponse, Result);
