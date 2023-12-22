#include "AutoGen/Nft/VyNode_Nft_MintTokens.h"
#include "AutoGen/VyNftAPI_BP.h"
#include "AutoGen/FnModels/Nft/VyMintTokens_Nft.h"
UClass* UVyNode_Nft_MintTokens::GetApiClass() const
{
	return UVyNftAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Nft_MintTokens::GetResponseType() const
{
	return FVyMintTokensResponse::StaticStruct();
}

FName UVyNode_Nft_MintTokens::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, Get);
}

FName UVyNode_Nft_MintTokens::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, MintTokens);
}

FName UVyNode_Nft_MintTokens::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Nft_MintTokens::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Nft_MintTokens::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
