#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Market/VyUserOrderWithdrawalMaxDto.h"

#include "VyGetUserOrderWithdrawalMax_Market.generated.h"


//RESPONSE [UserOrderMaxWithdrawalDto]
USTRUCT(BlueprintType)
struct VENLY_API FVyGetUserOrderWithdrawalMaxResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyUserOrderWithdrawalMaxDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetUserOrderWithdrawalMaxCompleteBP, FVyGetUserOrderWithdrawalMaxResponse, Result);
