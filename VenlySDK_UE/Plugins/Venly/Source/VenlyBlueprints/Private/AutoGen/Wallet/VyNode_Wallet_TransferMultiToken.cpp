#include "AutoGen/Wallet/VyNode_Wallet_TransferMultiToken.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyTransferMultiToken_Wallet.h"
UClass* UVyNode_Wallet_TransferMultiToken::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_TransferMultiToken::GetResponseType() const
{
	return FVyTransferMultiTokenResponse::StaticStruct();
}

FName UVyNode_Wallet_TransferMultiToken::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_TransferMultiToken::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, TransferMultiToken);
}

FName UVyNode_Wallet_TransferMultiToken::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_TransferMultiToken::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_TransferMultiToken::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
