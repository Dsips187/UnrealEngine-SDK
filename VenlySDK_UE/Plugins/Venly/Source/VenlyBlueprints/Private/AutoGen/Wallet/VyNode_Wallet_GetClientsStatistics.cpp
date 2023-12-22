#include "AutoGen/Wallet/VyNode_Wallet_GetClientsStatistics.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyGetClientsStatistics_Wallet.h"
UClass* UVyNode_Wallet_GetClientsStatistics::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_GetClientsStatistics::GetResponseType() const
{
	return FVyGetClientsStatisticsResponse::StaticStruct();
}

FName UVyNode_Wallet_GetClientsStatistics::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_GetClientsStatistics::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, GetClientsStatistics);
}

FName UVyNode_Wallet_GetClientsStatistics::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_GetClientsStatistics::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_GetClientsStatistics::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
