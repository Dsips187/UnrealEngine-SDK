#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/VyEnums_generated.h"
#include "AutoGen/Models/Market/VyUserProfileDto.h"
#include "AutoGen/Models/Market/VyNftDetailsDto.h"
#include "VySaleDto.generated.h"

/*
* Sale details
*/
USTRUCT(BlueprintType)
struct FVySaleDto : public FVyDTO
{
	GENERATED_BODY()
	/**The total amount of the sale*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int Amount;
	/**The remaining amount of the sale*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int RemainingAmount;
	/**The minimum buy amount for the sale*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int MinBuyAmount;
	/**The maximum buy amount for the sale*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int MaxBuyAmount;
	/**The ID of the sale*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Id;
	/**Details of the NFT being sold*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyNftDetailsDto Nft;
	/**The ID of the seller*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString SellerId;
	/**The nickname of the seller*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString SellerNickname;
	/**The external ID of the seller*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ExternalSellerId;
	/**The address of the seller*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString SellerAddress;
	/**The start date of the sale*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FDateTime StartDate;
	/**The end date of the sale*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FDateTime EndDate;
	/**The type of the sale*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyOfferType Type;
	/**The status of the sale*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyOfferState Status;
	/**Data to sign*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString DataToSign;
	/**Transaction approval*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString TxApprove;
	/**Transaction in custody*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString TxInCustody;
	/**The date the sale was created*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FDateTime CreatedOn;
	/**The creator of the sale*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString CreatedBy;
	/**The date the sale was last modified*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FDateTime ModifiedOn;
	/**The modifier of the sale*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ModifiedBy;
	/**Indicates if the sale is signed*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") bool Signed;
	/**The currency type of the sale*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyCurrencyType Currency;
	/**The profile of the seller*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyUserProfileDto Seller;
	/**The total amount purchased*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int AmountPurchased;
	/**The total amount reimbursed*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int AmountReimbursed;
	/**The total amount terminated*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int AmountTerminated;
	/**The visibility type of the sale*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyVisibilityType Visibility;
	/**The price of the sale*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double Price;
};


UCLASS(BlueprintType)
class UVySaleDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVySaleDtoRef* ToObject(const FVySaleDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVySaleDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVySaleDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVySaleDto Data{};
};