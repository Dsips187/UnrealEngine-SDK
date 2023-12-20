#include "ProviderExtensions/VyNode_Ext_HasWallet.h"
#include "VyProviderExtensions.h"
#include "VyProviderExtensionModels.h"

UClass* UVyNode_Ext_HasWallet::GetApiClass() const
{
	return UVyProviderExtensions::StaticClass();
}

UScriptStruct* UVyNode_Ext_HasWallet::GetResponseType() const
{
	return FVyHasWalletResponse::StaticStruct();
}

FName UVyNode_Ext_HasWallet::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyProviderExtensions, Get);
}

FName UVyNode_Ext_HasWallet::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyProviderExtensions, BP_HasWallet);
}

FName UVyNode_Ext_HasWallet::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Ext_HasWallet::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Ext_HasWallet::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
