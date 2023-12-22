#include "AutoGen/Market/VyNode_Market_AddOfferSignature.h"
#include "AutoGen/VyMarketAPI_BP.h"
#include "AutoGen/FnModels/Market/VyAddOfferSignature_Market.h"
UClass* UVyNode_Market_AddOfferSignature::GetApiClass() const
{
	return UVyMarketAPI_BP::StaticClass();
}

UScriptStruct* UVyNode_Market_AddOfferSignature::GetResponseType() const
{
	return FVyAddOfferSignatureResponse::StaticStruct();
}

FName UVyNode_Market_AddOfferSignature::GetSelfFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, Get);
}

FName UVyNode_Market_AddOfferSignature::GetRequestFunctionName() const
{
	return GET_FUNCTION_NAME_CHECKED(UVyMarketAPI_BP, AddOfferSignature);
}

FName UVyNode_Market_AddOfferSignature::GetOnCompleteDelegateName() const
{
	return NAME_OnCompleteDelegate;
}

FName UVyNode_Market_AddOfferSignature::GetApiName() const
{
	return NAME_ApiName;
}

FName UVyNode_Market_AddOfferSignature::GetAuthoredName() const
{
	return NAME_AuthoredName;
}
