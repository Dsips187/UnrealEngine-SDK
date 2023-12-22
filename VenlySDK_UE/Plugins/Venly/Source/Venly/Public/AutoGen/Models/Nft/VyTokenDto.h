#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/VyEnums_generated.h"
#include "AutoGen/Models/Nft/VyTokenTypeDto.h"
#include "VyTokenDto.generated.h"

/*
* Data transfer object for a token
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyTokenDto : public FVyDTO
{
	GENERATED_BODY()
	/**The blockchain on which the token exists*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyChain Chain;
	/**The address of the token contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ContractAddress;
	/**The unique identifier of the token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int Id;
	/**The type of the token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyTokenTypeDto TokenType;
	/**The amount of the token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int Amount;
	/**The URL of the token's image*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ImageUrl;
	/**The URL of the token's preview image*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ImagePreviewUrl;
	/**The URL of the token's thumbnail image*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ImageThumbnailUrl;
	/**The external URL associated with the token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ExternalUrl;
	/**The background color of the token*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString BackgroundColor;
	
	virtual ~FVyTokenDto() = default;
	virtual bool HasPropertyLUT() const override { return true; }
	virtual const TMap<FName, FName>& GetPropertyLUT() const override;
};


UCLASS(BlueprintType)
class VENLY_API UVyTokenDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyTokenDtoRef* ToObject(const FVyTokenDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyTokenDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyTokenDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyTokenDto Data{};
};