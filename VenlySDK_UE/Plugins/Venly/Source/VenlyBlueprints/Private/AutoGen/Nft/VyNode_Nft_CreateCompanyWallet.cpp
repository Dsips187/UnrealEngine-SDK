#include "AutoGen/Nft/VyNode_Nft_CreateCompanyWallet.h"
#include "AutoGen/VyNftAPI_BP.h"
#include "AutoGen/FnModels/Nft/VyCreateCompanyWallet_Nft.h"
UClass* UVyNode_Nft_CreateCompanyWallet::GetApiClass() const
{
	return UVyNftAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Nft_CreateCompanyWallet::GetResponseType() const
{
	return FVyCreateCompanyWalletResponse::StaticStruct();
}

FName UVyNode_Nft_CreateCompanyWallet::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, Get);
}

FName UVyNode_Nft_CreateCompanyWallet::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, CreateCompanyWallet);
}

FName UVyNode_Nft_CreateCompanyWallet::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Nft_CreateCompanyWallet::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Nft_CreateCompanyWallet::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
