#include "AutoGen/Nft/VyNode_Nft_GetTokenTypeMetadata.h"
#include "AutoGen/VyNftAPI_BP.h"
#include "AutoGen/FnModels/Nft/VyGetTokenTypeMetadata_Nft.h"
UClass* UVyNode_Nft_GetTokenTypeMetadata::GetApiClass() const
{
	return UVyNftAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Nft_GetTokenTypeMetadata::GetResponseType() const
{
	return FVyGetTokenTypeMetadataResponse::StaticStruct();
}

FName UVyNode_Nft_GetTokenTypeMetadata::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, Get);
}

FName UVyNode_Nft_GetTokenTypeMetadata::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, GetTokenTypeMetadata);
}

FName UVyNode_Nft_GetTokenTypeMetadata::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Nft_GetTokenTypeMetadata::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Nft_GetTokenTypeMetadata::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
