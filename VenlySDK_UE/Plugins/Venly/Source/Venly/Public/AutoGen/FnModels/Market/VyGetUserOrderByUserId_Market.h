#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Market/VyOrderDto.h"

#include "VyGetUserOrderByUserId_Market.generated.h"


//RESPONSE [OrderDto]
USTRUCT(BlueprintType)
struct FVyGetUserOrderByUserIdResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyOrderDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetUserOrderByUserIdCompleteBP, FVyGetUserOrderByUserIdResponse, Result);
