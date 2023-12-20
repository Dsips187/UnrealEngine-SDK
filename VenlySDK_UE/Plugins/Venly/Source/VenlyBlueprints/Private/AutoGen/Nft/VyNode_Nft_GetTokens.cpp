#include "AutoGen/Nft/VyNode_Nft_GetTokens.h"
#include "AutoGen/VyNftAPI_BP.h"
#include "AutoGen/FnModels/Nft/VyGetTokens_Nft.h"
UClass* UVyNode_Nft_GetTokens::GetApiClass() const
{
	return UVyNftAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Nft_GetTokens::GetResponseType() const
{
	return FVyGetTokensResponse::StaticStruct();
}

FName UVyNode_Nft_GetTokens::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, Get);
}

FName UVyNode_Nft_GetTokens::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, GetTokens);
}

FName UVyNode_Nft_GetTokens::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Nft_GetTokens::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Nft_GetTokens::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
