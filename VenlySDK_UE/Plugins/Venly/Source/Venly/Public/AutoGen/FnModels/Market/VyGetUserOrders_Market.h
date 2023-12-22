#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Market/VyOrderDto.h"

#include "VyGetUserOrders_Market.generated.h"


//RESPONSE [OrderDto]
USTRUCT(BlueprintType)
struct FVyGetUserOrdersResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") TArray<FVyOrderDto> Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetUserOrdersCompleteBP, FVyGetUserOrdersResponse, Result);
