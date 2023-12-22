#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/Models/Wallet/VyWalletDto.h"
#include "AutoGen/Optionals/VyOptWalletImportType.h"
#include "AutoGen/Optionals/VyOptStringArray.h"
#include "AutoGen/Optionals/VyOptWalletType.h"

#include "VyImportWalletWif_Wallet.generated.h"


//REQUEST [wifWalletImport]
/*
* Request parameters to import a WIF wallet
*/
USTRUCT(BlueprintType)
struct FVyWifWalletImportRequest : public FVyDTO
{
	GENERATED_BODY()
	/**The WIF (Wallet Import Format) key*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString Wif;
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
class UVyWifWalletImportRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyWifWalletImportRequestRef* ToObject(const FVyWifWalletImportRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyWifWalletImportRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyWifWalletImportRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyWifWalletImportRequest Data{};
};
//RESPONSE [ViewWalletResult]
USTRUCT(BlueprintType)
struct FVyImportWalletWifResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyWalletDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnImportWalletWifCompleteBP, FVyImportWalletWifResponse, Result);
