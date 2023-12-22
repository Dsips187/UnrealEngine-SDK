#include "AutoGen/Nft/VyNode_Nft_GetSupportedNftChains.h"
#include "AutoGen/VyNftAPI_BP.h"
#include "AutoGen/FnModels/Nft/VyGetSupportedNftChains_Nft.h"
UClass* UVyNode_Nft_GetSupportedNftChains::GetApiClass() const
{
	return UVyNftAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Nft_GetSupportedNftChains::GetResponseType() const
{
	return FVyGetSupportedNftChainsResponse::StaticStruct();
}

FName UVyNode_Nft_GetSupportedNftChains::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, Get);
}

FName UVyNode_Nft_GetSupportedNftChains::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, GetSupportedNftChains);
}

FName UVyNode_Nft_GetSupportedNftChains::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Nft_GetSupportedNftChains::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Nft_GetSupportedNftChains::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
