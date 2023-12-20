#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/Models/Market/VyUserProfileDto.h"
#include "VyBidDto.generated.h"

/*
* Bid data transfer object
*/
USTRUCT(BlueprintType)
struct FVyBidDto : public FVyDTO
{
	GENERATED_BODY()
	/**The unique identifier of the bid*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Id;
	/**The user who made the bid*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyUserProfileDto User;
	/**The amount of the bid*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double Amount;
	/**The identifier of the offer associated with the bid*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString OfferId;
	/**The external user identifier*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ExternalUserId;
	/**The date and time when the bid was created*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FDateTime CreatedOn;
};


UCLASS(BlueprintType)
class UVyBidDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyBidDtoRef* ToObject(const FVyBidDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyBidDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyBidDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyBidDto Data{};
};