#pragma once
#include "Models/VyCoreModels.h"

#include "VyTransactionResultDto.generated.h"

/*
* Data transfer object for transaction result
*/
USTRUCT(BlueprintType)
struct FVyTransactionResultDto : public FVyDTO
{
	GENERATED_BODY()
	/**Hash of the transaction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString TransactionHash;
	/**Details of the transaction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString TransactionDetails;
};


UCLASS(BlueprintType)
class UVyTransactionResultDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyTransactionResultDtoRef* ToObject(const FVyTransactionResultDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyTransactionResultDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyTransactionResultDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyTransactionResultDto Data{};
};