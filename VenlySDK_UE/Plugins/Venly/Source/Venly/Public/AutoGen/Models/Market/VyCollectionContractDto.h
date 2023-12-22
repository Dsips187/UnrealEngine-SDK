#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/VyEnums_generated.h"
#include "VyCollectionContractDto.generated.h"

/*
* A data transfer object representing a collection contract
*/
USTRUCT(BlueprintType)
struct FVyCollectionContractDto : public FVyDTO
{
	GENERATED_BODY()
	/**The address of the collection contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Address;
	/**The blockchain on which the collection contract exists*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyChain Chain;
};


UCLASS(BlueprintType)
class UVyCollectionContractDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyCollectionContractDtoRef* ToObject(const FVyCollectionContractDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyCollectionContractDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyCollectionContractDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyCollectionContractDto Data{};
};