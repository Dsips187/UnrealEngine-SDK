#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/VyEnums_generated.h"
#include "VyDepositAddressDto.generated.h"

/*
* Deposit address information
*/
USTRUCT(BlueprintType)
struct FVyDepositAddressDto : public FVyDTO
{
	GENERATED_BODY()
	/**The user ID*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString UserId;
	/**The preferred blockchain for the deposit address*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyChain Chain;
	/**The deposit address*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Address;
	/**The memo associated with the deposit address*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Memo;
};


UCLASS(BlueprintType)
class UVyDepositAddressDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyDepositAddressDtoRef* ToObject(const FVyDepositAddressDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyDepositAddressDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyDepositAddressDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyDepositAddressDto Data{};
};