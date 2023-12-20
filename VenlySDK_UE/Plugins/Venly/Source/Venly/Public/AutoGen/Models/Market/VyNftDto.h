#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/VyEnums_generated.h"
#include "VyNftDto.generated.h"

/*
* A data transfer object representing an NFT
*/
USTRUCT(BlueprintType)
struct FVyNftDto : public FVyDTO
{
	GENERATED_BODY()
	/**The unique identifier of the NFT*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString TokenId;
	/**The address of the NFT*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Address;
	/**The blockchain on which the NFT exists*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyChain Chain;
};


UCLASS(BlueprintType)
class UVyNftDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyNftDtoRef* ToObject(const FVyNftDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyNftDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyNftDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyNftDto Data{};
};