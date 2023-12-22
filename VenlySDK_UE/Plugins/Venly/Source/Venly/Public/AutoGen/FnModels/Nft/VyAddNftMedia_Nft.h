#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Nft/VyNftMediaDto.h"

#include "VyAddNftMedia_Nft.generated.h"


//REQUEST [addNftMedia]
/*
* Request parameters to add media to an NFT
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyAddNftMediaRequest : public FVyDTO
{
	GENERATED_BODY()
	/**The file to be added as media to the NFT*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString File;
};


UCLASS(BlueprintType)
class VENLY_API UVyAddNftMediaRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyAddNftMediaRequestRef* ToObject(const FVyAddNftMediaRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyAddNftMediaRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyAddNftMediaRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyAddNftMediaRequest Data{};
};
//RESPONSE [UploadNftMediaResponse]
USTRUCT(BlueprintType)
struct VENLY_API FVyAddNftMediaResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyNftMediaDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnAddNftMediaCompleteBP, FVyAddNftMediaResponse, Result);
