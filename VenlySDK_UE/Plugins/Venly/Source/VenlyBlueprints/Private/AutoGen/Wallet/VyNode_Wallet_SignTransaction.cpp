#include "AutoGen/Wallet/VyNode_Wallet_SignTransaction.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VySignTransaction_Wallet.h"
UClass* UVyNode_Wallet_SignTransaction::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_SignTransaction::GetResponseType() const
{
	return FVySignTransactionResponse::StaticStruct();
}

FName UVyNode_Wallet_SignTransaction::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_SignTransaction::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, SignTransaction);
}

FName UVyNode_Wallet_SignTransaction::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_SignTransaction::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_SignTransaction::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
