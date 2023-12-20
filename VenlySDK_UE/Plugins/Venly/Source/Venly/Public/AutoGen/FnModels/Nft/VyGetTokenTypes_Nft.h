#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Nft/VyTokenTypeDto.h"

#include "VyGetTokenTypes_Nft.generated.h"


//RESPONSE [TokenTypeView]
USTRUCT(BlueprintType)
struct FVyGetTokenTypesResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") TArray<FVyTokenTypeDto> Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetTokenTypesCompleteBP, FVyGetTokenTypesResponse, Result);
