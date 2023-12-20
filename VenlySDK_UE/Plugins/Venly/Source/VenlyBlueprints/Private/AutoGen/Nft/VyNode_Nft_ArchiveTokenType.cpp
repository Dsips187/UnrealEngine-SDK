#include "AutoGen/Nft/VyNode_Nft_ArchiveTokenType.h"
#include "AutoGen/VyNftAPI_BP.h"
#include "Models/VyCoreModels.h"
UClass* UVyNode_Nft_ArchiveTokenType::GetApiClass() const
{
	return UVyNftAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Nft_ArchiveTokenType::GetResponseType() const
{
	return FVyApiUnitResponse::StaticStruct();
}

FName UVyNode_Nft_ArchiveTokenType::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, Get);
}

FName UVyNode_Nft_ArchiveTokenType::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, ArchiveTokenType);
}

FName UVyNode_Nft_ArchiveTokenType::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Nft_ArchiveTokenType::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Nft_ArchiveTokenType::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
