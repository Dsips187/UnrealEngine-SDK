#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/Models/Shared/VyTypeValueDto.h"
#include "VyMultiTokenContractDto.generated.h"

/*
* Data transfer object for a multi-token contract
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyMultiTokenContractDto : public FVyDTO
{
	GENERATED_BODY()
	/**The name of the multi-token contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Name;
	/**The description of the multi-token contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Description;
	/**The address of the multi-token contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Address;
	/**The symbol of the multi-token contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Symbol;
	/**The media associated with the multi-token contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") TArray<FVyTypeValueDto> Media;
	/**The type of the multi-token contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Type;
	/**Indicates if the multi-token contract is verified*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") bool Verified;
	/**Indicates if the multi-token contract is premium*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") bool Premium;
	/**The categories associated with the multi-token contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") TArray<FString> Categories;
	/**The URL of the multi-token contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Url;
	/**The image URL of the multi-token contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ImageUrl;
	/**The external URL of the multi-token contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ExternalUrl;
};


UCLASS(BlueprintType)
class VENLY_API UVyMultiTokenContractDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyMultiTokenContractDtoRef* ToObject(const FVyMultiTokenContractDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyMultiTokenContractDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyMultiTokenContractDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyMultiTokenContractDto Data{};
};