#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Wallet/VyBlockchainInfoDto.h"

#include "VyGetBlockchainInfo_Wallet.generated.h"


//RESPONSE [BlockchainInfoDto]
USTRUCT(BlueprintType)
struct FVyGetBlockchainInfoResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyBlockchainInfoDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetBlockchainInfoCompleteBP, FVyGetBlockchainInfoResponse, Result);
