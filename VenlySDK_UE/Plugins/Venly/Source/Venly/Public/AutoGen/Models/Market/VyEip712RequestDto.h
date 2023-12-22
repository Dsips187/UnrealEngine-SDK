#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/Models/Market/VyEip712MessageDto.h"
#include "AutoGen/Models/Market/VyEip712DomainDto.h"
#include "VyEip712RequestDto.generated.h"

/*
* Request parameters for EIP712 request
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyEip712RequestDto : public FVyDTO
{
	GENERATED_BODY()
	/**Types of the EIP712 request*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Types;
	/**Domain information for the EIP712 request*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyEip712DomainDto Domain;
	/**Primary type of the EIP712 request*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString PrimaryType;
	/**Message for the EIP712 request*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyEip712MessageDto Message;
};


UCLASS(BlueprintType)
class VENLY_API UVyEip712RequestDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyEip712RequestDtoRef* ToObject(const FVyEip712RequestDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyEip712RequestDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyEip712RequestDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyEip712RequestDto Data{};
};