#include "AutoGen/Wallet/VyNode_Wallet_IsValidWalletAddress.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyIsValidWalletAddress_Wallet.h"
UClass* UVyNode_Wallet_IsValidWalletAddress::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_IsValidWalletAddress::GetResponseType() const
{
	return FVyIsValidWalletAddressResponse::StaticStruct();
}

FName UVyNode_Wallet_IsValidWalletAddress::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_IsValidWalletAddress::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, IsValidWalletAddress);
}

FName UVyNode_Wallet_IsValidWalletAddress::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_IsValidWalletAddress::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_IsValidWalletAddress::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
