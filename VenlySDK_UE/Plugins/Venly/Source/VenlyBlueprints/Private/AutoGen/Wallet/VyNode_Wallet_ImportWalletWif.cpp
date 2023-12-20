#include "AutoGen/Wallet/VyNode_Wallet_ImportWalletWif.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyImportWalletWif_Wallet.h"
UClass* UVyNode_Wallet_ImportWalletWif::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_ImportWalletWif::GetResponseType() const
{
	return FVyImportWalletWifResponse::StaticStruct();
}

FName UVyNode_Wallet_ImportWalletWif::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_ImportWalletWif::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, ImportWalletWif);
}

FName UVyNode_Wallet_ImportWalletWif::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_ImportWalletWif::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_ImportWalletWif::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
