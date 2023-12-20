#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/VyEnums_generated.h"
#include "VyTradingPairDetailsDto.generated.h"

/*
* Trading pair details
*/
USTRUCT(BlueprintType)
struct FVyTradingPairDetailsDto : public FVyDTO
{
	GENERATED_BODY()
	/**The blockchain of the trading pair*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyChain Chain;
	/**The symbol of the trading pair*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Symbol;
	/**The address of the token in the trading pair*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString TokenAddress;
	
	virtual ~FVyTradingPairDetailsDto() = default;
	virtual bool HasPropertyLUT() const override { return true; }
	virtual const TMap<FName, FName>& GetPropertyLUT() const override;
};


UCLASS(BlueprintType)
class UVyTradingPairDetailsDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyTradingPairDetailsDtoRef* ToObject(const FVyTradingPairDetailsDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyTradingPairDetailsDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyTradingPairDetailsDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyTradingPairDetailsDto Data{};
};