#include "AutoGen/Models/Wallet/VyMultiTokenTransactionRequest.h"

const TMap<FName, FName>& FVyMultiTokenTransactionRequest::GetPropertyLUT() const
{
	static const TMap<FName, FName> LUT = {
	{TEXT("ToAddress"), TEXT("to")},
	{TEXT("Chain"), TEXT("secretType")},
	{TEXT("FromAddress"), TEXT("from")},
	};
	
	return LUT;
}
