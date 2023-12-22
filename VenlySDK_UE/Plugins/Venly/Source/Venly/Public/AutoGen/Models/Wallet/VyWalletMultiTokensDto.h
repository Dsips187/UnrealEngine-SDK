#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/Models/Shared/VyMultiTokenDto.h"
#include "AutoGen/VyEnums_generated.h"
#include "VyWalletMultiTokensDto.generated.h"

/*
* A DTO representing a wallet with multiple tokens
*/
USTRUCT(BlueprintType)
struct FVyWalletMultiTokensDto : public FVyDTO
{
	GENERATED_BODY()
	/**The ID of the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString WalletId;
	/**The address of the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString WalletAddress;
	/**The type of the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyWalletType WalletType;
	/**The preferred blockchain for the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyChain Chain;
	/**An array of multi tokens in the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") TArray<FVyMultiTokenDto> Items;
	
	virtual ~FVyWalletMultiTokensDto() = default;
	virtual bool HasPropertyLUT() const override { return true; }
	virtual const TMap<FName, FName>& GetPropertyLUT() const override;
};


UCLASS(BlueprintType)
class UVyWalletMultiTokensDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyWalletMultiTokensDtoRef* ToObject(const FVyWalletMultiTokensDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyWalletMultiTokensDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyWalletMultiTokensDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyWalletMultiTokensDto Data{};
};