#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/VyEnums_generated.h"
#include "AutoGen/Optionals/VyOptChain.h"
#include "AutoGen/Models/Market/VyOrderDto.h"

#include "VyCreateOrder_Market.generated.h"


//REQUEST [createOrder]
/*
* Request parameters to create an order
*/
USTRUCT(BlueprintType)
struct FVyCreateOrderRequest : public FVyDTO
{
	GENERATED_BODY()
	/**Identifier of the user*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString UserId;
	/**The type of trading*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyTradingType Type;
	/**The preferred blockchain for the order*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptChain Chain;
	/**A memo for the transaction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString TransactionMemo;
	/**The amount of the order*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double Amount;
	/**The address for the order*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Address;
	/**The country of the user*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString UserCountry;
};


UCLASS(BlueprintType)
class UVyCreateOrderRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyCreateOrderRequestRef* ToObject(const FVyCreateOrderRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyCreateOrderRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyCreateOrderRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyCreateOrderRequest Data{};
};
//RESPONSE [OrderDto]
USTRUCT(BlueprintType)
struct FVyCreateOrderResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyOrderDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnCreateOrderCompleteBP, FVyCreateOrderResponse, Result);
