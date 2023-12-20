#include "AutoGen/Wallet/VyNode_Wallet_GetMultiTokenBalancesByAddress.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyGetMultiTokenBalancesByAddress_Wallet.h"
UClass* UVyNode_Wallet_GetMultiTokenBalancesByAddress::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_GetMultiTokenBalancesByAddress::GetResponseType() const
{
	return FVyGetMultiTokenBalancesByAddressResponse::StaticStruct();
}

FName UVyNode_Wallet_GetMultiTokenBalancesByAddress::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_GetMultiTokenBalancesByAddress::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, GetMultiTokenBalancesByAddress);
}

FName UVyNode_Wallet_GetMultiTokenBalancesByAddress::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_GetMultiTokenBalancesByAddress::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_GetMultiTokenBalancesByAddress::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
