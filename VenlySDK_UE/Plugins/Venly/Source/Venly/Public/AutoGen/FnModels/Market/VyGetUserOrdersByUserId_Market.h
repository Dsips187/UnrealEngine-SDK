#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Market/VyOrderDto.h"

#include "VyGetUserOrdersByUserId_Market.generated.h"


//RESPONSE [OrderDto]
USTRUCT(BlueprintType)
struct FVyGetUserOrdersByUserIdResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") TArray<FVyOrderDto> Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetUserOrdersByUserIdCompleteBP, FVyGetUserOrdersByUserIdResponse, Result);
