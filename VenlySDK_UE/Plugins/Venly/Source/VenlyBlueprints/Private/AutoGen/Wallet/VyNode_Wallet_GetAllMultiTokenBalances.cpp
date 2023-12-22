#include "AutoGen/Wallet/VyNode_Wallet_GetAllMultiTokenBalances.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyGetAllMultiTokenBalances_Wallet.h"
UClass* UVyNode_Wallet_GetAllMultiTokenBalances::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_GetAllMultiTokenBalances::GetResponseType() const
{
	return FVyGetAllMultiTokenBalancesResponse::StaticStruct();
}

FName UVyNode_Wallet_GetAllMultiTokenBalances::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_GetAllMultiTokenBalances::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, GetAllMultiTokenBalances);
}

FName UVyNode_Wallet_GetAllMultiTokenBalances::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_GetAllMultiTokenBalances::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_GetAllMultiTokenBalances::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
