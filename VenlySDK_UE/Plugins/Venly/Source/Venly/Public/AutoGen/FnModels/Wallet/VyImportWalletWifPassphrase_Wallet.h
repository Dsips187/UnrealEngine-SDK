#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Optionals/VyOptWalletImportType.h"
#include "AutoGen/Optionals/VyOptWalletType.h"
#include "AutoGen/Models/Wallet/VyWalletDto.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/Optionals/VyOptStringArray.h"

#include "VyImportWalletWifPassphrase_Wallet.generated.h"


//REQUEST [wifPassphraseImport]
/*
* Request parameters to import a wallet using WIF and passphrase
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyWifPassphraseImportRequest : public FVyDTO
{
	GENERATED_BODY()
	/**The WIF (Wallet Import Format) key*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString Wif;
	/**The passphrase to encrypt the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString Passphrase;
	/**The type of wallet to import*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptWalletImportType ImportWalletType;
	/**The type of wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptWalletType WalletType;
	/**Pincode to access the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString Pincode;
	/**An array of client names*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptStringArray Clients;
};


UCLASS(BlueprintType)
class VENLY_API UVyWifPassphraseImportRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyWifPassphraseImportRequestRef* ToObject(const FVyWifPassphraseImportRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyWifPassphraseImportRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyWifPassphraseImportRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyWifPassphraseImportRequest Data{};
};
//RESPONSE [ViewWalletResult]
USTRUCT(BlueprintType)
struct VENLY_API FVyImportWalletWifPassphraseResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyWalletDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnImportWalletWifPassphraseCompleteBP, FVyImportWalletWifPassphraseResponse, Result);
