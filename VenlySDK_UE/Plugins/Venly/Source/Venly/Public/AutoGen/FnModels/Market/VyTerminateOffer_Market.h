#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/Models/Market/VyOfferTerminationDto.h"

#include "VyTerminateOffer_Market.generated.h"


//REQUEST [terminateOffer]
/*
* Request parameters to terminate an offer
*/
USTRUCT(BlueprintType)
struct FVyTerminateOfferRequest : public FVyDTO
{
	GENERATED_BODY()
	/**(read-only) The type of the request, should be "TERMINATION"*/
	UPROPERTY(BlueprintReadOnly, Category="Venly") FString Type{TEXT("TERMINATION")};
	/**The ID of the offer to be terminated*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString OfferId;
	/**The ID of the user initiating the termination*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString UserId;
};


UCLASS(BlueprintType)
class UVyTerminateOfferRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyTerminateOfferRequestRef* ToObject(const FVyTerminateOfferRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyTerminateOfferRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyTerminateOfferRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyTerminateOfferRequest Data{};
};
//RESPONSE [TerminationDto]
USTRUCT(BlueprintType)
struct FVyTerminateOfferResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyOfferTerminationDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnTerminateOfferCompleteBP, FVyTerminateOfferResponse, Result);
