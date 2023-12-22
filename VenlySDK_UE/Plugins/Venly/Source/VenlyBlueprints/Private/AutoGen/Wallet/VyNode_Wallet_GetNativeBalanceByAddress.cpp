#include "AutoGen/Wallet/VyNode_Wallet_GetNativeBalanceByAddress.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyGetNativeBalanceByAddress_Wallet.h"
UClass* UVyNode_Wallet_GetNativeBalanceByAddress::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_GetNativeBalanceByAddress::GetResponseType() const
{
	return FVyGetNativeBalanceByAddressResponse::StaticStruct();
}

FName UVyNode_Wallet_GetNativeBalanceByAddress::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_GetNativeBalanceByAddress::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, GetNativeBalanceByAddress);
}

FName UVyNode_Wallet_GetNativeBalanceByAddress::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_GetNativeBalanceByAddress::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_GetNativeBalanceByAddress::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
