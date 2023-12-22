#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Nft/VyNftImageDto.h"

#include "VyAddNftImage_Nft.generated.h"


//REQUEST [addNftImage]
/*
* Request parameters to add an image to an NFT
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyAddNftImageRequest : public FVyDTO
{
	GENERATED_BODY()
	/**The file path or URL of the image to be added*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString File;
};


UCLASS(BlueprintType)
class VENLY_API UVyAddNftImageRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyAddNftImageRequestRef* ToObject(const FVyAddNftImageRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyAddNftImageRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyAddNftImageRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyAddNftImageRequest Data{};
};
//RESPONSE [UploadNftImageResponse]
USTRUCT(BlueprintType)
struct VENLY_API FVyAddNftImageResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyNftImageDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnAddNftImageCompleteBP, FVyAddNftImageResponse, Result);
