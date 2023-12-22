#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/Models/Wallet/VyWalletKeystoreDto.h"

#include "VyExportWallet_Wallet.generated.h"


//REQUEST [exportWallet]
/*
* Request parameters to export a wallet
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyExportWalletRequest : public FVyDTO
{
	GENERATED_BODY()
	/**Identifier of the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString WalletId;
	/**Pincode to access the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Pincode;
	/**Password to encrypt the exported wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Password;
};


UCLASS(BlueprintType)
class VENLY_API UVyExportWalletRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyExportWalletRequestRef* ToObject(const FVyExportWalletRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyExportWalletRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyExportWalletRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyExportWalletRequest Data{};
};
//RESPONSE [ExportedWalletDto]
USTRUCT(BlueprintType)
struct VENLY_API FVyExportWalletResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyWalletKeystoreDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnExportWalletCompleteBP, FVyExportWalletResponse, Result);
