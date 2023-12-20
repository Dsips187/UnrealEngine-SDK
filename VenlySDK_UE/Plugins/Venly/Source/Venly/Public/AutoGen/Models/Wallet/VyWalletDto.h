#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/VyEnums_generated.h"
#include "AutoGen/Models/Wallet/VyNativeTokenDto.h"
#include "VyWalletDto.generated.h"

/*
* Data structure representing a wallet
*/
USTRUCT(BlueprintType)
struct FVyWalletDto : public FVyDTO
{
	GENERATED_BODY()
	/**The unique identifier of the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Id;
	/**The address of the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Address;
	/**The blockchain the wallet belongs to*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyChain Chain;
	/**The type of the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyWalletType WalletType;
	/**Indicates if the wallet is archived*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") bool Archived;
	/**The description of the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Description;
	/**The creation date of the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FDateTime CreatedAt;
	/**Indicates if the wallet is the primary wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") bool IsPrimary;
	/**Indicates if the wallet has a customer PIN*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") bool HasCustomerPin;
	/**The identifier of the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Identifier;
	/**The balance of the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyNativeTokenDto Balance;
	
	virtual ~FVyWalletDto() = default;
	virtual bool HasPropertyLUT() const override { return true; }
	virtual const TMap<FName, FName>& GetPropertyLUT() const override;
};


UCLASS(BlueprintType)
class UVyWalletDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyWalletDtoRef* ToObject(const FVyWalletDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyWalletDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyWalletDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyWalletDto Data{};
};