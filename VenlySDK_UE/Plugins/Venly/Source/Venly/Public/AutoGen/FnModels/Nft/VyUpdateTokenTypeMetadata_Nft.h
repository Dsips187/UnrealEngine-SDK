#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/Optionals/VyOptTokenAttributeArray.h"
#include "AutoGen/Optionals/VyOptTypeValueArray.h"

#include "VyUpdateTokenTypeMetadata_Nft.generated.h"


//REQUEST [updateTokenTypeMetadata]
/*
* Request parameters to update token type metadata
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyUpdateTokenTypeMetadataRequest : public FVyDTO
{
	GENERATED_BODY()
	/**The name of the token type*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Name;
	/**A description for the token type*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString Description;
	/**The URL of the image for the token type*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString ImageUrl;
	/**The external URL associated with the token type*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString ExternalUrl;
	/**The background color of the token type*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString BackgroundColor;
	/**An array of animation URLs for the token type*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptTypeValueArray AnimationUrls;
	/**An array of attributes for the token type*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptTokenAttributeArray Attributes;
	
	virtual ~FVyUpdateTokenTypeMetadataRequest() = default;
	virtual bool HasPropertyLUT() const override { return true; }
	virtual const TMap<FName, FName>& GetPropertyLUT() const override;
};


UCLASS(BlueprintType)
class VENLY_API UVyUpdateTokenTypeMetadataRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyUpdateTokenTypeMetadataRequestRef* ToObject(const FVyUpdateTokenTypeMetadataRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyUpdateTokenTypeMetadataRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyUpdateTokenTypeMetadataRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyUpdateTokenTypeMetadataRequest Data{};
};
//RESPONSE [#type]
USTRUCT(BlueprintType)
struct VENLY_API FVyUpdateTokenTypeMetadataResponse : public FVyApiResponse, public FVyResponseTrait_VariantResult
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FString Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnUpdateTokenTypeMetadataCompleteBP, FVyUpdateTokenTypeMetadataResponse, Result);
