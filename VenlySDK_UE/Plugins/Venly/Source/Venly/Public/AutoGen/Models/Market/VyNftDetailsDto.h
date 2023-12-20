#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/Models/Market/VyCollectionDetailsDto.h"
#include "AutoGen/VyEnums_generated.h"
#include "AutoGen/Models/Shared/VyTypeValueDto.h"
#include "AutoGen/Models/Shared/VyTokenAttributeDto.h"
#include "VyNftDetailsDto.generated.h"

/*
* Details of an NFT
*/
USTRUCT(BlueprintType)
struct FVyNftDetailsDto : public FVyDTO
{
	GENERATED_BODY()
	/**The ID of the NFT*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Id;
	/**The address of the NFT*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Address;
	/**The blockchain of the NFT*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyChain Chain;
	/**The name of the NFT*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Name;
	/**The description of the NFT*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Description;
	/**The URL of the image associated with the NFT*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ImageUrl;
	/**The background color of the NFT*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString BackgroundColor;
	/**The URL associated with the NFT*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Url;
	/**The URL of the preview image associated with the NFT*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ImagePreviewUrl;
	/**The URL of the thumbnail image associated with the NFT*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ImageThumbnailUrl;
	/**The URLs of the animations associated with the NFT*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") TArray<FVyTypeValueDto> AnimationUrls;
	/**Indicates if the NFT is fungible*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") bool Fungible;
	/**The maximum supply of the NFT*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int MaxSupply;
	/**The attributes of the NFT*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") TArray<FVyTokenAttributeDto> Attributes;
	/**The contract details of the NFT*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyCollectionDetailsDto Contract;
	/**The identifier of the collection*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString CollectionIdentifier;
};


UCLASS(BlueprintType)
class UVyNftDetailsDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyNftDetailsDtoRef* ToObject(const FVyNftDetailsDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyNftDetailsDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyNftDetailsDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyNftDetailsDto Data{};
};