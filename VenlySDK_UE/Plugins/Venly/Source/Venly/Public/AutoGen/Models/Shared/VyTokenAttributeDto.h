#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/VyEnums_generated.h"
#include "VyTokenAttributeDto.generated.h"

/*
* Data structure representing a token attribute
*/
USTRUCT(BlueprintType)
struct FVyTokenAttributeDto : public FVyDTO
{
	GENERATED_BODY()
	/**The type of the token attribute*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyTokenAttributeType Type;
	/**The name of the token attribute*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Name;
	/**The value of the token attribute*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Value;
	/**The display type of the token attribute*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString DisplayType;
	/**The number of traits of the token attribute*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int TraitCount;
	/**The maximum value of the token attribute*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int MaxValue;
};


UCLASS(BlueprintType)
class UVyTokenAttributeDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyTokenAttributeDtoRef* ToObject(const FVyTokenAttributeDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyTokenAttributeDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyTokenAttributeDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyTokenAttributeDto Data{};
};