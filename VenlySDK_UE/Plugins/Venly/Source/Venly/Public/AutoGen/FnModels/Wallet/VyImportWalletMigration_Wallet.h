#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Optionals/VyOptWalletImportType.h"
#include "AutoGen/Optionals/VyOptWalletType.h"
#include "AutoGen/Optionals/VyOptChain.h"
#include "AutoGen/Models/Wallet/VyWalletDto.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/Optionals/VyOptStringArray.h"

#include "VyImportWalletMigration_Wallet.generated.h"


//REQUEST [migrationWalletImport]
/*
* Request parameters for importing a wallet during migration
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyMigrationWalletImportRequest : public FVyDTO
{
	GENERATED_BODY()
	/**Identifier of the wallet to be imported*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString WalletId;
	/**The preferred blockchain for the imported wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptChain To;
	/**The type of the wallet to be imported*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptWalletImportType ImportWalletType;
	/**The type of the imported wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptWalletType WalletType;
	/**Pincode to access the imported wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString Pincode;
	/**Array of clients associated with the imported wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptStringArray Clients;
};


UCLASS(BlueprintType)
class VENLY_API UVyMigrationWalletImportRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyMigrationWalletImportRequestRef* ToObject(const FVyMigrationWalletImportRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyMigrationWalletImportRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyMigrationWalletImportRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyMigrationWalletImportRequest Data{};
};
//RESPONSE [ViewWalletResult]
USTRUCT(BlueprintType)
struct VENLY_API FVyImportWalletMigrationResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyWalletDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnImportWalletMigrationCompleteBP, FVyImportWalletMigrationResponse, Result);
