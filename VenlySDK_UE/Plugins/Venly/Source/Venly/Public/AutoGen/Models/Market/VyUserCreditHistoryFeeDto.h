#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/VyEnums_generated.h"
#include "VyUserCreditHistoryFeeDto.generated.h"

/*
* User credit history fee information
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyUserCreditHistoryFeeDto : public FVyDTO
{
	GENERATED_BODY()
	/**The type of the fee*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyCreditHistoryFeeType Type;
	/**The percentage of the fee*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double Percentage;
	/**The amount of the fee*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double Amount;
};


UCLASS(BlueprintType)
class VENLY_API UVyUserCreditHistoryFeeDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyUserCreditHistoryFeeDtoRef* ToObject(const FVyUserCreditHistoryFeeDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyUserCreditHistoryFeeDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyUserCreditHistoryFeeDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyUserCreditHistoryFeeDto Data{};
};