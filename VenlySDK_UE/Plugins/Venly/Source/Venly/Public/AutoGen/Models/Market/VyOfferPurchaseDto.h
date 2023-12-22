#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/VyEnums_generated.h"
#include "AutoGen/Models/Market/VyUserProfileDto.h"
#include "VyOfferPurchaseDto.generated.h"

/*
* Purchase information for an offer
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyOfferPurchaseDto : public FVyDTO
{
	GENERATED_BODY()
	/**The price per item of the purchase*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double PricePerItem;
	/**The profile of the buyer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyUserProfileDto Buyer;
	/**The external ID of the buyer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ExternalBuyerId;
	/**The wallet address of the buyer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString BuyerWalletAddress;
	/**The ID of the purchase*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Id;
	/**The fulfillment type of the purchase*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyFulfillmentType Type;
	/**The ID of the offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString OfferId;
	/**The transaction out of custody*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString TxOutOfCustody;
	/**The amount of items purchased*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int Amount;
	/**The fulfillment state of the purchase*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyFulfillmentState Status;
	/**The creation date of the purchase*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString CreationDate;
	/**The transaction association*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString TxAssociation;
};


UCLASS(BlueprintType)
class VENLY_API UVyOfferPurchaseDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyOfferPurchaseDtoRef* ToObject(const FVyOfferPurchaseDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyOfferPurchaseDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyOfferPurchaseDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyOfferPurchaseDto Data{};
};