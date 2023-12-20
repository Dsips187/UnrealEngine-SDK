#include "AutoGen/Nft/VyNode_Nft_AddNftMedia.h"
#include "AutoGen/VyNftAPI_BP.h"
#include "AutoGen/FnModels/Nft/VyAddNftMedia_Nft.h"
UClass* UVyNode_Nft_AddNftMedia::GetApiClass() const
{
	return UVyNftAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Nft_AddNftMedia::GetResponseType() const
{
	return FVyAddNftMediaResponse::StaticStruct();
}

FName UVyNode_Nft_AddNftMedia::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, Get);
}

FName UVyNode_Nft_AddNftMedia::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, AddNftMedia);
}

FName UVyNode_Nft_AddNftMedia::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Nft_AddNftMedia::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Nft_AddNftMedia::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
