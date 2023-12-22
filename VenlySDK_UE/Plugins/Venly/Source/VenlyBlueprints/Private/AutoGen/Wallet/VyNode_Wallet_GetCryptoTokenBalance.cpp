#include "AutoGen/Wallet/VyNode_Wallet_GetCryptoTokenBalance.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyGetCryptoTokenBalance_Wallet.h"
UClass* UVyNode_Wallet_GetCryptoTokenBalance::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_GetCryptoTokenBalance::GetResponseType() const
{
	return FVyGetCryptoTokenBalanceResponse::StaticStruct();
}

FName UVyNode_Wallet_GetCryptoTokenBalance::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_GetCryptoTokenBalance::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, GetCryptoTokenBalance);
}

FName UVyNode_Wallet_GetCryptoTokenBalance::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_GetCryptoTokenBalance::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_GetCryptoTokenBalance::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
