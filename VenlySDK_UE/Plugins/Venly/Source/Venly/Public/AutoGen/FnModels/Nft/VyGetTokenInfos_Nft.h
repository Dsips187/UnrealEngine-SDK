#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Nft/VyTokenInfoDto.h"

#include "VyGetTokenInfos_Nft.generated.h"


//RESPONSE [TokenListItemView]
USTRUCT(BlueprintType)
struct FVyGetTokenInfosResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") TArray<FVyTokenInfoDto> Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetTokenInfosCompleteBP, FVyGetTokenInfosResponse, Result);
