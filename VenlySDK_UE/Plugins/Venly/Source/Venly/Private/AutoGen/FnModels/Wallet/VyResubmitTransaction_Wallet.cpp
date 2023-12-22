#include "AutoGen/FnModels/Wallet//VyResubmitTransaction_Wallet.h"

const TMap<FName, FName>& FVyResubmitTransactionRequest::GetPropertyLUT() const
{
	static const TMap<FName, FName> LUT = {
	{TEXT("Chain"), TEXT("secretType")},
	};
	
	return LUT;
}
