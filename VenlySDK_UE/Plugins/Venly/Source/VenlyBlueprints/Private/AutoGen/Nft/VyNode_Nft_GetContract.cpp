#include "AutoGen/Nft/VyNode_Nft_GetContract.h"
#include "AutoGen/VyNftAPI_BP.h"
#include "AutoGen/FnModels/Nft/VyGetContract_Nft.h"
UClass* UVyNode_Nft_GetContract::GetApiClass() const
{
	return UVyNftAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Nft_GetContract::GetResponseType() const
{
	return FVyGetContractResponse::StaticStruct();
}

FName UVyNode_Nft_GetContract::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, Get);
}

FName UVyNode_Nft_GetContract::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, GetContract);
}

FName UVyNode_Nft_GetContract::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Nft_GetContract::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Nft_GetContract::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
