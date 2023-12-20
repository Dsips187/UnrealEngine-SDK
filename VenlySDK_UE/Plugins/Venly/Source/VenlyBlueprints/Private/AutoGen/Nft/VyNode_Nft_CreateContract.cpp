#include "AutoGen/Nft/VyNode_Nft_CreateContract.h"
#include "AutoGen/VyNftAPI_BP.h"
#include "AutoGen/FnModels/Nft/VyCreateContract_Nft.h"
UClass* UVyNode_Nft_CreateContract::GetApiClass() const
{
	return UVyNftAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Nft_CreateContract::GetResponseType() const
{
	return FVyCreateContractResponse::StaticStruct();
}

FName UVyNode_Nft_CreateContract::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, Get);
}

FName UVyNode_Nft_CreateContract::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, CreateContract);
}

FName UVyNode_Nft_CreateContract::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Nft_CreateContract::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Nft_CreateContract::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
