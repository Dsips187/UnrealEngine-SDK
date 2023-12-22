#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/VyEnums_generated.h"
#include "AutoGen/Models/Shared/VyTypeValueDto.h"
#include "VyCollectionDetailsDto.generated.h"

/*
* Details of a collection
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyCollectionDetailsDto : public FVyDTO
{
	GENERATED_BODY()
	/**The blockchain on which the collection exists*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyChain Chain;
	/**The address of the collection*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Address;
	/**The number of items in the collection*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int Count;
	/**The name of the collection*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Name;
	/**The description of the collection*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Description;
	/**The symbol of the collection*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Symbol;
	/**The URL of the collection*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Url;
	/**The URL of the collection's image*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ImageUrl;
	/**The media associated with the collection*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") TArray<FVyTypeValueDto> Media;
	/**Indicates if the collection is verified*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") bool Verified;
	/**Indicates if the collection is premium*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") bool Premium;
	/**The categories associated with the collection*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") TArray<FString> Categories;
};


UCLASS(BlueprintType)
class VENLY_API UVyCollectionDetailsDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyCollectionDetailsDtoRef* ToObject(const FVyCollectionDetailsDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyCollectionDetailsDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyCollectionDetailsDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyCollectionDetailsDto Data{};
};