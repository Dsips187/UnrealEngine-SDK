#include "AutoGen/Wallet/VyNode_Wallet_IsValidSignature.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyIsValidSignature_Wallet.h"
UClass* UVyNode_Wallet_IsValidSignature::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_IsValidSignature::GetResponseType() const
{
	return FVyIsValidSignatureResponse::StaticStruct();
}

FName UVyNode_Wallet_IsValidSignature::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_IsValidSignature::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, IsValidSignature);
}

FName UVyNode_Wallet_IsValidSignature::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_IsValidSignature::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_IsValidSignature::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
