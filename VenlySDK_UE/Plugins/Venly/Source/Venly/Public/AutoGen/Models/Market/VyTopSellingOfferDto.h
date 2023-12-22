#pragma once
#include "Models/VyCoreModels.h"

#include "VyTopSellingOfferDto.generated.h"

/*
* Top selling offer data transfer object
*/
USTRUCT(BlueprintType)
struct FVyTopSellingOfferDto : public FVyDTO
{
	GENERATED_BODY()
	/**The price of the offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double Price;
	/**The identifier of the offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Id;
};


UCLASS(BlueprintType)
class UVyTopSellingOfferDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyTopSellingOfferDtoRef* ToObject(const FVyTopSellingOfferDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyTopSellingOfferDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyTopSellingOfferDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyTopSellingOfferDto Data{};
};