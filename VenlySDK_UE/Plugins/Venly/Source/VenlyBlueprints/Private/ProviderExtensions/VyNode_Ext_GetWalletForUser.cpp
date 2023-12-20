#include "ProviderExtensions/VyNode_Ext_GetWalletForUser.h"
#include "VyProviderExtensions.h"
#include "VyProviderExtensionModels.h"

UClass* UVyNode_Ext_GetWalletForUser::GetApiClass() const
{
	return UVyProviderExtensions::StaticClass();
}

UScriptStruct* UVyNode_Ext_GetWalletForUser::GetResponseType() const
{
	return FVyGetWalletResponse::StaticStruct();
}

FName UVyNode_Ext_GetWalletForUser::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyProviderExtensions, Get);
}

FName UVyNode_Ext_GetWalletForUser::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyProviderExtensions, BP_GetWalletForUser);
}

FName UVyNode_Ext_GetWalletForUser::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Ext_GetWalletForUser::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Ext_GetWalletForUser::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
