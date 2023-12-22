#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/Optionals/VyOptOrderType.h"
#include "AutoGen/Optionals/VyOptChain.h"
#include "AutoGen/Optionals/VyOptDouble.h"
#include "AutoGen/Models/Wallet/VyExchangeRateResultDto.h"

#include "VyGetExchangeRate_Wallet.generated.h"


/*
* Optional query to filter the GetExchangeRate endpoint results
*/
USTRUCT(BlueprintType)
struct FVyQuery_GetExchangeRate : public FVyQuery
{
	GENERATED_BODY();
	/**Filter based on the source Chain*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptChain FromChain;
	/**Filter based on the destination Chain*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptChain ToChain;
	/**Filter based on the source Token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString FromToken;
	/**Filter based on the destination Token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString ToToken;
	/**Filter based on the amount*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptDouble Amount;
	/**Filter based on the order type*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptOrderType OrderType;
	
	virtual bool HasQueryLUT() const override { return true; }
	virtual const TMap<FName, FName>& GetQueryLUT() const override;
};

//RESPONSE [ExchangeRateResult]
USTRUCT(BlueprintType)
struct FVyGetExchangeRateResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyExchangeRateResultDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetExchangeRateCompleteBP, FVyGetExchangeRateResponse, Result);
