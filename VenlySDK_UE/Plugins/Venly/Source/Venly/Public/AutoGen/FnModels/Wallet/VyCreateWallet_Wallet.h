#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/VyEnums_generated.h"
#include "AutoGen/Models/Wallet/VyWalletDto.h"

#include "VyCreateWallet_Wallet.generated.h"


//REQUEST [CreateWalletRequest]
/*
* Request parameters to create a wallet
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyCreateWalletRequest : public FVyDTO
{
	GENERATED_BODY()
	/**Identifier of the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString Identifier;
	/**Pincode to access the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Pincode;
	/**A description for the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString Description;
	/**The preferred blockchain for the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyChain Chain;
	/**(read-only) The wallet type, should be "API_WALLET"*/
	UPROPERTY(BlueprintReadOnly, Category="Venly") FString WalletType{TEXT("API_WALLET")};
	
	virtual ~FVyCreateWalletRequest() = default;
	virtual bool HasPropertyLUT() const override { return true; }
	virtual const TMap<FName, FName>& GetPropertyLUT() const override;
};


UCLASS(BlueprintType)
class VENLY_API UVyCreateWalletRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyCreateWalletRequestRef* ToObject(const FVyCreateWalletRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyCreateWalletRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyCreateWalletRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyCreateWalletRequest Data{};
};
//RESPONSE [ViewWalletResult]
USTRUCT(BlueprintType)
struct VENLY_API FVyCreateWalletResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyWalletDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnCreateWalletCompleteBP, FVyCreateWalletResponse, Result);
