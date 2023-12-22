#pragma once
#include "Models/VyCoreModels.h"

#include "VyWithdrawalFeeDto.generated.h"

/*
* Withdrawal fee information
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyWithdrawalFeeDto : public FVyDTO
{
	GENERATED_BODY()
	/**The minimum withdrawal fee*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double MinWithdrawalFee;
	/**The withdrawal fee percentage for market withdrawals*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double MarketWithdrawalFeePercentage;
};


UCLASS(BlueprintType)
class VENLY_API UVyWithdrawalFeeDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyWithdrawalFeeDtoRef* ToObject(const FVyWithdrawalFeeDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyWithdrawalFeeDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyWithdrawalFeeDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyWithdrawalFeeDto Data{};
};