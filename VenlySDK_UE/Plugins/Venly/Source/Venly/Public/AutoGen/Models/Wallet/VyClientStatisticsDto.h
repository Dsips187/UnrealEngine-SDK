#pragma once
#include "Models/VyCoreModels.h"

#include "VyClientStatisticsDto.generated.h"

/*
* Client statistics data
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyClientStatisticsDto : public FVyDTO
{
	GENERATED_BODY()
	/**The number of wallets*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int NumberOfWallets;
	/**The number of users*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int NumberOfUsers;
};


UCLASS(BlueprintType)
class VENLY_API UVyClientStatisticsDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyClientStatisticsDtoRef* ToObject(const FVyClientStatisticsDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyClientStatisticsDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyClientStatisticsDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyClientStatisticsDto Data{};
};