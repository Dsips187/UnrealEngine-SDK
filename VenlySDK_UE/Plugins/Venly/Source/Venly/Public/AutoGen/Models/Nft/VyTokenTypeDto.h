#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/Models/Shared/VyStorageDto.h"
#include "AutoGen/Models/Shared/VyTypeValueDto.h"
#include "AutoGen/Models/Shared/VyTokenAttributeDto.h"
#include "VyTokenTypeDto.generated.h"

/*
* Data structure representing a token type
*/
USTRUCT(BlueprintType)
struct FVyTokenTypeDto : public FVyDTO
{
	GENERATED_BODY()
	/**The unique identifier of the token type*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int Id;
	/**Indicates if the token type is confirmed*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") bool Confirmed;
	/**The name of the token type*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Name;
	/**The description of the token type*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Description;
	/**Indicates if the token type is fungible*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") bool Fungible;
	/**Indicates if the token type is burnable*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") bool Burnable;
	/**The external URL associated with the token type*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ExternalUrl;
	/**The background color of the token type*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString BackgroundColor;
	/**The URL of the image associated with the token type*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ImageUrl;
	/**The URL of the thumbnail image associated with the token type*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ImageThumbnailUrl;
	/**The URL of the preview image associated with the token type*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ImagePreviewUrl;
	/**The maximum supply of the token type*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int MaxSupply;
	/**The current supply of the token type*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int CurrentSupply;
	/**The URLs of the animation associated with the token type*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") TArray<FVyTypeValueDto> AnimationUrls;
	/**The attributes of the token type*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") TArray<FVyTokenAttributeDto> Attributes;
	/**The transaction hash associated with the token type*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString TransactionHash;
	/**The storage information of the token type*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyStorageDto Storage;
	
	virtual ~FVyTokenTypeDto() = default;
	virtual bool HasPropertyLUT() const override { return true; }
	virtual const TMap<FName, FName>& GetPropertyLUT() const override;
};


UCLASS(BlueprintType)
class UVyTokenTypeDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyTokenTypeDtoRef* ToObject(const FVyTokenTypeDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyTokenTypeDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyTokenTypeDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyTokenTypeDto Data{};
};