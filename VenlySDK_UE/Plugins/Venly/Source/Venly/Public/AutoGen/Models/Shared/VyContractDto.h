#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/VyEnums_generated.h"
#include "AutoGen/Models/Shared/VyStorageDto.h"
#include "AutoGen/Models/Shared/VyTypeValueDto.h"
#include "VyContractDto.generated.h"

/*
* Data transfer object for token contract information
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyContractDto : public FVyDTO
{
	GENERATED_BODY()
	/**The name of the token contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Name;
	/**The description of the token contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Description;
	/**Indicates if the token contract is confirmed*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") bool Confirmed;
	/**The address of the token contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Address;
	/**The ID of the token contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int Id;
	/**The blockchain chain of the token contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyChain Chain;
	/**The symbol of the token contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Symbol;
	/**The external URL of the token contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ExternalUrl;
	/**The image URL of the token contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ImageUrl;
	/**The media associated with the token contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") TArray<FVyTypeValueDto> Media;
	/**The transaction hash of the token contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString TransactionHash;
	/**The owner of the token contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Owner;
	/**The storage information of the token contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyStorageDto Storage;
	/**Documentation Missing!*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ExternalLink;
	
	virtual ~FVyContractDto() = default;
	virtual bool HasPropertyLUT() const override { return true; }
	virtual const TMap<FName, FName>& GetPropertyLUT() const override;
};


UCLASS(BlueprintType)
class VENLY_API UVyContractDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyContractDtoRef* ToObject(const FVyContractDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyContractDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyContractDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyContractDto Data{};
};