#include "AutoGen/Nft/VyNode_Nft_GetCompanyWallets.h"
#include "AutoGen/VyNftAPI_BP.h"
#include "AutoGen/FnModels/Nft/VyGetCompanyWallets_Nft.h"
UClass* UVyNode_Nft_GetCompanyWallets::GetApiClass() const
{
	return UVyNftAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Nft_GetCompanyWallets::GetResponseType() const
{
	return FVyGetCompanyWalletsResponse::StaticStruct();
}

FName UVyNode_Nft_GetCompanyWallets::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, Get);
}

FName UVyNode_Nft_GetCompanyWallets::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, GetCompanyWallets);
}

FName UVyNode_Nft_GetCompanyWallets::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Nft_GetCompanyWallets::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Nft_GetCompanyWallets::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
