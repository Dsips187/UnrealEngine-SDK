#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/Models/Shared/VyTypeValueDto.h"
#include "AutoGen/Models/Shared/VyTokenAttributeDto.h"
#include "VyTokenTypeMetadataDto.generated.h"

/*
* Token type metadata
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyTokenTypeMetadataDto : public FVyDTO
{
	GENERATED_BODY()
	/**The name of the token type*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Name;
	/**The description of the token type*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Description;
	/**Indicates if the token type is fungible*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") bool Fungible;
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
	/**The URLs of the animation associated with the token type*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") TArray<FVyTypeValueDto> AnimationUrls;
	/**The attributes of the token type*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") TArray<FVyTokenAttributeDto> Attributes;
	
	virtual ~FVyTokenTypeMetadataDto() = default;
	virtual bool HasPropertyLUT() const override { return true; }
	virtual const TMap<FName, FName>& GetPropertyLUT() const override;
};


UCLASS(BlueprintType)
class VENLY_API UVyTokenTypeMetadataDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyTokenTypeMetadataDtoRef* ToObject(const FVyTokenTypeMetadataDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyTokenTypeMetadataDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyTokenTypeMetadataDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyTokenTypeMetadataDto Data{};
};