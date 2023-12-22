#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/VyEnums_generated.h"
#include "VyExchangeRateDto.generated.h"

/*
* Exchange rate information
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyExchangeRateDto : public FVyDTO
{
	GENERATED_BODY()
	/**The exchange platform*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyExchange Exchange;
	/**The type of order*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyOrderType OrderType;
	/**The amount to be exchanged*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double InputAmount;
	/**The resulting amount after the exchange*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double OutputAmount;
	/**The allowed slippage percentage*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double Slippage;
	/**The fee for the exchange*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double Fee;
};


UCLASS(BlueprintType)
class VENLY_API UVyExchangeRateDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyExchangeRateDtoRef* ToObject(const FVyExchangeRateDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyExchangeRateDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyExchangeRateDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyExchangeRateDto Data{};
};