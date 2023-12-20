#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Nft/VyContractMetadataDto.h"

#include "VyGetContractMetadata_Nft.generated.h"


//RESPONSE [TokenContractMetadataView]
USTRUCT(BlueprintType)
struct FVyGetContractMetadataResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyContractMetadataDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetContractMetadataCompleteBP, FVyGetContractMetadataResponse, Result);
