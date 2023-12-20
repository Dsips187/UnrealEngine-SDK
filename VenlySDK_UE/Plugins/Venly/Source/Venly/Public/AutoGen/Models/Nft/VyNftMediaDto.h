#pragma once
#include "Models/VyCoreModels.h"

#include "VyNftMediaDto.generated.h"

/*
* Data transfer object for NFT media
*/
USTRUCT(BlueprintType)
struct FVyNftMediaDto : public FVyDTO
{
	GENERATED_BODY()
	/**The media associated with the NFT*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Media;
};


UCLASS(BlueprintType)
class UVyNftMediaDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyNftMediaDtoRef* ToObject(const FVyNftMediaDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyNftMediaDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyNftMediaDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyNftMediaDto Data{};
};