#include "AutoGen/Nft/VyNode_Nft_ArchiveContract.h"
#include "AutoGen/VyNftAPI_BP.h"
#include "Models/VyCoreModels.h"
UClass* UVyNode_Nft_ArchiveContract::GetApiClass() const
{
	return UVyNftAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Nft_ArchiveContract::GetResponseType() const
{
	return FVyApiUnitResponse::StaticStruct();
}

FName UVyNode_Nft_ArchiveContract::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, Get);
}

FName UVyNode_Nft_ArchiveContract::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, ArchiveContract);
}

FName UVyNode_Nft_ArchiveContract::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Nft_ArchiveContract::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Nft_ArchiveContract::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
