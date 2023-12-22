#include "AutoGen/Wallet/VyNode_Wallet_ImportWalletKeyStore.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyImportWalletKeyStore_Wallet.h"
UClass* UVyNode_Wallet_ImportWalletKeyStore::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_ImportWalletKeyStore::GetResponseType() const
{
	return FVyImportWalletKeyStoreResponse::StaticStruct();
}

FName UVyNode_Wallet_ImportWalletKeyStore::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_ImportWalletKeyStore::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, ImportWalletKeyStore);
}

FName UVyNode_Wallet_ImportWalletKeyStore::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_ImportWalletKeyStore::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_ImportWalletKeyStore::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
