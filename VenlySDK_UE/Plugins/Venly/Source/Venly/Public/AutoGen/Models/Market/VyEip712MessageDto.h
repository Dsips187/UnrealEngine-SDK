#pragma once
#include "Models/VyCoreModels.h"

#include "VyEip712MessageDto.generated.h"

/*
* Data transfer object for an EIP712 message
*/
USTRUCT(BlueprintType)
struct FVyEip712MessageDto : public FVyDTO
{
	GENERATED_BODY()
	/**The nonce value*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") int Nonce;
	/**The sender's address*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString From;
	/**The function signature*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString FunctionSignature;
};


UCLASS(BlueprintType)
class UVyEip712MessageDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyEip712MessageDtoRef* ToObject(const FVyEip712MessageDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyEip712MessageDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyEip712MessageDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyEip712MessageDto Data{};
};