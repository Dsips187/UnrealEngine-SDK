#pragma once
#include "Models/VyCoreModels.h"

#include "VyCollectionSocialDto.generated.h"

/*
* A social media information for an NFT collection
*/
USTRUCT(BlueprintType)
struct FVyCollectionSocialDto : public FVyDTO
{
	GENERATED_BODY()
	/**The type of social media*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Type;
	/**The value of the social media*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Value;
};


UCLASS(BlueprintType)
class UVyCollectionSocialDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyCollectionSocialDtoRef* ToObject(const FVyCollectionSocialDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyCollectionSocialDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyCollectionSocialDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyCollectionSocialDto Data{};
};