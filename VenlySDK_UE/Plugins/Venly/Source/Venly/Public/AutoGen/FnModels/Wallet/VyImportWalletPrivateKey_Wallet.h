#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/Models/Wallet/VyWalletDto.h"
#include "AutoGen/Optionals/VyOptWalletImportType.h"
#include "AutoGen/Optionals/VyOptStringArray.h"
#include "AutoGen/Optionals/VyOptWalletType.h"

#include "VyImportWalletPrivateKey_Wallet.generated.h"


//REQUEST [privateKeyWalletImport]
/*
* Request parameters to import a private key wallet
*/
USTRUCT(BlueprintType)
struct FVyPrivateKeyWalletImportRequest : public FVyDTO
{
	GENERATED_BODY()
	/**The private key of the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString PrivateKey;
	/**The type of wallet import*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptWalletImportType ImportWalletType;
	/**The type of wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptWalletType WalletType;
	/**Pincode to access the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString Pincode;
	/**An array of client names*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptStringArray Clients;
};


UCLASS(BlueprintType)
class UVyPrivateKeyWalletImportRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyPrivateKeyWalletImportRequestRef* ToObject(const FVyPrivateKeyWalletImportRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyPrivateKeyWalletImportRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyPrivateKeyWalletImportRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyPrivateKeyWalletImportRequest Data{};
};
//RESPONSE [ViewWalletResult]
USTRUCT(BlueprintType)
struct FVyImportWalletPrivateKeyResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyWalletDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnImportWalletPrivateKeyCompleteBP, FVyImportWalletPrivateKeyResponse, Result);
