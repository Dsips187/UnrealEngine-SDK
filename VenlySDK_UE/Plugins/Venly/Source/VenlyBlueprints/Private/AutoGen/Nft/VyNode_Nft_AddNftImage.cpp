#include "AutoGen/Nft/VyNode_Nft_AddNftImage.h"
#include "AutoGen/VyNftAPI_BP.h"
#include "AutoGen/FnModels/Nft/VyAddNftImage_Nft.h"
UClass* UVyNode_Nft_AddNftImage::GetApiClass() const
{
	return UVyNftAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Nft_AddNftImage::GetResponseType() const
{
	return FVyAddNftImageResponse::StaticStruct();
}

FName UVyNode_Nft_AddNftImage::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, Get);
}

FName UVyNode_Nft_AddNftImage::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, AddNftImage);
}

FName UVyNode_Nft_AddNftImage::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Nft_AddNftImage::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Nft_AddNftImage::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
