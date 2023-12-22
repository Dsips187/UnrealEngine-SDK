#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Nft/VyPageWalletBalanceDto.h"
#include "AutoGen/Optionals/VyOptInt.h"
#include "AutoGen/Optionals/VyOptBool.h"

#include "VyGetCompanyWalletByChain_Nft.generated.h"


/*
* Optional query to filter the GetCompanyWalletByChain endpoint results
*/
USTRUCT(BlueprintType)
struct FVyQuery_GetCompanyWalletByChain : public FVyQuery
{
	GENERATED_BODY();
	/**Filter based on the page number*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptInt PageNumber;
	/**Filter based on the page size*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptInt PageSize;
	/**Filter based on whether to include the balance*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptBool IncludeBalance;
};

//RESPONSE [PageWalletBalanceDto]
USTRUCT(BlueprintType)
struct FVyGetCompanyWalletByChainResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyPageWalletBalanceDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetCompanyWalletByChainCompleteBP, FVyGetCompanyWalletByChainResponse, Result);
