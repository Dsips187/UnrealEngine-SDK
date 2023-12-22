#include "AutoGen/Wallet/VyNode_Wallet_TransferCryptoToken.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyTransferCryptoToken_Wallet.h"
UClass* UVyNode_Wallet_TransferCryptoToken::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_TransferCryptoToken::GetResponseType() const
{
	return FVyTransferCryptoTokenResponse::StaticStruct();
}

FName UVyNode_Wallet_TransferCryptoToken::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_TransferCryptoToken::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, TransferCryptoToken);
}

FName UVyNode_Wallet_TransferCryptoToken::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_TransferCryptoToken::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_TransferCryptoToken::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
