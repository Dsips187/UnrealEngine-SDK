#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Shared/VyMultiTokenDto.h"
#include "AutoGen/Optionals/VyOptStringArray.h"

#include "VyGetMultiTokenBalancesByAddress_Wallet.generated.h"


/*
* Optional query to filter the GetMultiTokenBalancesByAddress endpoint results
*/
USTRUCT(BlueprintType)
struct FVyQuery_GetMultiTokenBalancesByAddress : public FVyQuery
{
	GENERATED_BODY();
	/**Filter based on specific contract addresses*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptStringArray ContractAddresses;
};

//RESPONSE [NonFungibleAssetBalance]
USTRUCT(BlueprintType)
struct FVyGetMultiTokenBalancesByAddressResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") TArray<FVyMultiTokenDto> Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetMultiTokenBalancesByAddressCompleteBP, FVyGetMultiTokenBalancesByAddressResponse, Result);
