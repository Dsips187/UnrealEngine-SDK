#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/VyEnums_generated.h"
#include "VyStorageDto.generated.h"

/*
* A data transfer object representing storage information
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyStorageDto : public FVyDTO
{
	GENERATED_BODY()
	/**The type of storage*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyStorageType Type;
	/**The location of the storage*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Location;
};


UCLASS(BlueprintType)
class VENLY_API UVyStorageDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyStorageDtoRef* ToObject(const FVyStorageDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyStorageDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyStorageDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyStorageDto Data{};
};