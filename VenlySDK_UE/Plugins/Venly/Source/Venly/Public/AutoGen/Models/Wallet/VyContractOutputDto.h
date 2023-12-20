#pragma once
#include "Models/VyCoreModels.h"

#include "VyContractOutputDto.generated.h"

/*
* Contract output or wallet information
*/
USTRUCT(BlueprintType)
struct FVyContractOutputDto : public FVyDTO
{
	GENERATED_BODY()
	/**The type of the contract output or wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Type;
};


UCLASS(BlueprintType)
class UVyContractOutputDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyContractOutputDtoRef* ToObject(const FVyContractOutputDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyContractOutputDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyContractOutputDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyContractOutputDto Data{};
};