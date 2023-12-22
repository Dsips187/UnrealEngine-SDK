#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/Models/Market/VyNftDetailsDto.h"
#include "AutoGen/VyEnums_generated.h"
#include "AutoGen/Models/Market/VyUserProfileDto.h"
#include "VyHotOfferDto.generated.h"

/*
* Data structure representing a hot offer
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyHotOfferDto : public FVyDTO
{
	GENERATED_BODY()
	/**The unique identifier of the hot offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Id;
	/**Details of the NFT associated with the hot offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyNftDetailsDto Nft;
	/**The unique identifier of the seller*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString SellerId;
	/**The nickname of the seller*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString SellerNickname;
	/**The external identifier of the seller*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ExternalSellerId;
	/**The address of the seller*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString SellerAddress;
	/**The start date of the hot offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString StartDate;
	/**The end date of the hot offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString EndDate;
	/**The type of the hot offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyOfferType Type;
	/**The status of the hot offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyOfferState Status;
	/**Data to sign for the hot offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString DataToSign;
	/**Transaction for approval of the hot offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString TxApprove;
	/**Transaction in custody of the hot offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString TxInCustody;
	/**The date the hot offer was created*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString CreatedOn;
	/**The user who created the hot offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString CreatedBy;
	/**The date the hot offer was last modified*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ModifiedOn;
	/**The user who last modified the hot offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ModifiedBy;
	/**Indicates if the hot offer is signed*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") bool Signed;
	/**The currency type of the hot offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyCurrencyType Currency;
	/**The profile of the seller*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyUserProfileDto Seller;
	/**The amount purchased for the hot offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int AmountPurchased;
	/**The amount reimbursed for the hot offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int AmountReimbursed;
	/**The amount terminated for the hot offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int AmountTerminated;
	/**The visibility type of the hot offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyVisibilityType Visibility;
	/**The price of the hot offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double Price;
};


UCLASS(BlueprintType)
class VENLY_API UVyHotOfferDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyHotOfferDtoRef* ToObject(const FVyHotOfferDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyHotOfferDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyHotOfferDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyHotOfferDto Data{};
};