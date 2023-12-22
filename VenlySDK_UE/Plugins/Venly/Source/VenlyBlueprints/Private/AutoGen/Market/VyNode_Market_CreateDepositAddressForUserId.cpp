#include "AutoGen/Market/VyNode_Market_CreateDepositAddressForUserId.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyCreateDepositAddressForUserId_Market.h"
UClass* UVyNode_Market_CreateDepositAddressForUserId::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_CreateDepositAddressForUserId::GetResponseType() const
{
	return FVyCreateDepositAddressForUserIdResponse::StaticStruct();
}

FName UVyNode_Market_CreateDepositAddressForUserId::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_CreateDepositAddressForUserId::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, CreateDepositAddressForUserId);
}

FName UVyNode_Market_CreateDepositAddressForUserId::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_CreateDepositAddressForUserId::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_CreateDepositAddressForUserId::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
