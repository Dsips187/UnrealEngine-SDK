#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Wallet/VyWalletMultiTokensDto.h"
#include "AutoGen/Optionals/VyOptStringArray.h"

#include "VyGetAllMultiTokenBalances_Wallet.generated.h"


/*
* Optional query to filter the GetAllMultiTokenBalances endpoint results
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyQuery_GetAllMultiTokenBalances : public FVyQuery
{
	GENERATED_BODY();
	/**Filter based on a specific Chain*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptStringArray Chain;
	
	virtual bool HasQueryLUT() const override { return true; }
	virtual const TMap<FName, FName>& GetQueryLUT() const override;
};

//RESPONSE [WalletItemsDto]
USTRUCT(BlueprintType)
struct VENLY_API FVyGetAllMultiTokenBalancesResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") TArray<FVyWalletMultiTokensDto> Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetAllMultiTokenBalancesCompleteBP, FVyGetAllMultiTokenBalancesResponse, Result);
