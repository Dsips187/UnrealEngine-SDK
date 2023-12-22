#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/Models/Market/VyCollectionSocialDto.h"
#include "AutoGen/Models/Market/VyCollectionContractDto.h"
#include "AutoGen/Models/Market/VyCollectionStatsDto.h"
#include "AutoGen/VyEnums_generated.h"
#include "VyCollectionDto.generated.h"

/*
* A data transfer object representing a collection
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyCollectionDto : public FVyDTO
{
	GENERATED_BODY()
	/**The public identifier of the collection*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString PublicIdentifier;
	/**The name of the collection*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Name;
	/**Indicates if the collection is verified*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") bool Verified;
	/**Indicates if the collection is premium*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") bool Premium;
	/**The contracts associated with the collection*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") TArray<FVyCollectionContractDto> Contracts;
	/**The banner image URL of the collection*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Banner;
	/**The logo image URL of the collection*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Logo;
	/**The description of the collection*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Description;
	/**The source of the collection*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyCollectionSource Source;
	/**The URL of the collection*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString CollectionUrl;
	/**The social media accounts associated with the collection*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") TArray<FVyCollectionSocialDto> Socials;
	/**The categories of the collection*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") TArray<FString> Categories;
	/**The statistics of the collection*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyCollectionStatsDto Stats;
	/**The number of items in the collection*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int NumberOfItems;
};


UCLASS(BlueprintType)
class VENLY_API UVyCollectionDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyCollectionDtoRef* ToObject(const FVyCollectionDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyCollectionDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyCollectionDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyCollectionDto Data{};
};