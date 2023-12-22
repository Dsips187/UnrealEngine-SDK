#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/VyEnums_generated.h"
#include "VyUserCreditBalanceDto.generated.h"

/*
* User credit balance information
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyUserCreditBalanceDto : public FVyDTO
{
	GENERATED_BODY()
	/**The currency type of the balance*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyCurrencyType Currency;
	/**The available balance*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double Balance;
	/**The locked balance*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double LockedBalance;
};


UCLASS(BlueprintType)
class VENLY_API UVyUserCreditBalanceDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyUserCreditBalanceDtoRef* ToObject(const FVyUserCreditBalanceDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyUserCreditBalanceDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyUserCreditBalanceDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyUserCreditBalanceDto Data{};
};