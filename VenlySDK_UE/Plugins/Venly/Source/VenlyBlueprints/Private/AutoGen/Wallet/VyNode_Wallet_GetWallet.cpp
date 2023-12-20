#include "AutoGen/Wallet/VyNode_Wallet_GetWallet.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyGetWallet_Wallet.h"
UClass* UVyNode_Wallet_GetWallet::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_GetWallet::GetResponseType() const
{
	return FVyGetWalletResponse::StaticStruct();
}

FName UVyNode_Wallet_GetWallet::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_GetWallet::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, GetWallet);
}

FName UVyNode_Wallet_GetWallet::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_GetWallet::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_GetWallet::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
