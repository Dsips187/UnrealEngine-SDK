#pragma once
#include "Models/VyCoreModels.h"

#include "VyTypeValueDto.generated.h"

/*
* DTO for storing a type and its corresponding value
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyTypeValueDto : public FVyDTO
{
	GENERATED_BODY()
	/**The type of the value*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Type;
	/**The value associated with the type*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Value;
};


UCLASS(BlueprintType)
class VENLY_API UVyTypeValueDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyTypeValueDtoRef* ToObject(const FVyTypeValueDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyTypeValueDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyTypeValueDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyTypeValueDto Data{};
};