#include "AutoGen/Market/VyNode_Market_UpdateFulfillmentAssociation.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyUpdateFulfillmentAssociation_Market.h"
UClass* UVyNode_Market_UpdateFulfillmentAssociation::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_UpdateFulfillmentAssociation::GetResponseType() const
{
	return FVyUpdateFulfillmentAssociationResponse::StaticStruct();
}

FName UVyNode_Market_UpdateFulfillmentAssociation::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_UpdateFulfillmentAssociation::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, UpdateFulfillmentAssociation);
}

FName UVyNode_Market_UpdateFulfillmentAssociation::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_UpdateFulfillmentAssociation::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_UpdateFulfillmentAssociation::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
