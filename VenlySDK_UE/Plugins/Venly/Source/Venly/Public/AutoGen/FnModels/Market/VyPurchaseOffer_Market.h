#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/Optionals/VyOptInt.h"
#include "AutoGen/Models/Market/VyOfferPurchaseDto.h"

#include "VyPurchaseOffer_Market.generated.h"


//REQUEST [purchaseOffer]
/*
* Request parameters to purchase an offer
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyPurchaseOfferRequest : public FVyDTO
{
	GENERATED_BODY()
	/**External user ID*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString ExternalUserId;
	/**Wallet address*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString WalletAddress;
	/**Amount to purchase*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptInt Amount;
	/**Country of the buyer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString BuyerCountry;
	/**(read-only) The type of the request, should be "PURCHASE"*/
	UPROPERTY(BlueprintReadOnly, Category="Venly") FString Type{TEXT("PURCHASE")};
	/**ID of the offer to purchase*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString OfferId;
	/**User ID*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString UserId;
};


UCLASS(BlueprintType)
class VENLY_API UVyPurchaseOfferRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyPurchaseOfferRequestRef* ToObject(const FVyPurchaseOfferRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyPurchaseOfferRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyPurchaseOfferRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyPurchaseOfferRequest Data{};
};
//RESPONSE [PurchaseDto]
USTRUCT(BlueprintType)
struct VENLY_API FVyPurchaseOfferResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyOfferPurchaseDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnPurchaseOfferCompleteBP, FVyPurchaseOfferResponse, Result);
