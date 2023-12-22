#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/VyEnums_generated.h"
#include "AutoGen/Models/Market/VyUserProfileDto.h"
#include "VyFulfillmentDto.generated.h"

/*
* Data transfer object for a fulfillment
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyFulfillmentDto : public FVyDTO
{
	GENERATED_BODY()
	/**The price per item*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double PricePerItem;
	/**The wallet address of the buyer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString BuyerWalletAddress;
	/**The type of fulfillment*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyFulfillmentType Type;
	/**The profile of the buyer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyUserProfileDto Buyer;
	/**The status of the fulfillment*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyFulfillmentState Status;
	/**The date of creation*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FDateTime CreationDate;
	/**The external ID of the buyer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ExternalBuyerId;
	/**The amount of items*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int Amount;
	/**The transaction association*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString TxAssociation;
	/**The transaction out of custody*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString TxOutOfCustody;
	/**The ID of the fulfillment*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Id;
	/**The ID of the offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString OfferId;
};


UCLASS(BlueprintType)
class VENLY_API UVyFulfillmentDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyFulfillmentDtoRef* ToObject(const FVyFulfillmentDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyFulfillmentDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyFulfillmentDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyFulfillmentDto Data{};
};