#include "AutoGen/Nft/VyNode_Nft_GetTokenTypes.h"
#include "AutoGen/VyNftAPI_BP.h"
#include "AutoGen/FnModels/Nft/VyGetTokenTypes_Nft.h"
UClass* UVyNode_Nft_GetTokenTypes::GetApiClass() const
{
	return UVyNftAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Nft_GetTokenTypes::GetResponseType() const
{
	return FVyGetTokenTypesResponse::StaticStruct();
}

FName UVyNode_Nft_GetTokenTypes::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, Get);
}

FName UVyNode_Nft_GetTokenTypes::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, GetTokenTypes);
}

FName UVyNode_Nft_GetTokenTypes::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Nft_GetTokenTypes::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Nft_GetTokenTypes::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
