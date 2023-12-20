#include "AutoGen/Nft/VyNode_Nft_GetCompanyWalletByChain.h"
#include "AutoGen/VyNftAPI_BP.h"
#include "AutoGen/FnModels/Nft/VyGetCompanyWalletByChain_Nft.h"
UClass* UVyNode_Nft_GetCompanyWalletByChain::GetApiClass() const
{
	return UVyNftAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Nft_GetCompanyWalletByChain::GetResponseType() const
{
	return FVyGetCompanyWalletByChainResponse::StaticStruct();
}

FName UVyNode_Nft_GetCompanyWalletByChain::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, Get);
}

FName UVyNode_Nft_GetCompanyWalletByChain::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, GetCompanyWalletByChain);
}

FName UVyNode_Nft_GetCompanyWalletByChain::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Nft_GetCompanyWalletByChain::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Nft_GetCompanyWalletByChain::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
