#pragma once
#include "Models/VyCoreModels.h"

#include "VyReadContractResultDto.generated.h"

/*
* Result of reading a contract
*/
USTRUCT(BlueprintType)
struct FVyReadContractResultDto : public FVyDTO
{
	GENERATED_BODY()
	/**The type of the result*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Type;
	/**The value of the result*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Value;
};


UCLASS(BlueprintType)
class UVyReadContractResultDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyReadContractResultDtoRef* ToObject(const FVyReadContractResultDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyReadContractResultDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyReadContractResultDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyReadContractResultDto Data{};
};