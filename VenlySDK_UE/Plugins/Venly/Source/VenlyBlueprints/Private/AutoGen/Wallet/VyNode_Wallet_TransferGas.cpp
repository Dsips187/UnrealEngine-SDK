#include "AutoGen/Wallet/VyNode_Wallet_TransferGas.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyTransferGas_Wallet.h"
UClass* UVyNode_Wallet_TransferGas::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_TransferGas::GetResponseType() const
{
	return FVyTransferGasResponse::StaticStruct();
}

FName UVyNode_Wallet_TransferGas::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_TransferGas::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, TransferGas);
}

FName UVyNode_Wallet_TransferGas::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_TransferGas::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_TransferGas::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
