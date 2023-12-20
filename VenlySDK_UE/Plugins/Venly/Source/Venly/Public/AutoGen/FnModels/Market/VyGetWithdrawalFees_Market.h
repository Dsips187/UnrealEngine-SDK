#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Market/VyWithdrawalFeeDto.h"

#include "VyGetWithdrawalFees_Market.generated.h"


//RESPONSE [WithdrawalFeeDto]
USTRUCT(BlueprintType)
struct FVyGetWithdrawalFeesResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyWithdrawalFeeDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetWithdrawalFeesCompleteBP, FVyGetWithdrawalFeesResponse, Result);
