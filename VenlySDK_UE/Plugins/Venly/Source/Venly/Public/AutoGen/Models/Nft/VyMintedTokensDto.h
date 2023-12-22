#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/Models/Nft/VyMintedTokenDestinationDto.h"
#include "VyMintedTokensDto.generated.h"

/*
* Represents the response after minting tokens
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyMintedTokensDto : public FVyDTO
{
	GENERATED_BODY()
	/**The hash of the transaction that minted the tokens*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString TransactionHash;
	/**The metadata associated with the minted tokens*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Metadata;
	/**The destinations where the minted tokens were sent*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") TArray<FString> Destinations;
	/**The IDs of the minted tokens*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") TArray<int> TokenIds;
	/**The details of the minted tokens including their destinations*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") TArray<FVyMintedTokenDestinationDto> MintedTokens;
};


UCLASS(BlueprintType)
class VENLY_API UVyMintedTokensDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyMintedTokensDtoRef* ToObject(const FVyMintedTokensDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyMintedTokensDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyMintedTokensDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyMintedTokensDto Data{};
};