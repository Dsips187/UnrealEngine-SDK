#include "AutoGen/Wallet/VyNode_Wallet_GetMultiTokenBalances.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyGetMultiTokenBalances_Wallet.h"
UClass* UVyNode_Wallet_GetMultiTokenBalances::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_GetMultiTokenBalances::GetResponseType() const
{
	return FVyGetMultiTokenBalancesResponse::StaticStruct();
}

FName UVyNode_Wallet_GetMultiTokenBalances::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_GetMultiTokenBalances::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, GetMultiTokenBalances);
}

FName UVyNode_Wallet_GetMultiTokenBalances::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_GetMultiTokenBalances::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_GetMultiTokenBalances::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
