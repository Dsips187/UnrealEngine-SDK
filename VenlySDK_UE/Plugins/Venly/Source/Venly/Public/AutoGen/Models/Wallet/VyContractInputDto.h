#pragma once
#include "Models/VyCoreModels.h"

#include "VyContractInputDto.generated.h"

/*
* Data transfer object for contract input
*/
USTRUCT(BlueprintType)
struct FVyContractInputDto : public FVyDTO
{
	GENERATED_BODY()
	/**The type of the contract input*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Type;
	/**The value of the contract input*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Value;
};


UCLASS(BlueprintType)
class UVyContractInputDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyContractInputDtoRef* ToObject(const FVyContractInputDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyContractInputDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyContractInputDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyContractInputDto Data{};
};