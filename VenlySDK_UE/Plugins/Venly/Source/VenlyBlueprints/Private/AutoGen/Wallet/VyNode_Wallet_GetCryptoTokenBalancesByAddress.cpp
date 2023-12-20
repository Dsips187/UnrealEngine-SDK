#include "AutoGen/Wallet/VyNode_Wallet_GetCryptoTokenBalancesByAddress.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyGetCryptoTokenBalancesByAddress_Wallet.h"
UClass* UVyNode_Wallet_GetCryptoTokenBalancesByAddress::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_GetCryptoTokenBalancesByAddress::GetResponseType() const
{
	return FVyGetCryptoTokenBalancesByAddressResponse::StaticStruct();
}

FName UVyNode_Wallet_GetCryptoTokenBalancesByAddress::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_GetCryptoTokenBalancesByAddress::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, GetCryptoTokenBalancesByAddress);
}

FName UVyNode_Wallet_GetCryptoTokenBalancesByAddress::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_GetCryptoTokenBalancesByAddress::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_GetCryptoTokenBalancesByAddress::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
