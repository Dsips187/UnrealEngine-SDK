#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/Models/Shared/VyTypeValueDto.h"
#include "VyContractMetadataDto.generated.h"

/*
* Contract metadata information
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyContractMetadataDto : public FVyDTO
{
	GENERATED_BODY()
	/**The name of the contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Name;
	/**The description of the contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Description;
	/**The symbol of the contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Symbol;
	/**The external URL of the contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ExternalUrl;
	/**The image URL of the contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ImageUrl;
	/**The media associated with the contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") TArray<FVyTypeValueDto> Media;
	/**Documentation Missing!*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ExternalLink;
	
	virtual ~FVyContractMetadataDto() = default;
	virtual bool HasPropertyLUT() const override { return true; }
	virtual const TMap<FName, FName>& GetPropertyLUT() const override;
};


UCLASS(BlueprintType)
class VENLY_API UVyContractMetadataDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyContractMetadataDtoRef* ToObject(const FVyContractMetadataDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyContractMetadataDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyContractMetadataDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyContractMetadataDto Data{};
};