#pragma once
#include "Models/VyCoreModels.h"

#include "VyNftImageDto.generated.h"

/*
* Data transfer object for NFT image information
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyNftImageDto : public FVyDTO
{
	GENERATED_BODY()
	/**The URL of the NFT image*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Image;
	/**The URL of the NFT image preview*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ImagePreview;
	/**The URL of the NFT image thumbnail*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ImageThumbnail;
};


UCLASS(BlueprintType)
class VENLY_API UVyNftImageDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyNftImageDtoRef* ToObject(const FVyNftImageDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyNftImageDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyNftImageDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyNftImageDto Data{};
};