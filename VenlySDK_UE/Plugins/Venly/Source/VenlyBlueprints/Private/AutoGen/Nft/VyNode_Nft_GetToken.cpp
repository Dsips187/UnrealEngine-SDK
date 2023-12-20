#include "AutoGen/Nft/VyNode_Nft_GetToken.h"
#include "AutoGen/VyNftAPI_BP.h"
#include "AutoGen/FnModels/Nft/VyGetToken_Nft.h"
UClass* UVyNode_Nft_GetToken::GetApiClass() const
{
	return UVyNftAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Nft_GetToken::GetResponseType() const
{
	return FVyGetTokenResponse::StaticStruct();
}

FName UVyNode_Nft_GetToken::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, Get);
}

FName UVyNode_Nft_GetToken::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, GetToken);
}

FName UVyNode_Nft_GetToken::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Nft_GetToken::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Nft_GetToken::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
