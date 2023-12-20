#include "AutoGen/Wallet/VyNode_Wallet_ExecuteContract.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyExecuteContract_Wallet.h"
UClass* UVyNode_Wallet_ExecuteContract::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_ExecuteContract::GetResponseType() const
{
	return FVyExecuteContractResponse::StaticStruct();
}

FName UVyNode_Wallet_ExecuteContract::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_ExecuteContract::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, ExecuteContract);
}

FName UVyNode_Wallet_ExecuteContract::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_ExecuteContract::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_ExecuteContract::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
