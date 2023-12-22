#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/VyEnums_generated.h"
#include "VyReferenceDto.generated.h"

/*
* A reference data transfer object
*/
USTRUCT(BlueprintType)
struct FVyReferenceDto : public FVyDTO
{
	GENERATED_BODY()
	/**The identifier of the reference*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Id;
	/**The type of the reference*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyReferenceType Type;
};


UCLASS(BlueprintType)
class UVyReferenceDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyReferenceDtoRef* ToObject(const FVyReferenceDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyReferenceDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyReferenceDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyReferenceDto Data{};
};