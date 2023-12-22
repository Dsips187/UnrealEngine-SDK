#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Wallet/VyTradingPairDto.h"

#include "VyGetTradingPairs_Wallet.generated.h"


//RESPONSE [TradingPair]
USTRUCT(BlueprintType)
struct VENLY_API FVyGetTradingPairsResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") TArray<FVyTradingPairDto> Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetTradingPairsCompleteBP, FVyGetTradingPairsResponse, Result);
