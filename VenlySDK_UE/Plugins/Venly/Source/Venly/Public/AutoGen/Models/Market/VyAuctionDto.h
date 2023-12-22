#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/Models/Market/VyBidDto.h"
#include "AutoGen/VyEnums_generated.h"
#include "AutoGen/Models/Market/VyNftDetailsDto.h"
#include "AutoGen/Models/Market/VyUserProfileDto.h"
#include "VyAuctionDto.generated.h"

/*
* Auction details
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyAuctionDto : public FVyDTO
{
	GENERATED_BODY()
	/**The minimum bid amount*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double MinimumBid;
	/**The buy now price*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double BuyNowPrice;
	/**The list of bids*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") TArray<FVyBidDto> Bids;
	/**The highest bid*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyBidDto HighestBid;
	/**The auction ID*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Id;
	/**The details of the NFT*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyNftDetailsDto Nft;
	/**The ID of the seller*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString SellerId;
	/**The nickname of the seller*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString SellerNickname;
	/**The external ID of the seller*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ExternalSellerId;
	/**The address of the seller*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString SellerAddress;
	/**The start date of the auction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FDateTime StartDate;
	/**The end date of the auction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FDateTime EndDate;
	/**The type of offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyOfferType Type;
	/**The status of the offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyOfferState Status;
	/**The data to sign*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString DataToSign;
	/**The transaction for approval*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString TxApprove;
	/**The transaction in custody*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString TxInCustody;
	/**The creation date*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FDateTime CreatedOn;
	/**The creator of the auction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString CreatedBy;
	/**The modification date*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FDateTime ModifiedOn;
	/**The modifier of the auction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ModifiedBy;
	/**Indicates if the auction is signed*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") bool Signed;
	/**The currency type*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyCurrencyType Currency;
	/**The seller's profile*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyUserProfileDto Seller;
	/**The amount purchased*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int AmountPurchased;
	/**The amount reimbursed*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int AmountReimbursed;
	/**The amount terminated*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int AmountTerminated;
	/**The visibility type*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyVisibilityType Visibility;
	/**The price*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double Price;
};


UCLASS(BlueprintType)
class VENLY_API UVyAuctionDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyAuctionDtoRef* ToObject(const FVyAuctionDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyAuctionDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyAuctionDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyAuctionDto Data{};
};