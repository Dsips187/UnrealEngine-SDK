#include "AutoGen/Wallet/VyNode_Wallet_GetTransactionFees.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyGetTransactionFees_Wallet.h"
UClass* UVyNode_Wallet_GetTransactionFees::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_GetTransactionFees::GetResponseType() const
{
	return FVyGetTransactionFeesResponse::StaticStruct();
}

FName UVyNode_Wallet_GetTransactionFees::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_GetTransactionFees::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, GetTransactionFees);
}

FName UVyNode_Wallet_GetTransactionFees::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_GetTransactionFees::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_GetTransactionFees::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
