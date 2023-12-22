#include "AutoGen/Wallet/VyNode_Wallet_GetWalletEvents.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyGetWalletEvents_Wallet.h"
UClass* UVyNode_Wallet_GetWalletEvents::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_GetWalletEvents::GetResponseType() const
{
	return FVyGetWalletEventsResponse::StaticStruct();
}

FName UVyNode_Wallet_GetWalletEvents::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_GetWalletEvents::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, GetWalletEvents);
}

FName UVyNode_Wallet_GetWalletEvents::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_GetWalletEvents::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_GetWalletEvents::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
