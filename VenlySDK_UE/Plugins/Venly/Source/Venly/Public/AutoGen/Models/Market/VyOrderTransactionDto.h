#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/VyEnums_generated.h"
#include "VyOrderTransactionDto.generated.h"

/*
* Order transaction details
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyOrderTransactionDto : public FVyDTO
{
	GENERATED_BODY()
	/**The hash of the transaction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString TransactionHash;
	/**The blockchain on which the transaction occurred*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyChain Blockchain;
	/**The destination of the transaction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Destination;
	/**A memo associated with the transaction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Memo;
};


UCLASS(BlueprintType)
class VENLY_API UVyOrderTransactionDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyOrderTransactionDtoRef* ToObject(const FVyOrderTransactionDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyOrderTransactionDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyOrderTransactionDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyOrderTransactionDto Data{};
};