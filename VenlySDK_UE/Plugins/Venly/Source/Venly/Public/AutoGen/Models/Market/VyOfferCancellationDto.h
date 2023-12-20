#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/VyEnums_generated.h"
#include "VyOfferCancellationDto.generated.h"

/*
* Data transfer object for offer cancellation
*/
USTRUCT(BlueprintType)
struct FVyOfferCancellationDto : public FVyDTO
{
	GENERATED_BODY()
	/**The ID of the cancellation*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Id;
	/**The type of fulfillment for the cancellation*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyFulfillmentType Type;
	/**The ID of the offer being cancelled*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString OfferId;
	/**The transaction out of custody*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString TxOutOfCustody;
	/**The amount of the cancellation*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int Amount;
	/**The status of the cancellation*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyFulfillmentState Status;
	/**The creation date of the cancellation*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString CreationDate;
	/**The transaction association*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString TxAssociation;
};


UCLASS(BlueprintType)
class UVyOfferCancellationDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyOfferCancellationDtoRef* ToObject(const FVyOfferCancellationDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyOfferCancellationDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyOfferCancellationDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyOfferCancellationDto Data{};
};