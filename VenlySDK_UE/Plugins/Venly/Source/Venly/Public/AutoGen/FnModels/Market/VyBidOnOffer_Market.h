#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/Models/Market/VyOfferDto.h"
#include "AutoGen/Optionals/VyOptDouble.h"

#include "VyBidOnOffer_Market.generated.h"


//REQUEST [bid]
/*
* Request parameters for placing a bid
*/
USTRUCT(BlueprintType)
struct FVyBidRequest : public FVyDTO
{
	GENERATED_BODY()
	/**Identifier of the user placing the bid*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString UserId;
	/**Identifier of the offer being bid on*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString OfferId;
	/**Amount of the bid*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptDouble Amount;
	/**External identifier of the user placing the bid*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString ExternalUserId;
};


UCLASS(BlueprintType)
class UVyBidRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyBidRequestRef* ToObject(const FVyBidRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyBidRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyBidRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyBidRequest Data{};
};
//RESPONSE [update_merged]
USTRUCT(BlueprintType)
struct FVyBidOnOfferResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyOfferDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnBidOnOfferCompleteBP, FVyBidOnOfferResponse, Result);
