#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/Models/Market/VySignMessageRequestEip712RequestDto.h"
#include "VyOfferPreparationDto.generated.h"

/*
* Offer preparation data transfer object
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyOfferPreparationDto : public FVyDTO
{
	GENERATED_BODY()
	/**Array of approval preparation transactions*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") TArray<FString> ApprovalPreparationTransactions;
	/**Array of signable messages*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") TArray<FVySignMessageRequestEip712RequestDto> SignableMessages;
};


UCLASS(BlueprintType)
class VENLY_API UVyOfferPreparationDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyOfferPreparationDtoRef* ToObject(const FVyOfferPreparationDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyOfferPreparationDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyOfferPreparationDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyOfferPreparationDto Data{};
};