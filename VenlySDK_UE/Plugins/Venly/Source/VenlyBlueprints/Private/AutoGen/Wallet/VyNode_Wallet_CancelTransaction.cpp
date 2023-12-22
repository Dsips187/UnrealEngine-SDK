#include "AutoGen/Wallet/VyNode_Wallet_CancelTransaction.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyCancelTransaction_Wallet.h"
UClass* UVyNode_Wallet_CancelTransaction::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_CancelTransaction::GetResponseType() const
{
	return FVyCancelTransactionResponse::StaticStruct();
}

FName UVyNode_Wallet_CancelTransaction::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_CancelTransaction::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, CancelTransaction);
}

FName UVyNode_Wallet_CancelTransaction::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_CancelTransaction::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_CancelTransaction::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
