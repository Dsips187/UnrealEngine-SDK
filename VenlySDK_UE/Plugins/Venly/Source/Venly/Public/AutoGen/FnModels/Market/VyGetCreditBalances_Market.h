#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Market/VyUserCreditBalanceDto.h"
#include "AutoGen/Optionals/VyOptStringArray.h"

#include "VyGetCreditBalances_Market.generated.h"


/*
* Optional query to filter the GetCreditBalances endpoint results
*/
USTRUCT(BlueprintType)
struct FVyQuery_GetCreditBalances : public FVyQuery
{
	GENERATED_BODY();
	/**Filter based on specific currencies*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptStringArray Currencies;
};

//RESPONSE [UserCreditBalanceDto]
USTRUCT(BlueprintType)
struct FVyGetCreditBalancesResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") TArray<FVyUserCreditBalanceDto> Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetCreditBalancesCompleteBP, FVyGetCreditBalancesResponse, Result);
