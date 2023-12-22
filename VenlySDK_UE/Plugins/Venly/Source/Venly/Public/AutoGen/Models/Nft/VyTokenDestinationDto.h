#pragma once
#include "Models/VyCoreModels.h"

#include "VyTokenDestinationDto.generated.h"

/*
* A data transfer object representing a token destination
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyTokenDestinationDto : public FVyDTO
{
	GENERATED_BODY()
	/**The address of the token destination*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Address;
	/**The amount of tokens to be sent to the destination*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int Amount;
};


UCLASS(BlueprintType)
class VENLY_API UVyTokenDestinationDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyTokenDestinationDtoRef* ToObject(const FVyTokenDestinationDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyTokenDestinationDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyTokenDestinationDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyTokenDestinationDto Data{};
};