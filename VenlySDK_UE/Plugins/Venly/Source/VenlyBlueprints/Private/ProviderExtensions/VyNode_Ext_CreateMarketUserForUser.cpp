#include "ProviderExtensions/VyNode_Ext_CreateMarketUserForUser.h"
#include "VyProviderExtensions.h"
#include "VyProviderExtensionModels.h"

UClass* UVyNode_Ext_CreateMarketUserForUser::GetApiClass() const
{
	return UVyProviderExtensions::StaticClass();
}

UScriptStruct* UVyNode_Ext_CreateMarketUserForUser::GetResponseType() const
{
	return FVyCreateSubUserResponse::StaticStruct();
}

FName UVyNode_Ext_CreateMarketUserForUser::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyProviderExtensions, Get);
}

FName UVyNode_Ext_CreateMarketUserForUser::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyProviderExtensions, BP_CreateMarketUserForUser);
}

FName UVyNode_Ext_CreateMarketUserForUser::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Ext_CreateMarketUserForUser::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Ext_CreateMarketUserForUser::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
