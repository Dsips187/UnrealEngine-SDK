#pragma once
#include "Models/VyCoreModels.h"

#include "VyBlockchainInfoDto.generated.h"

/*
* Blockchain information data transfer object
*/
USTRUCT(BlueprintType)
struct FVyBlockchainInfoDto : public FVyDTO
{
	GENERATED_BODY()
	/**The current block number*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int BlockNumber;
	/**The number of confirmations required for a transaction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int RequiredConfirmations;
	/**The ID of the blockchain chain*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int ChainId;
};


UCLASS(BlueprintType)
class UVyBlockchainInfoDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyBlockchainInfoDtoRef* ToObject(const FVyBlockchainInfoDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyBlockchainInfoDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyBlockchainInfoDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyBlockchainInfoDto Data{};
};