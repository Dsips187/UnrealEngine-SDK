#include "AutoGen/Wallet/VyNode_Wallet_ExportWallet.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyExportWallet_Wallet.h"
UClass* UVyNode_Wallet_ExportWallet::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_ExportWallet::GetResponseType() const
{
	return FVyExportWalletResponse::StaticStruct();
}

FName UVyNode_Wallet_ExportWallet::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_ExportWallet::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, ExportWallet);
}

FName UVyNode_Wallet_ExportWallet::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_ExportWallet::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_ExportWallet::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
