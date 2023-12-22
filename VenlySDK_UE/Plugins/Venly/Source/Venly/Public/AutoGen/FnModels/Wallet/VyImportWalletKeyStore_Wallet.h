#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Optionals/VyOptWalletImportType.h"
#include "AutoGen/Optionals/VyOptWalletType.h"
#include "AutoGen/Models/Wallet/VyWalletDto.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/Optionals/VyOptStringArray.h"

#include "VyImportWalletKeyStore_Wallet.generated.h"


//REQUEST [keystorePasswordWalletImport]
/*
* Request parameters to import a wallet using a keystore file and password
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyKeystorePasswordWalletImportRequest : public FVyDTO
{
	GENERATED_BODY()
	/**The keystore file contents*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString Keystore;
	/**The password to decrypt the keystore file*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString Password;
	/**The type of wallet to import*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptWalletImportType ImportWalletType;
	/**The type of wallet to create*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptWalletType WalletType;
	/**Pincode to access the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString Pincode;
	/**An array of client names*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptStringArray Clients;
};


UCLASS(BlueprintType)
class VENLY_API UVyKeystorePasswordWalletImportRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyKeystorePasswordWalletImportRequestRef* ToObject(const FVyKeystorePasswordWalletImportRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyKeystorePasswordWalletImportRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyKeystorePasswordWalletImportRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyKeystorePasswordWalletImportRequest Data{};
};
//RESPONSE [ViewWalletResult]
USTRUCT(BlueprintType)
struct VENLY_API FVyImportWalletKeyStoreResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyWalletDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnImportWalletKeyStoreCompleteBP, FVyImportWalletKeyStoreResponse, Result);
