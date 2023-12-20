#include "AutoGen/Market/VyNode_Market_GetCollections.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyGetCollections_Market.h"
UClass* UVyNode_Market_GetCollections::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_GetCollections::GetResponseType() const
{
	return FVyGetCollectionsResponse::StaticStruct();
}

FName UVyNode_Market_GetCollections::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_GetCollections::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, GetCollections);
}

FName UVyNode_Market_GetCollections::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_GetCollections::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_GetCollections::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
