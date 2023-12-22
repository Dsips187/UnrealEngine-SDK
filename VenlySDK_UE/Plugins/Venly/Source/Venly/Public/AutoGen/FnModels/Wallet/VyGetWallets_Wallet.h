#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Optionals/VyOptInt.h"
#include "AutoGen/Optionals/VyOptChain.h"
#include "AutoGen/Optionals/VyOptBool.h"
#include "AutoGen/Optionals/VyOptSortOrder.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/Models/Wallet/VyWalletDto.h"
#include "AutoGen/Optionals/VyOptWalletType.h"

#include "VyGetWallets_Wallet.generated.h"


/*
* Optional query to filter the GetWallets endpoint results
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyQuery_GetWallets : public FVyQuery
{
	GENERATED_BODY();
	/**Filter based on a specific Chain*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptChain Chain;
	/**Filter based on a specific ClientId*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString ClientId;
	/**Filter based a specific wallet address*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString Address;
	/**Filter based on the archived state*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptBool Archived;
	/**Filter based on the linkable state*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptBool Linkable;
	/**Filter based on a specific WalletType*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptWalletType WalletType;
	/**Include the wallet balance in the results*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptBool IncludeBalance;
	/**Specify the page number for pagination*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptInt Page;
	/**Specify the number of results per page*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptInt Size;
	/**Specify the field to sort the results on*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString SortOn;
	/**Specify the sort order for the results*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptSortOrder SortOrder;
	/**Filter based on a specific Identifier*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString Identifier;
	
	virtual bool HasQueryLUT() const override { return true; }
	virtual const TMap<FName, FName>& GetQueryLUT() const override;
};

//RESPONSE [ViewWalletResult]
USTRUCT(BlueprintType)
struct VENLY_API FVyGetWalletsResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") TArray<FVyWalletDto> Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetWalletsCompleteBP, FVyGetWalletsResponse, Result);
