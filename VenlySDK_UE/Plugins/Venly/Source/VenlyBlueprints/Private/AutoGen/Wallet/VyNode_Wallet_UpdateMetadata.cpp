#include "AutoGen/Wallet/VyNode_Wallet_UpdateMetadata.h"
#include "AutoGen/VyWalletAPI_BP.h"
#include "AutoGen/FnModels/Wallet/VyUpdateMetadata_Wallet.h"
UClass* UVyNode_Wallet_UpdateMetadata::GetApiClass() const
{
	return UVyWalletAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Wallet_UpdateMetadata::GetResponseType() const
{
	return FVyUpdateMetadataResponse::StaticStruct();
}

FName UVyNode_Wallet_UpdateMetadata::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, Get);
}

FName UVyNode_Wallet_UpdateMetadata::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyWalletAPI_BP, UpdateMetadata);
}

FName UVyNode_Wallet_UpdateMetadata::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Wallet_UpdateMetadata::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Wallet_UpdateMetadata::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
