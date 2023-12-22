#include "AutoGen/Wallet/VyNode_Wallet_GetSupportedWalletChains.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyGetSupportedWalletChains_Wallet.h"
UClass* UVyNode_Wallet_GetSupportedWalletChains::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_GetSupportedWalletChains::GetResponseType() const
{
	return FVyGetSupportedWalletChainsResponse::StaticStruct();
}

FName UVyNode_Wallet_GetSupportedWalletChains::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_GetSupportedWalletChains::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, GetSupportedWalletChains);
}

FName UVyNode_Wallet_GetSupportedWalletChains::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_GetSupportedWalletChains::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_GetSupportedWalletChains::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
