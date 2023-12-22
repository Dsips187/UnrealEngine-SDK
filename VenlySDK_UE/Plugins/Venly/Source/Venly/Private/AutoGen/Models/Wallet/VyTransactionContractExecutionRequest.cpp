#include "AutoGen/Models/Wallet/VyTransactionContractExecutionRequest.h"

const TMap<FName, FName>& FVyTransactionContractExecutionRequest::GetPropertyLUT() const
{
	static const TMap<FName, FName> LUT = {
	{TEXT("ToAddress"), TEXT("to")},
	{TEXT("Chain"), TEXT("secretType")},
	};
	
	return LUT;
}
