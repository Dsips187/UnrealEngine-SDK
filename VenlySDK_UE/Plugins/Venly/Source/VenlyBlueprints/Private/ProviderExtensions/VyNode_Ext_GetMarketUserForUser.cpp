#include "ProviderExtensions/VyNode_Ext_GetMarketUserForUser.h"
#include "VyProviderExtensions.h"
#include "VyProviderExtensionModels.h"

UClass* UVyNode_Ext_GetMarketUserForUser::GetApiClass() const
{
	return UVyProviderExtensions::StaticClass();
}

UScriptStruct* UVyNode_Ext_GetMarketUserForUser::GetResponseType() const
{
	return FVyGetUserProfileResponse::StaticStruct();
}

FName UVyNode_Ext_GetMarketUserForUser::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyProviderExtensions, Get);
}

FName UVyNode_Ext_GetMarketUserForUser::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyProviderExtensions, BP_GetMarketUserForUser);
}

FName UVyNode_Ext_GetMarketUserForUser::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Ext_GetMarketUserForUser::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Ext_GetMarketUserForUser::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
