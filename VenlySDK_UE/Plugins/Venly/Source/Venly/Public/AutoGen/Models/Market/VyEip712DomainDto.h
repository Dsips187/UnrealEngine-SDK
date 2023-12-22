#pragma once
#include "Models/VyCoreModels.h"

#include "VyEip712DomainDto.generated.h"

/*
* Data transfer object for Eip712Domain
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyEip712DomainDto : public FVyDTO
{
	GENERATED_BODY()
	/**The name of the domain*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Name;
	/**The version of the domain*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Version;
	/**The verifying contract of the domain*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString VerifyingContract;
	/**The salt of the domain*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Salt;
};


UCLASS(BlueprintType)
class VENLY_API UVyEip712DomainDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyEip712DomainDtoRef* ToObject(const FVyEip712DomainDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyEip712DomainDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyEip712DomainDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyEip712DomainDto Data{};
};