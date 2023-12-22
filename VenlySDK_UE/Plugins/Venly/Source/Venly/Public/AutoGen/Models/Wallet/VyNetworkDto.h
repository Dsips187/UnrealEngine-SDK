#pragma once
#include "Models/VyCoreModels.h"

#include "VyNetworkDto.generated.h"

/*
* Data structure representing a network
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyNetworkDto : public FVyDTO
{
	GENERATED_BODY()
	/**The name of the network*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Name;
	/**The URL of the network's node*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString NodeUrl;
	/**The chain ID of the network*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int ChainId;
};


UCLASS(BlueprintType)
class VENLY_API UVyNetworkDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyNetworkDtoRef* ToObject(const FVyNetworkDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyNetworkDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyNetworkDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyNetworkDto Data{};
};