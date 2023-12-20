#include "AutoGen/Wallet/VyNode_Wallet_TransferNativeToken.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyTransferNativeToken_Wallet.h"
UClass* UVyNode_Wallet_TransferNativeToken::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_TransferNativeToken::GetResponseType() const
{
	return FVyTransferNativeTokenResponse::StaticStruct();
}

FName UVyNode_Wallet_TransferNativeToken::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_TransferNativeToken::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, TransferNativeToken);
}

FName UVyNode_Wallet_TransferNativeToken::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_TransferNativeToken::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_TransferNativeToken::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
