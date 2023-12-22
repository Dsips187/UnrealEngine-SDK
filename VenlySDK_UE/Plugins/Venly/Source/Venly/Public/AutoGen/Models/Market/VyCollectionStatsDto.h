#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/Models/Market/VyCollectionAveragePriceDto.h"
#include "AutoGen/Models/Market/VyTopSellingOfferDto.h"
#include "AutoGen/Models/Market/VyCollectionVolumeDto.h"
#include "VyCollectionStatsDto.generated.h"

/*
* Collection statistics
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyCollectionStatsDto : public FVyDTO
{
	GENERATED_BODY()
	/**Top selling offer in the collection*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyTopSellingOfferDto TopSellingOffer;
	/**Latest sale price in the collection*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double LatestSalePrice;
	/**Total sale volume in the collection*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double TotalSaleVolume;
	/**Average sale price in the collection*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyCollectionAveragePriceDto AverageSalePrice;
	/**Floor price in the collection*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double FloorPrice;
	/**Sale volume in the collection*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyCollectionVolumeDto SaleVolume;
};


UCLASS(BlueprintType)
class VENLY_API UVyCollectionStatsDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyCollectionStatsDtoRef* ToObject(const FVyCollectionStatsDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyCollectionStatsDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyCollectionStatsDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyCollectionStatsDto Data{};
};