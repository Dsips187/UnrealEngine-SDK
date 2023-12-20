#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Nft/VyPageWalletBalanceDto.h"
#include "AutoGen/Optionals/VyOptInt.h"
#include "AutoGen/Optionals/VyOptBool.h"

#include "VyGetCompanyWallets_Nft.generated.h"


/*
* Optional query to filter the GetCompanyWallets endpoint results
*/
USTRUCT(BlueprintType)
struct FVyQuery_GetCompanyWallets : public FVyQuery
{
	GENERATED_BODY();
	/**Filter based on the page number*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptInt PageNumber;
	/**Filter based on the page size*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptInt PageSize;
	/**Filter based on whether to include the wallet balance*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptBool IncludeBalance;
};

//RESPONSE [PageWalletBalanceDto]
USTRUCT(BlueprintType)
struct FVyGetCompanyWalletsResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyPageWalletBalanceDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetCompanyWalletsCompleteBP, FVyGetCompanyWalletsResponse, Result);
