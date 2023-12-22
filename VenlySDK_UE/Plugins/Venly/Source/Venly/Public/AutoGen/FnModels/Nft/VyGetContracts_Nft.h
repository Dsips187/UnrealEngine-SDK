#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Shared/VyContractDto.h"

#include "VyGetContracts_Nft.generated.h"


//RESPONSE [TokenContractView]
USTRUCT(BlueprintType)
struct FVyGetContractsResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") TArray<FVyContractDto> Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetContractsCompleteBP, FVyGetContractsResponse, Result);
