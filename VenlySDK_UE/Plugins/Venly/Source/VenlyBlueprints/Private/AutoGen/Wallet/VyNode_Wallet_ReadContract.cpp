#include "AutoGen/Wallet/VyNode_Wallet_ReadContract.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyReadContract_Wallet.h"
UClass* UVyNode_Wallet_ReadContract::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_ReadContract::GetResponseType() const
{
	return FVyReadContractResponse::StaticStruct();
}

FName UVyNode_Wallet_ReadContract::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_ReadContract::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, ReadContract);
}

FName UVyNode_Wallet_ReadContract::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_ReadContract::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_ReadContract::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
