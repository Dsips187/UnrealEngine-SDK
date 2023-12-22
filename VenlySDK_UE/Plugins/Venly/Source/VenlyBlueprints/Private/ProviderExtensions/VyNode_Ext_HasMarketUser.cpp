#include "ProviderExtensions/VyNode_Ext_HasMarketUser.h"
#include "VyProviderExtensions.h"
#include "VyProviderExtensionModels.h"

UClass* UVyNode_Ext_HasMarketUser::GetApiClass() const
{
	return UVyProviderExtensions::StaticClass();
}

UScriptStruct* UVyNode_Ext_HasMarketUser::GetResponseType() const
{
	return FVyHasMarketUserResponse::StaticStruct();
}

FName UVyNode_Ext_HasMarketUser::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyProviderExtensions, Get);
}

FName UVyNode_Ext_HasMarketUser::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyProviderExtensions, BP_HasMarketUser);
}

FName UVyNode_Ext_HasMarketUser::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Ext_HasMarketUser::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Ext_HasMarketUser::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
