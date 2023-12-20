#include "AutoGen/Wallet/VyNode_Wallet_ImportWalletWifPassphrase.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyImportWalletWifPassphrase_Wallet.h"
UClass* UVyNode_Wallet_ImportWalletWifPassphrase::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_ImportWalletWifPassphrase::GetResponseType() const
{
	return FVyImportWalletWifPassphraseResponse::StaticStruct();
}

FName UVyNode_Wallet_ImportWalletWifPassphrase::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_ImportWalletWifPassphrase::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, ImportWalletWifPassphrase);
}

FName UVyNode_Wallet_ImportWalletWifPassphrase::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_ImportWalletWifPassphrase::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_ImportWalletWifPassphrase::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
