#include "AutoGen/Wallet/VyNode_Wallet_GetExchangeRate.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyGetExchangeRate_Wallet.h"
UClass* UVyNode_Wallet_GetExchangeRate::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_GetExchangeRate::GetResponseType() const
{
	return FVyGetExchangeRateResponse::StaticStruct();
}

FName UVyNode_Wallet_GetExchangeRate::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_GetExchangeRate::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, GetExchangeRate);
}

FName UVyNode_Wallet_GetExchangeRate::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_GetExchangeRate::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_GetExchangeRate::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
