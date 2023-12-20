#include "AutoGen/Wallet/VyNode_Wallet_ImportWalletPrivateKey.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyImportWalletPrivateKey_Wallet.h"
UClass* UVyNode_Wallet_ImportWalletPrivateKey::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_ImportWalletPrivateKey::GetResponseType() const
{
	return FVyImportWalletPrivateKeyResponse::StaticStruct();
}

FName UVyNode_Wallet_ImportWalletPrivateKey::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_ImportWalletPrivateKey::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, ImportWalletPrivateKey);
}

FName UVyNode_Wallet_ImportWalletPrivateKey::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_ImportWalletPrivateKey::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_ImportWalletPrivateKey::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
