#include "AutoGen/Wallet/VyNode_Wallet_UpdateSecurity.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyUpdateSecurity_Wallet.h"
UClass* UVyNode_Wallet_UpdateSecurity::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_UpdateSecurity::GetResponseType() const
{
	return FVyUpdateSecurityResponse::StaticStruct();
}

FName UVyNode_Wallet_UpdateSecurity::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_UpdateSecurity::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, UpdateSecurity);
}

FName UVyNode_Wallet_UpdateSecurity::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_UpdateSecurity::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_UpdateSecurity::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
