#include "AutoGen/Wallet/VyNode_Wallet_GetCryptoTokenBalances.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyGetCryptoTokenBalances_Wallet.h"
UClass* UVyNode_Wallet_GetCryptoTokenBalances::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_GetCryptoTokenBalances::GetResponseType() const
{
	return FVyGetCryptoTokenBalancesResponse::StaticStruct();
}

FName UVyNode_Wallet_GetCryptoTokenBalances::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_GetCryptoTokenBalances::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, GetCryptoTokenBalances);
}

FName UVyNode_Wallet_GetCryptoTokenBalances::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_GetCryptoTokenBalances::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_GetCryptoTokenBalances::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
