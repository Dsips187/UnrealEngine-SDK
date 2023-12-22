#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/Models/Market/VyOfferDto.h"
#include "AutoGen/Optionals/VyOptBool.h"
#include "AutoGen/Optionals/VyOptDouble.h"
#include "AutoGen/Optionals/VyOptVisibilityType.h"

#include "VyUpdateOffer_Market.generated.h"


//REQUEST [updateOffer]
/*
* Request parameters to update an offer
*/
USTRUCT(BlueprintType)
struct FVyUpdateOfferRequest : public FVyDTO
{
	GENERATED_BODY()
	/**The price of the offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptDouble Price;
	/**The start date of the offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString StartDate;
	/**The end date of the offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString EndDate;
	/**Indicates if the offer is private*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptBool PrivateOffer;
	/**The visibility type of the offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptVisibilityType Visibility;
};


UCLASS(BlueprintType)
class UVyUpdateOfferRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyUpdateOfferRequestRef* ToObject(const FVyUpdateOfferRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyUpdateOfferRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyUpdateOfferRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyUpdateOfferRequest Data{};
};
//RESPONSE [update_merged]
USTRUCT(BlueprintType)
struct FVyUpdateOfferResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyOfferDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnUpdateOfferCompleteBP, FVyUpdateOfferResponse, Result);
