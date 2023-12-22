#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/Models/Wallet/VyExchangeRateDto.h"
#include "VyExchangeRateResultDto.generated.h"

/*
* Exchange rate result data transfer object
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyExchangeRateResultDto : public FVyDTO
{
	GENERATED_BODY()
	/**List of exchange rates*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") TArray<FVyExchangeRateDto> ExchangeRates;
	/**The best exchange rate*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyExchangeRateDto BestRate;
};


UCLASS(BlueprintType)
class VENLY_API UVyExchangeRateResultDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyExchangeRateResultDtoRef* ToObject(const FVyExchangeRateResultDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyExchangeRateResultDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyExchangeRateResultDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyExchangeRateResultDto Data{};
};