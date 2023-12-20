#pragma once
#include "Models/VyCoreModels.h"

#include "VyCollectionAveragePriceDto.generated.h"

/*
* A data transfer object representing the average price of a collection
*/
USTRUCT(BlueprintType)
struct FVyCollectionAveragePriceDto : public FVyDTO
{
	GENERATED_BODY()
	/**The average price of the collection in the last 7 days*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double Last7Days;
	/**The average price of the collection in the last 14 days*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double Last14Days;
	/**The average price of the collection in the last 30 days*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double Last30days;
	/**The average price of the collection in the last 90 days*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double Last90Days;
};


UCLASS(BlueprintType)
class UVyCollectionAveragePriceDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyCollectionAveragePriceDtoRef* ToObject(const FVyCollectionAveragePriceDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyCollectionAveragePriceDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyCollectionAveragePriceDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyCollectionAveragePriceDto Data{};
};