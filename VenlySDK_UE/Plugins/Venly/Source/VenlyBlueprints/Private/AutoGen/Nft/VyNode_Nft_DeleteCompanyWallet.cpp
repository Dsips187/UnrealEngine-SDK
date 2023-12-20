#include "AutoGen/Nft/VyNode_Nft_DeleteCompanyWallet.h"
#include "AutoGen/VyNftAPI_BP.h"
#include "Models/VyCoreModels.h"
UClass* UVyNode_Nft_DeleteCompanyWallet::GetApiClass() const
{
	return UVyNftAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Nft_DeleteCompanyWallet::GetResponseType() const
{
	return FVyApiUnitResponse::StaticStruct();
}

FName UVyNode_Nft_DeleteCompanyWallet::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, Get);
}

FName UVyNode_Nft_DeleteCompanyWallet::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyNftAPI_BP, DeleteCompanyWallet);
}

FName UVyNode_Nft_DeleteCompanyWallet::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Nft_DeleteCompanyWallet::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Nft_DeleteCompanyWallet::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
