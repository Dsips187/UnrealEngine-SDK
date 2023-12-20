#include "AutoGen/Nft/VyNode_Nft_UpdateTokenTypeMetadata.h"
#include "AutoGen/VyNftAPI_BP.h"
#include "AutoGen/FnModels/Nft/VyUpdateTokenTypeMetadata_Nft.h"
UClass* UVyNode_Nft_UpdateTokenTypeMetadata::GetApiClass() const
{
	return UVyNftAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Nft_UpdateTokenTypeMetadata::GetResponseType() const
{
	return FVyUpdateTokenTypeMetadataResponse::StaticStruct();
}

FName UVyNode_Nft_UpdateTokenTypeMetadata::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, Get);
}

FName UVyNode_Nft_UpdateTokenTypeMetadata::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, UpdateTokenTypeMetadata);
}

FName UVyNode_Nft_UpdateTokenTypeMetadata::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Nft_UpdateTokenTypeMetadata::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Nft_UpdateTokenTypeMetadata::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
