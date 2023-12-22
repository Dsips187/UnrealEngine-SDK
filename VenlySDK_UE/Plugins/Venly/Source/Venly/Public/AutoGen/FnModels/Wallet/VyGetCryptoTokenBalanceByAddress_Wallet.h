#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Shared/VyCryptoTokenDto.h"

#include "VyGetCryptoTokenBalanceByAddress_Wallet.generated.h"


//RESPONSE [TokenBalance]
USTRUCT(BlueprintType)
struct FVyGetCryptoTokenBalanceByAddressResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyCryptoTokenDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetCryptoTokenBalanceByAddressCompleteBP, FVyGetCryptoTokenBalanceByAddressResponse, Result);
