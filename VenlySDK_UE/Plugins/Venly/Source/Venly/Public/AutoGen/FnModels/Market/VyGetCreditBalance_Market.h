#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Market/VyUserCreditBalanceDto.h"
#include "AutoGen/Optionals/VyOptStringArray.h"

#include "VyGetCreditBalance_Market.generated.h"


/*
* Optional query to filter the GetCreditBalance endpoint results
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyQuery_GetCreditBalance : public FVyQuery
{
	GENERATED_BODY();
	/**Filter based on specific currencies*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptStringArray Currencies;
};

//RESPONSE [UserCreditBalanceDto]
USTRUCT(BlueprintType)
struct VENLY_API FVyGetCreditBalanceResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") TArray<FVyUserCreditBalanceDto> Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetCreditBalanceCompleteBP, FVyGetCreditBalanceResponse, Result);
