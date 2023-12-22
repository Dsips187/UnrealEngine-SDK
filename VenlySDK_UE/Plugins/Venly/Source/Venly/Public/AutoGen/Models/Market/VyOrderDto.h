#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/VyEnums_generated.h"
#include "AutoGen/Models/Market/VyOrderTransactionDto.h"
#include "VyOrderDto.generated.h"

/*
* Represents an order
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyOrderDto : public FVyDTO
{
	GENERATED_BODY()
	/**The unique identifier of the order*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Id;
	/**The user ID associated with the order*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString UserId;
	/**The quantity of the order*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double Quantity;
	/**The handling fee of the order*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double HandlingFee;
	/**The market fee of the order*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double MarketFee;
	/**The market fee percentage of the order*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double MarketFeePercentage;
	/**The currency of the order*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Currency;
	/**The status of the order*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyOrderState Status;
	/**The date of the order*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Date;
	/**The trading type of the order*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyTradingType Type;
	/**The transaction details of the order*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOrderTransactionDto Transaction;
};


UCLASS(BlueprintType)
class VENLY_API UVyOrderDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyOrderDtoRef* ToObject(const FVyOrderDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyOrderDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyOrderDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyOrderDto Data{};
};