#include "AutoGen/Wallet/VyNode_Wallet_GetWallets.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyGetWallets_Wallet.h"
UClass* UVyNode_Wallet_GetWallets::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_GetWallets::GetResponseType() const
{
	return FVyGetWalletsResponse::StaticStruct();
}

FName UVyNode_Wallet_GetWallets::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_GetWallets::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, GetWallets);
}

FName UVyNode_Wallet_GetWallets::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_GetWallets::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_GetWallets::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
