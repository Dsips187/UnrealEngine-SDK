#include "AutoGen/Wallet/VyNode_Wallet_ImportWalletMigration.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyImportWalletMigration_Wallet.h"
UClass* UVyNode_Wallet_ImportWalletMigration::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_ImportWalletMigration::GetResponseType() const
{
	return FVyImportWalletMigrationResponse::StaticStruct();
}

FName UVyNode_Wallet_ImportWalletMigration::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_ImportWalletMigration::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, ImportWalletMigration);
}

FName UVyNode_Wallet_ImportWalletMigration::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_ImportWalletMigration::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_ImportWalletMigration::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
