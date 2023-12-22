#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Shared/VyMultiTokenDto.h"
#include "AutoGen/Optionals/VyOptStringArray.h"

#include "VyGetMultiTokenBalances_Wallet.generated.h"


/*
* Optional query to filter the GetMultiTokenBalances endpoint results
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyQuery_GetMultiTokenBalances : public FVyQuery
{
	GENERATED_BODY();
	/**Filter based on specific contract addresses*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptStringArray ContractAddresses;
};

//RESPONSE [NonFungibleAssetBalance]
USTRUCT(BlueprintType)
struct VENLY_API FVyGetMultiTokenBalancesResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") TArray<FVyMultiTokenDto> Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetMultiTokenBalancesCompleteBP, FVyGetMultiTokenBalancesResponse, Result);
