#include "AutoGen/Wallet/VyNode_Wallet_GetCryptoTokenBalanceByAddress.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyGetCryptoTokenBalanceByAddress_Wallet.h"
UClass* UVyNode_Wallet_GetCryptoTokenBalanceByAddress::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_GetCryptoTokenBalanceByAddress::GetResponseType() const
{
	return FVyGetCryptoTokenBalanceByAddressResponse::StaticStruct();
}

FName UVyNode_Wallet_GetCryptoTokenBalanceByAddress::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_GetCryptoTokenBalanceByAddress::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, GetCryptoTokenBalanceByAddress);
}

FName UVyNode_Wallet_GetCryptoTokenBalanceByAddress::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_GetCryptoTokenBalanceByAddress::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_GetCryptoTokenBalanceByAddress::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
