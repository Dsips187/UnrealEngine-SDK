#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Optionals/VyOptBool.h"
#include "AutoGen/Models/Wallet/VyWalletDto.h"

#include "VyGetWallet_Wallet.generated.h"


/*
* Optional query to filter the GetWallet endpoint results
*/
USTRUCT(BlueprintType)
struct FVyQuery_GetWallet : public FVyQuery
{
	GENERATED_BODY();
	/**Include the wallet balance in the results*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptBool IncludeBalance;
};

//RESPONSE [ViewWalletResult]
USTRUCT(BlueprintType)
struct FVyGetWalletResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyWalletDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetWalletCompleteBP, FVyGetWalletResponse, Result);
