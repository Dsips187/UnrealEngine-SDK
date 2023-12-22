#include "AutoGen/FnModels/Wallet//VyReadContract_Wallet.h"

const TMap<FName, FName>& FVyReadContractRequest::GetPropertyLUT() const
{
	static const TMap<FName, FName> LUT = {
	{TEXT("Chain"), TEXT("secretType")},
	};
	
	return LUT;
}
