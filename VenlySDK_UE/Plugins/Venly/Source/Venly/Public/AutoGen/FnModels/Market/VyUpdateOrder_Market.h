#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Market/VyOrderDto.h"

#include "VyUpdateOrder_Market.generated.h"


//REQUEST [updateOrder]
/*
* Request parameters to update an order
*/
USTRUCT(BlueprintType)
struct FVyUpdateOrderRequest : public FVyDTO
{
	GENERATED_BODY()
	/**The updated amount for the order*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double Amount;
};


UCLASS(BlueprintType)
class UVyUpdateOrderRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyUpdateOrderRequestRef* ToObject(const FVyUpdateOrderRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyUpdateOrderRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyUpdateOrderRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyUpdateOrderRequest Data{};
};
//RESPONSE [OrderDto]
USTRUCT(BlueprintType)
struct FVyUpdateOrderResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyOrderDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnUpdateOrderCompleteBP, FVyUpdateOrderResponse, Result);
