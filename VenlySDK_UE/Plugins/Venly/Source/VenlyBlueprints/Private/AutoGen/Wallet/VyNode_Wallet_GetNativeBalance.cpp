#include "AutoGen/Wallet/VyNode_Wallet_GetNativeBalance.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyGetNativeBalance_Wallet.h"
UClass* UVyNode_Wallet_GetNativeBalance::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_GetNativeBalance::GetResponseType() const
{
	return FVyGetNativeBalanceResponse::StaticStruct();
}

FName UVyNode_Wallet_GetNativeBalance::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_GetNativeBalance::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, GetNativeBalance);
}

FName UVyNode_Wallet_GetNativeBalance::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_GetNativeBalance::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_GetNativeBalance::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
