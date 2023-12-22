#include "AutoGen/Nft/VyNode_Nft_UpdateContractMetadata.h"
#include "AutoGen/VyNftAPI_BP.h"
#include "AutoGen/FnModels/Nft/VyUpdateContractMetadata_Nft.h"
UClass* UVyNode_Nft_UpdateContractMetadata::GetApiClass() const
{
	return UVyNftAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Nft_UpdateContractMetadata::GetResponseType() const
{
	return FVyUpdateContractMetadataResponse::StaticStruct();
}

FName UVyNode_Nft_UpdateContractMetadata::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, Get);
}

FName UVyNode_Nft_UpdateContractMetadata::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, UpdateContractMetadata);
}

FName UVyNode_Nft_UpdateContractMetadata::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Nft_UpdateContractMetadata::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Nft_UpdateContractMetadata::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
