#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/VyEnums_generated.h"
#include "VyCompanyWalletDto.generated.h"

/*
* Company wallet data transfer object
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyCompanyWalletDto : public FVyDTO
{
	GENERATED_BODY()
	/**The type of the company wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyCompanyWalletType Type;
	/**The ID of the company*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString CompanyId;
	/**The address of the company wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Address;
	/**The ID of the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString WalletId;
	/**The ID of the company wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Id;
	/**The preferred blockchain for the company wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyChain Chain;
};


UCLASS(BlueprintType)
class VENLY_API UVyCompanyWalletDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyCompanyWalletDtoRef* ToObject(const FVyCompanyWalletDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyCompanyWalletDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyCompanyWalletDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyCompanyWalletDto Data{};
};