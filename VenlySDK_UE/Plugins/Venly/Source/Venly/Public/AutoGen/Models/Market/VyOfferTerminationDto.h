#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/VyEnums_generated.h"
#include "VyOfferTerminationDto.generated.h"

/*
* Data transfer object for offer termination
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyOfferTerminationDto : public FVyDTO
{
	GENERATED_BODY()
	/**The ID of the termination*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Id;
	/**The type of fulfillment*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyFulfillmentType Type;
	/**The ID of the offer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString OfferId;
	/**The transaction out of custody*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString TxOutOfCustody;
	/**The amount of the termination*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int Amount;
	/**The status of the fulfillment*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyFulfillmentState Status;
	/**The creation date of the termination*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString CreationDate;
	/**The transaction association*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString TxAssociation;
};


UCLASS(BlueprintType)
class VENLY_API UVyOfferTerminationDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyOfferTerminationDtoRef* ToObject(const FVyOfferTerminationDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyOfferTerminationDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyOfferTerminationDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyOfferTerminationDto Data{};
};