#include "AutoGen/Nft/VyNode_Nft_GetContracts.h"
#include "AutoGen/VyNftAPI_BP.h"
#include "AutoGen/FnModels/Nft/VyGetContracts_Nft.h"
UClass* UVyNode_Nft_GetContracts::GetApiClass() const
{
	return UVyNftAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Nft_GetContracts::GetResponseType() const
{
	return FVyGetContractsResponse::StaticStruct();
}

FName UVyNode_Nft_GetContracts::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, Get);
}

FName UVyNode_Nft_GetContracts::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, GetContracts);
}

FName UVyNode_Nft_GetContracts::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Nft_GetContracts::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Nft_GetContracts::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
