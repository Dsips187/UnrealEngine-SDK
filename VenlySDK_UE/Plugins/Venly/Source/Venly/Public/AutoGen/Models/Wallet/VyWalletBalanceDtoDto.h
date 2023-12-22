#pragma once
#include "Models/VyCoreModels.h"

#include "VyWalletBalanceDtoDto.generated.h"

/*
* A data transfer object representing the balance of a wallet
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyWalletBalanceDtoDto : public FVyDTO
{
	GENERATED_BODY()
	/**The address of the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString WalletAddress;
	/**The address of the contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ContractAddress;
	/**The balance of the token in the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int TokenBalance;
};


UCLASS(BlueprintType)
class VENLY_API UVyWalletBalanceDtoDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyWalletBalanceDtoDtoRef* ToObject(const FVyWalletBalanceDtoDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyWalletBalanceDtoDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyWalletBalanceDtoDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyWalletBalanceDtoDto Data{};
};