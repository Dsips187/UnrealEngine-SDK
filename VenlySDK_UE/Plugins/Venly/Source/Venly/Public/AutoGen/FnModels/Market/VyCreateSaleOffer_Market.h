#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Market/VySaleDto.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/Optionals/VyOptDouble.h"
#include "AutoGen/Optionals/VyOptInt.h"
#include "AutoGen/Optionals/VyOptCurrencyType.h"
#include "AutoGen/Optionals/VyOptDateTime.h"
#include "AutoGen/Optionals/VyOptVisibilityType.h"
#include "AutoGen/Models/Market/VyNftDto.h"

#include "VyCreateSaleOffer_Market.generated.h"


//REQUEST [saleOffer]
/*
* Request parameters for creating a sale offer
*/
USTRUCT(BlueprintType)
struct VENLY_API FVySaleOfferRequest : public FVyDTO
{
	GENERATED_BODY()
	/**The price of the sale offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptDouble Price;
	/**The amount of the sale offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptInt Amount;
	/**The minimum buy amount for the sale offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptInt MinBuyAmount;
	/**The maximum buy amount for the sale offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptInt MaxBuyAmount;
	/**(read-only) The type of the sale offer, should be "SALE"*/
	UPROPERTY(BlueprintReadOnly, Category="Venly") FString Type{TEXT("SALE")};
	/**The NFT associated with the sale offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyNftDto Nft;
	/**The start date of the sale offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptDateTime StartDate;
	/**The end date of the sale offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptDateTime EndDate;
	/**The signature of the sale offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString Signature;
	/**The address of the seller*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString SellerAddress;
	/**The external ID of the seller*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString ExternalSellerId;
	/**The currency type of the sale offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptCurrencyType Currency;
	/**The ID of the seller*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString SellerId;
	/**The visibility type of the sale offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptVisibilityType Visibility;
};


UCLASS(BlueprintType)
class VENLY_API UVySaleOfferRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVySaleOfferRequestRef* ToObject(const FVySaleOfferRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVySaleOfferRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVySaleOfferRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVySaleOfferRequest Data{};
};
//RESPONSE [SaleDto]
USTRUCT(BlueprintType)
struct VENLY_API FVyCreateSaleOfferResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVySaleDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnCreateSaleOfferCompleteBP, FVyCreateSaleOfferResponse, Result);
