#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/Models/Shared/VyTypeValueDto.h"
#include "AutoGen/Models/Shared/VyTokenAttributeDto.h"
#include "AutoGen/Models/Shared/VyMultiTokenContractDto.h"
#include "VyMultiTokenDto.generated.h"

/*
* Data transfer object for a MultiToken
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyMultiTokenDto : public FVyDTO
{
	GENERATED_BODY()
	/**The ID of the MultiToken*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Id;
	/**The name of the MultiToken*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Name;
	/**The description of the MultiToken*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Description;
	/**The URL of the MultiToken*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Url;
	/**The background color of the MultiToken*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString BackgroundColor;
	/**The URL of the image associated with the MultiToken*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ImageUrl;
	/**The URL of the preview image associated with the MultiToken*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ImagePreviewUrl;
	/**The URL of the thumbnail image associated with the MultiToken*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ImageThumbnailUrl;
	/**The URL of the animation associated with the MultiToken*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString AnimationUrl;
	/**An array of animation URLs associated with the MultiToken*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") TArray<FVyTypeValueDto> AnimationUrls;
	/**Indicates whether the MultiToken is fungible*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") bool Fungible;
	/**The contract details of the MultiToken*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyMultiTokenContractDto Contract;
	/**An array of attributes associated with the MultiToken*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") TArray<FVyTokenAttributeDto> Attributes;
	/**The current balance of the MultiToken*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int Balance;
	/**The final balance of the MultiToken*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int FinalBalance;
	/**Indicates whether transfer fees are applicable for the MultiToken*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") bool TransferFees;
};


UCLASS(BlueprintType)
class VENLY_API UVyMultiTokenDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyMultiTokenDtoRef* ToObject(const FVyMultiTokenDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyMultiTokenDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyMultiTokenDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyMultiTokenDto Data{};
};