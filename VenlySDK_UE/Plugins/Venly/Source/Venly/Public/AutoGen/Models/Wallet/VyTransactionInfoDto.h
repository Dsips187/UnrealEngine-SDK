#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/VyEnums_generated.h"
#include "VyTransactionInfoDto.generated.h"

/*
* Transaction information
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyTransactionInfoDto : public FVyDTO
{
	GENERATED_BODY()
	/**Transaction hash*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Hash;
	/**Transaction status*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyTransactionState Status;
	/**Number of confirmations*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int Confirmations;
	/**Block hash*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString BlockHash;
	/**Block number*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int BlockNumber;
	/**Indicates if the transaction has reached finality*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") bool HasReachedFinality;
	/**The blockchain on which the transaction occurred*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyChain Chain;
};


UCLASS(BlueprintType)
class VENLY_API UVyTransactionInfoDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyTransactionInfoDtoRef* ToObject(const FVyTransactionInfoDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyTransactionInfoDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyTransactionInfoDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyTransactionInfoDto Data{};
};