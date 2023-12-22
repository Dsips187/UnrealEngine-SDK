#include "AutoGen/FnModels/Market//VyApproveOfferTx_Market.h"

const TMap<FName, FName>& FVyApproveOfferTxRequest::GetPropertyLUT() const
{
	static const TMap<FName, FName> LUT = {
	{TEXT("TransactionHash"), TEXT("txApprove")},
	};
	
	return LUT;
}
