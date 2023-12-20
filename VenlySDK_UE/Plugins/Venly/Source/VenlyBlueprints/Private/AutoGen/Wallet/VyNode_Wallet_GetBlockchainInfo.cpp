#include "AutoGen/Wallet/VyNode_Wallet_GetBlockchainInfo.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyGetBlockchainInfo_Wallet.h"
UClass* UVyNode_Wallet_GetBlockchainInfo::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_GetBlockchainInfo::GetResponseType() const
{
	return FVyGetBlockchainInfoResponse::StaticStruct();
}

FName UVyNode_Wallet_GetBlockchainInfo::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_GetBlockchainInfo::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, GetBlockchainInfo);
}

FName UVyNode_Wallet_GetBlockchainInfo::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_GetBlockchainInfo::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_GetBlockchainInfo::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
