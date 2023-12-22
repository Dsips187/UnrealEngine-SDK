#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/VyEnums_generated.h"
#include "AutoGen/Models/Market/VyUserProfileDto.h"
#include "VyFulfillmentAssociationDto.generated.h"

/*
* Data transfer object for fulfillment association
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyFulfillmentAssociationDto : public FVyDTO
{
	GENERATED_BODY()
	/**Price per item*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double PricePerItem;
	/**Buyer's wallet address*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString BuyerWalletAddress;
	/**Fulfillment type*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyFulfillmentType Type;
	/**Buyer's profile*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyUserProfileDto Buyer;
	/**Fulfillment status*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyFulfillmentState Status;
	/**Creation date*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString CreationDate;
	/**External buyer ID*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ExternalBuyerId;
	/**Amount*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int Amount;
	/**Transaction association*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString TxAssociation;
	/**Transaction out of custody*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString TxOutOfCustody;
	/**ID*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Id;
	/**Offer ID*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString OfferId;
};


UCLASS(BlueprintType)
class VENLY_API UVyFulfillmentAssociationDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyFulfillmentAssociationDtoRef* ToObject(const FVyFulfillmentAssociationDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyFulfillmentAssociationDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyFulfillmentAssociationDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyFulfillmentAssociationDto Data{};
};