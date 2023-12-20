#include "AutoGen/Market/VyNode_Market_CreateDepositAddress.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyCreateDepositAddress_Market.h"
UClass* UVyNode_Market_CreateDepositAddress::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_CreateDepositAddress::GetResponseType() const
{
	return FVyCreateDepositAddressResponse::StaticStruct();
}

FName UVyNode_Market_CreateDepositAddress::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_CreateDepositAddress::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, CreateDepositAddress);
}

FName UVyNode_Market_CreateDepositAddress::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_CreateDepositAddress::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_CreateDepositAddress::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
