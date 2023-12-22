#include "AutoGen/Market/VyNode_Market_GetCollection.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyGetCollection_Market.h"
UClass* UVyNode_Market_GetCollection::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_GetCollection::GetResponseType() const
{
	return FVyGetCollectionResponse::StaticStruct();
}

FName UVyNode_Market_GetCollection::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_GetCollection::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, GetCollection);
}

FName UVyNode_Market_GetCollection::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_GetCollection::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_GetCollection::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
