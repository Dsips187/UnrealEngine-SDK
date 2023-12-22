#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/Optionals/VyOptDouble.h"
#include "AutoGen/Models/Market/VyAuctionDto.h"
#include "AutoGen/Optionals/VyOptCurrencyType.h"
#include "AutoGen/Optionals/VyOptDateTime.h"
#include "AutoGen/Optionals/VyOptVisibilityType.h"
#include "AutoGen/Models/Market/VyNftDto.h"

#include "VyCreateAuctionOffer_Market.generated.h"


//REQUEST [auctionOffer]
/*
* Request parameters for making an auction offer
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyAuctionOfferRequest : public FVyDTO
{
	GENERATED_BODY()
	/**The minimum bid amount for the auction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptDouble MinimumBid;
	/**The buy now price for the auction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptDouble BuyNowPrice;
	/**(read-only) The type of the auction, should be "AUCTION"*/
	UPROPERTY(BlueprintReadOnly, Category="Venly") FString Type{TEXT("AUCTION")};
	/**The NFT being auctioned*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyNftDto Nft;
	/**The start date of the auction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptDateTime StartDate;
	/**The end date of the auction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptDateTime EndDate;
	/**The signature for the auction offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString Signature;
	/**The address of the seller*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString SellerAddress;
	/**The external ID of the seller*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString ExternalSellerId;
	/**The currency type for the auction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptCurrencyType Currency;
	/**The ID of the seller*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString SellerId;
	/**The visibility type for the auction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptVisibilityType Visibility;
};


UCLASS(BlueprintType)
class VENLY_API UVyAuctionOfferRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyAuctionOfferRequestRef* ToObject(const FVyAuctionOfferRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyAuctionOfferRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyAuctionOfferRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyAuctionOfferRequest Data{};
};
//RESPONSE [AuctionDto]
USTRUCT(BlueprintType)
struct VENLY_API FVyCreateAuctionOfferResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyAuctionDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnCreateAuctionOfferCompleteBP, FVyCreateAuctionOfferResponse, Result);
