#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Nft/VyTokenDto.h"

#include "VyGetToken_Nft.generated.h"


//RESPONSE [TokenView]
USTRUCT(BlueprintType)
struct FVyGetTokenResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyTokenDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetTokenCompleteBP, FVyGetTokenResponse, Result);
