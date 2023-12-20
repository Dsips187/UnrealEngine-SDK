#include "AutoGen/Nft/VyNode_Nft_CreateTokenType.h"
#include "AutoGen/VyNftAPI_BP.h"
#include "AutoGen/FnModels/Nft/VyCreateTokenType_Nft.h"
UClass* UVyNode_Nft_CreateTokenType::GetApiClass() const
{
	return UVyNftAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Nft_CreateTokenType::GetResponseType() const
{
	return FVyCreateTokenTypeResponse::StaticStruct();
}

FName UVyNode_Nft_CreateTokenType::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, Get);
}

FName UVyNode_Nft_CreateTokenType::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, CreateTokenType);
}

FName UVyNode_Nft_CreateTokenType::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Nft_CreateTokenType::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Nft_CreateTokenType::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
