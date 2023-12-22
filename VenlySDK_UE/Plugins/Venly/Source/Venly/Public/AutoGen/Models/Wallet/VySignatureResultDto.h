#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/VyEnums_generated.h"
#include "VySignatureResultDto.generated.h"

/*
* Result of a signature operation
*/
USTRUCT(BlueprintType)
struct VENLY_API FVySignatureResultDto : public FVyDTO
{
	GENERATED_BODY()
	/**The type of the signature*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVySignatureType Type;
	/**The R value of the signature*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString R;
	/**The V value of the signature*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString V;
	/**The hash of the transaction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString TransactionHash;
	/**Details of the transaction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString TransactionDetails;
	/**The signature*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Signature;
	/**The signed transaction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString SignedTransaction;
	/**The S value of the signature*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString S;
};


UCLASS(BlueprintType)
class VENLY_API UVySignatureResultDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVySignatureResultDtoRef* ToObject(const FVySignatureResultDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVySignatureResultDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVySignatureResultDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVySignatureResultDto Data{};
};