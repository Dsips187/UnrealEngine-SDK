#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/Models/Market/VyBidDto.h"
#include "AutoGen/VyEnums_generated.h"
#include "AutoGen/Models/Market/VyNftDetailsDto.h"
#include "AutoGen/Models/Market/VyUserProfileDto.h"
#include "VyOfferDto.generated.h"

/*
* A data transfer object representing an offer
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyOfferDto : public FVyDTO
{
	GENERATED_BODY()
	/**The currency type of the offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyCurrencyType Currency;
	/**The minimum bid amount for the offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double MinimumBid;
	/**The minimum buy amount for the offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int MinBuyAmount;
	/**The transaction in custody for the offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString TxInCustody;
	/**The price of the offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double Price;
	/**The date and time when the offer was created*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FDateTime CreatedOn;
	/**The end date of the offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FDateTime EndDate;
	/**The bids made on the offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") TArray<FVyBidDto> Bids;
	/**The amount reimbursed for the offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int AmountReimbursed;
	/**The transaction approved for the offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString TxApprove;
	/**The type of the offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyOfferType Type;
	/**The data to sign for the offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString DataToSign;
	/**The details of the NFT for the offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyNftDetailsDto Nft;
	/**The date and time when the offer was last modified*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FDateTime ModifiedOn;
	/**The user who last modified the offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ModifiedBy;
	/**The remaining amount for the offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int RemainingAmount;
	/**The ID of the seller*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString SellerId;
	/**The nickname of the seller*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString SellerNickname;
	/**The start date of the offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FDateTime StartDate;
	/**The amount of the offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int Amount;
	/**The buy now price of the offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double BuyNowPrice;
	/**The amount terminated for the offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int AmountTerminated;
	/**Indicates if the offer is signed*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") bool Signed;
	/**The status of the offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyOfferState Status;
	/**The ID of the offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Id;
	/**The profile of the seller*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyUserProfileDto Seller;
	/**The amount purchased for the offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int AmountPurchased;
	/**The maximum buy amount for the offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int MaxBuyAmount;
	/**The external ID of the seller*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ExternalSellerId;
	/**The address of the seller*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString SellerAddress;
	/**The user who created the offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString CreatedBy;
	/**The visibility of the offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyVisibilityType Visibility;
	/**The highest bid on the offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyBidDto HighestBid;
};


UCLASS(BlueprintType)
class VENLY_API UVyOfferDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyOfferDtoRef* ToObject(const FVyOfferDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyOfferDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyOfferDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyOfferDto Data{};
};