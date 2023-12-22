#pragma once
#include "Models/VyCoreModels.h"

#include "VyOfferFeeDto.generated.h"

/*
* An object that represents the fees associated with an offer
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyOfferFeeDto : public FVyDTO
{
	GENERATED_BODY()
	/**The fee charged by the market*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double MarketFee;
	/**The fee charged by the contract owner*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double ContractOwnerFee;
	/**The fee charged to the seller for the transaction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double SellerTxFee;
};


UCLASS(BlueprintType)
class VENLY_API UVyOfferFeeDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyOfferFeeDtoRef* ToObject(const FVyOfferFeeDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyOfferFeeDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyOfferFeeDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyOfferFeeDto Data{};
};