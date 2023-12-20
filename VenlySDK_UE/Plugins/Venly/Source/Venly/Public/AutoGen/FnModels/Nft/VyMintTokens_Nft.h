#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Nft/VyTokenDestinationDto.h"
#include "AutoGen/Models/Nft/VyMintedTokensDto.h"

#include "VyMintTokens_Nft.generated.h"


//REQUEST [mintTokens]
/*
* Request parameters to mint tokens
*/
USTRUCT(BlueprintType)
struct FVyMintTokensRequest : public FVyDTO
{
	GENERATED_BODY()
	/**An array of token destinations*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") TArray<FVyTokenDestinationDto> Destinations;
};


UCLASS(BlueprintType)
class UVyMintTokensRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyMintTokensRequestRef* ToObject(const FVyMintTokensRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyMintTokensRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyMintTokensRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyMintTokensRequest Data{};
};
//RESPONSE [MintTokenResponse]
USTRUCT(BlueprintType)
struct FVyMintTokensResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") TArray<FVyMintedTokensDto> Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnMintTokensCompleteBP, FVyMintTokensResponse, Result);
