#include "AutoGen/Nft/VyNode_Nft_GetContractMetadata.h"
#include "AutoGen/VyNftAPI_BP.h"
#include "AutoGen/FnModels/Nft/VyGetContractMetadata_Nft.h"
UClass* UVyNode_Nft_GetContractMetadata::GetApiClass() const
{
	return UVyNftAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Nft_GetContractMetadata::GetResponseType() const
{
	return FVyGetContractMetadataResponse::StaticStruct();
}

FName UVyNode_Nft_GetContractMetadata::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, Get);
}

FName UVyNode_Nft_GetContractMetadata::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, GetContractMetadata);
}

FName UVyNode_Nft_GetContractMetadata::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Nft_GetContractMetadata::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Nft_GetContractMetadata::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
