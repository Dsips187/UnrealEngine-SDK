#include "AutoGen/Models/Wallet/VyNativeTokenTransactionRequest.h"

const TMap<FName, FName>& FVyNativeTokenTransactionRequest::GetPropertyLUT() const
{
	static const TMap<FName, FName> LUT = {
	{TEXT("ToAddress"), TEXT("to")},
	{TEXT("Chain"), TEXT("secretType")},
	};
	
	return LUT;
}
