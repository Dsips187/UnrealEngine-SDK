#pragma once
#include "Models/VyCoreModels.h"

#include "VyWalletKeystoreDto.generated.h"

/*
* A data transfer object representing a wallet keystore
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyWalletKeystoreDto : public FVyDTO
{
	GENERATED_BODY()
	/**The keystore of the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Keystore;
};


UCLASS(BlueprintType)
class VENLY_API UVyWalletKeystoreDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyWalletKeystoreDtoRef* ToObject(const FVyWalletKeystoreDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyWalletKeystoreDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyWalletKeystoreDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyWalletKeystoreDto Data{};
};