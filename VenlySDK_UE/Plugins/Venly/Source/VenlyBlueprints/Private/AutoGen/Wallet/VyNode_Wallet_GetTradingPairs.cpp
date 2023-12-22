#include "AutoGen/Wallet/VyNode_Wallet_GetTradingPairs.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyGetTradingPairs_Wallet.h"
UClass* UVyNode_Wallet_GetTradingPairs::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_GetTradingPairs::GetResponseType() const
{
	return FVyGetTradingPairsResponse::StaticStruct();
}

FName UVyNode_Wallet_GetTradingPairs::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_GetTradingPairs::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, GetTradingPairs);
}

FName UVyNode_Wallet_GetTradingPairs::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_GetTradingPairs::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_GetTradingPairs::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
