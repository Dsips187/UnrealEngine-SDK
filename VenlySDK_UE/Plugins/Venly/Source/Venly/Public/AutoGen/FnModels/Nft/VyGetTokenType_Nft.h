#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Nft/VyTokenTypeDto.h"

#include "VyGetTokenType_Nft.generated.h"


//RESPONSE [TokenTypeView]
USTRUCT(BlueprintType)
struct VENLY_API FVyGetTokenTypeResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyTokenTypeDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetTokenTypeCompleteBP, FVyGetTokenTypeResponse, Result);
