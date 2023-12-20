#include "AutoGen/Market/VyNode_Market_GetDepositAddresses.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyGetDepositAddresses_Market.h"
UClass* UVyNode_Market_GetDepositAddresses::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_GetDepositAddresses::GetResponseType() const
{
	return FVyGetDepositAddressesResponse::StaticStruct();
}

FName UVyNode_Market_GetDepositAddresses::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_GetDepositAddresses::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, GetDepositAddresses);
}

FName UVyNode_Market_GetDepositAddresses::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_GetDepositAddresses::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_GetDepositAddresses::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
