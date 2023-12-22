#include "AutoGen/Nft/VyNode_Nft_GetTokenType.h"
#include "AutoGen/VyNftAPI_BP.h"
#include "AutoGen/FnModels/Nft/VyGetTokenType_Nft.h"
UClass* UVyNode_Nft_GetTokenType::GetApiClass() const
{
	return UVyNftAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Nft_GetTokenType::GetResponseType() const
{
	return FVyGetTokenTypeResponse::StaticStruct();
}

FName UVyNode_Nft_GetTokenType::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, Get);
}

FName UVyNode_Nft_GetTokenType::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, GetTokenType);
}

FName UVyNode_Nft_GetTokenType::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Nft_GetTokenType::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Nft_GetTokenType::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
