#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/Models/Wallet/VyTradingPairDetailsDto.h"
#include "VyTradingPairDto.generated.h"

/*
* Trading pair details
*/
USTRUCT(BlueprintType)
struct FVyTradingPairDto : public FVyDTO
{
	GENERATED_BODY()
	/**Details of the 'from' token in the trading pair*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyTradingPairDetailsDto From;
	/**Details of the 'to' token in the trading pair*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyTradingPairDetailsDto To;
};


UCLASS(BlueprintType)
class UVyTradingPairDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyTradingPairDtoRef* ToObject(const FVyTradingPairDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyTradingPairDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyTradingPairDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyTradingPairDto Data{};
};