#pragma once
#include "Models/VyCoreModels.h"

#include "VySortDto.generated.h"

/*
* A data transfer object for sorting options
*/
USTRUCT(BlueprintType)
struct VENLY_API FVySortDto : public FVyDTO
{
	GENERATED_BODY()
	/**Indicates if the sorting option is set to 'Empty'*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") bool Empty;
	/**Indicates if the sorting option is set to 'Unsorted'*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") bool Unsorted;
	/**Indicates if the sorting option is set to 'Sorted'*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") bool Sorted;
};


UCLASS(BlueprintType)
class VENLY_API UVySortDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVySortDtoRef* ToObject(const FVySortDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVySortDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVySortDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVySortDto Data{};
};