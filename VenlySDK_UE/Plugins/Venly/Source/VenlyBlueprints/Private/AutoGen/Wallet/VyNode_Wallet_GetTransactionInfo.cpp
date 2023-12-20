#include "AutoGen/Wallet/VyNode_Wallet_GetTransactionInfo.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyGetTransactionInfo_Wallet.h"
UClass* UVyNode_Wallet_GetTransactionInfo::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_GetTransactionInfo::GetResponseType() const
{
	return FVyGetTransactionInfoResponse::StaticStruct();
}

FName UVyNode_Wallet_GetTransactionInfo::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_GetTransactionInfo::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, GetTransactionInfo);
}

FName UVyNode_Wallet_GetTransactionInfo::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_GetTransactionInfo::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_GetTransactionInfo::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
