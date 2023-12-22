#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Shared/VyContractDto.h"

#include "VyGetContract_Nft.generated.h"


//RESPONSE [TokenContractView]
USTRUCT(BlueprintType)
struct FVyGetContractResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyContractDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetContractCompleteBP, FVyGetContractResponse, Result);
