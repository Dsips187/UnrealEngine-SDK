#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/Optionals/VyOptBool.h"
#include "AutoGen/Optionals/VyOptTokenDestinationArray.h"
#include "AutoGen/Models/Nft/VyTokenTypeDto.h"
#include "AutoGen/Optionals/VyOptStorage.h"
#include "AutoGen/Optionals/VyOptTokenAttributeArray.h"
#include "AutoGen/Optionals/VyOptInt.h"
#include "AutoGen/Optionals/VyOptTypeValueArray.h"

#include "VyCreateTokenType_Nft.generated.h"


//REQUEST [createTokenType]
/*
* Request parameters to create a token type
*/
USTRUCT(BlueprintType)
struct FVyCreateTokenTypeRequest : public FVyDTO
{
	GENERATED_BODY()
	/**Specifies if the token is fungible*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptBool Fungible;
	/**Specifies if the token is burnable*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptBool Burnable;
	/**The name of the token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Name;
	/**A description for the token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString Description;
	/**The URL of the token's image*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString ImageUrl;
	/**The external URL associated with the token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString ExternalUrl;
	/**The background color of the token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString BackgroundColor;
	/**An array of animation URLs for the token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptTypeValueArray AnimationUrls;
	/**The maximum supply of the token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptInt MaxSupply;
	/**The URL of the token's animation*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString AnimationUrl;
	/**The YouTube URL associated with the token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString YoutubeUrl;
	/**An array of attributes for the token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptTokenAttributeArray Attributes;
	/**An array of destinations for the token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptTokenDestinationArray Destinations;
	/**The storage configuration for the token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptStorage Storage;
	
	virtual ~FVyCreateTokenTypeRequest() = default;
	virtual bool HasPropertyLUT() const override { return true; }
	virtual const TMap<FName, FName>& GetPropertyLUT() const override;
};


UCLASS(BlueprintType)
class UVyCreateTokenTypeRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyCreateTokenTypeRequestRef* ToObject(const FVyCreateTokenTypeRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyCreateTokenTypeRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyCreateTokenTypeRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyCreateTokenTypeRequest Data{};
};
//RESPONSE [TokenTypeView]
USTRUCT(BlueprintType)
struct FVyCreateTokenTypeResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyTokenTypeDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnCreateTokenTypeCompleteBP, FVyCreateTokenTypeResponse, Result);
