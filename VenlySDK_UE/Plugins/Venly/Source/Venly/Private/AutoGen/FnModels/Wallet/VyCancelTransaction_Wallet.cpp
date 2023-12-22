#include "AutoGen/FnModels/Wallet//VyCancelTransaction_Wallet.h"

const TMap<FName, FName>& FVyTransactionCancelRequest::GetPropertyLUT() const
{
	static const TMap<FName, FName> LUT = {
	{TEXT("Chain"), TEXT("secretType")},
	};
	
	return LUT;
}
