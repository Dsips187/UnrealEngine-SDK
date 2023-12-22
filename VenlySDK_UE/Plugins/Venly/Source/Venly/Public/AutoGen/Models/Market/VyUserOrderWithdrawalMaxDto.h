#pragma once
#include "Models/VyCoreModels.h"

#include "VyUserOrderWithdrawalMaxDto.generated.h"

/*
* User order withdrawal maximum amount
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyUserOrderWithdrawalMaxDto : public FVyDTO
{
	GENERATED_BODY()
	/**The maximum withdrawal amount*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double MaxAmount;
};


UCLASS(BlueprintType)
class VENLY_API UVyUserOrderWithdrawalMaxDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyUserOrderWithdrawalMaxDtoRef* ToObject(const FVyUserOrderWithdrawalMaxDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyUserOrderWithdrawalMaxDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyUserOrderWithdrawalMaxDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyUserOrderWithdrawalMaxDto Data{};
};