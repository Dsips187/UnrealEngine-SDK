#pragma once
#include "Models/VyCoreModels.h"

#include "VyCollectionVolumeDto.generated.h"

/*
* A data transfer object representing the volume of a collection
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyCollectionVolumeDto : public FVyDTO
{
	GENERATED_BODY()
	/**The volume of the collection in the last 7 days*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int Last7Days;
	/**The volume of the collection in the last 14 days*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int Last14Days;
	/**The volume of the collection in the last 30 days*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int Last30days;
	/**The volume of the collection in the last 90 days*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int Last90Days;
};


UCLASS(BlueprintType)
class VENLY_API UVyCollectionVolumeDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyCollectionVolumeDtoRef* ToObject(const FVyCollectionVolumeDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyCollectionVolumeDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyCollectionVolumeDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyCollectionVolumeDto Data{};
};