#include "AutoGen/Models/Wallet/VyGasTransactionRequest.h"

const TMap<FName, FName>& FVyGasTransactionRequest::GetPropertyLUT() const
{
	static const TMap<FName, FName> LUT = {
	{TEXT("ToAddress"), TEXT("to")},
	{TEXT("Chain"), TEXT("secretType")},
	};
	
	return LUT;
}
