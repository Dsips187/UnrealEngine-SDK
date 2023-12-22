#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Nft/VyTokenDto.h"
#include "AutoGen/Optionals/VyOptStringArray.h"

#include "VyGetTokens_Nft.generated.h"


/*
* Optional query to filter the GetTokens endpoint results
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyQuery_GetTokens : public FVyQuery
{
	GENERATED_BODY();
	/**Filter based on specific contract addresses*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptStringArray ContractAddresses;
};

//RESPONSE [TokenView]
USTRUCT(BlueprintType)
struct VENLY_API FVyGetTokensResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") TArray<FVyTokenDto> Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnGetTokensCompleteBP, FVyGetTokensResponse, Result);
