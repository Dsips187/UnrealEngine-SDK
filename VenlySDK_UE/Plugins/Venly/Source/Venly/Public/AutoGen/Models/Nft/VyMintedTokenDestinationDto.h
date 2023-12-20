#pragma once
#include "Models/VyCoreModels.h"

#include "VyMintedTokenDestinationDto.generated.h"

/*
* A data transfer object representing the destination of a minted token
*/
USTRUCT(BlueprintType)
struct FVyMintedTokenDestinationDto : public FVyDTO
{
	GENERATED_BODY()
	/**The destination of the minted token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Destination;
	/**The ID of the minted token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int TokenId;
	/**The transaction hash of the minted token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString TxHash;
};


UCLASS(BlueprintType)
class UVyMintedTokenDestinationDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyMintedTokenDestinationDtoRef* ToObject(const FVyMintedTokenDestinationDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyMintedTokenDestinationDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyMintedTokenDestinationDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyMintedTokenDestinationDto Data{};
};