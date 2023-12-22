#include "AutoGen/Nft/VyNode_Nft_GetTokenInfos.h"
#include "AutoGen/VyNftAPI_BP.h"
#include "AutoGen/FnModels/Nft/VyGetTokenInfos_Nft.h"
UClass* UVyNode_Nft_GetTokenInfos::GetApiClass() const
{
	return UVyNftAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Nft_GetTokenInfos::GetResponseType() const
{
	return FVyGetTokenInfosResponse::StaticStruct();
}

FName UVyNode_Nft_GetTokenInfos::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, Get);
}

FName UVyNode_Nft_GetTokenInfos::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, GetTokenInfos);
}

FName UVyNode_Nft_GetTokenInfos::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Nft_GetTokenInfos::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Nft_GetTokenInfos::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
