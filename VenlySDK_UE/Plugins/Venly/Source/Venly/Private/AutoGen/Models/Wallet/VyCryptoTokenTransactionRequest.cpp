#include "AutoGen/Models/Wallet/VyCryptoTokenTransactionRequest.h"

const TMap<FName, FName>& FVyCryptoTokenTransactionRequest::GetPropertyLUT() const
{
	static const TMap<FName, FName> LUT = {
	{TEXT("ToAddress"), TEXT("to")},
	{TEXT("Chain"), TEXT("secretType")},
	};
	
	return LUT;
}
