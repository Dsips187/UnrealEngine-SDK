#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Shared/VyCryptoTokenDto.h"
#include "AutoGen/Optionals/VyOptBool.h"
#include "AutoGen/Optionals/VyOptStringArray.h"

#include "VyGetCryptoTokenBalancesByAddress_Wallet.generated.h"


/*
* Optional query to filter the GetCryptoTokenBalancesByAddress endpoint results
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyQuery_GetCryptoTokenBalancesByAddress : public FVyQuery
{
	GENERATED_BODY();
	/**Filter based on specific token addresses*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptStringArray TokenAddress;
	/**Filter to include all token balances*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptBool All;
};

//RESPONSE [TokenBalance]
USTRUCT(BlueprintType)
struct VENLY_API FVyGetCryptoTokenBalancesByAddressResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") TArray<FVyCryptoTokenDto> Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetCryptoTokenBalancesByAddressCompleteBP, FVyGetCryptoTokenBalancesByAddressResponse, Result);
