#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/Optionals/VyOptInt.h"
#include "AutoGen/Models/Market/VyOfferCancellationDto.h"

#include "VyCancelOffer_Market.generated.h"


//REQUEST [cancelOffer]
/*
* Request parameters to cancel an offer
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyCancelOfferRequest : public FVyDTO
{
	GENERATED_BODY()
	/**The amount to cancel*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptInt Amount;
	/**(read-only) The type of cancellation, should be "REIMBURSEMENT"*/
	UPROPERTY(BlueprintReadOnly, Category="Venly") FString Type{TEXT("REIMBURSEMENT")};
	/**The ID of the offer to cancel*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString OfferId;
	/**The ID of the user cancelling the offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString UserId;
};


UCLASS(BlueprintType)
class VENLY_API UVyCancelOfferRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyCancelOfferRequestRef* ToObject(const FVyCancelOfferRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyCancelOfferRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyCancelOfferRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyCancelOfferRequest Data{};
};
//RESPONSE [ReimbursementDto]
USTRUCT(BlueprintType)
struct VENLY_API FVyCancelOfferResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyOfferCancellationDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnCancelOfferCompleteBP, FVyCancelOfferResponse, Result);
