#include "AutoGen/Wallet/VyNode_Wallet_CreateWallet.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyCreateWallet_Wallet.h"
UClass* UVyNode_Wallet_CreateWallet::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_CreateWallet::GetResponseType() const
{
	return FVyCreateWalletResponse::StaticStruct();
}

FName UVyNode_Wallet_CreateWallet::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_CreateWallet::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, CreateWallet);
}

FName UVyNode_Wallet_CreateWallet::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_CreateWallet::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_CreateWallet::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
