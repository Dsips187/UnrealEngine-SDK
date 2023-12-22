#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Market/VyCollectionDto.h"

#include "VyGetCollection_Market.generated.h"


//RESPONSE [NFTCollectionDto]
USTRUCT(BlueprintType)
struct FVyGetCollectionResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyCollectionDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetCollectionCompleteBP, FVyGetCollectionResponse, Result);
