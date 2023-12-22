#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Nft/VyTokenTypeMetadataDto.h"

#include "VyGetTokenTypeMetadata_Nft.generated.h"


//RESPONSE [TokenTypeMetadata]
USTRUCT(BlueprintType)
struct FVyGetTokenTypeMetadataResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyTokenTypeMetadataDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetTokenTypeMetadataCompleteBP, FVyGetTokenTypeMetadataResponse, Result);
