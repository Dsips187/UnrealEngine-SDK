#include "ProviderExtensions/VyNode_Ext_CreateWalletForUser.h"
#include "VyProviderExtensions.h"
#include "VyProviderExtensionModels.h"

UClass* UVyNode_Ext_CreateWalletForUser::GetApiClass() const
{
	return UVyProviderExtensions::StaticClass();
}

UScriptStruct* UVyNode_Ext_CreateWalletForUser::GetResponseType() const
{
	return FVyCreateWalletResponse::StaticStruct();
}

FName UVyNode_Ext_CreateWalletForUser::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyProviderExtensions, Get);
}

FName UVyNode_Ext_CreateWalletForUser::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyProviderExtensions, BP_CreateWalletForUser);
}

FName UVyNode_Ext_CreateWalletForUser::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Ext_CreateWalletForUser::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Ext_CreateWalletForUser::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
