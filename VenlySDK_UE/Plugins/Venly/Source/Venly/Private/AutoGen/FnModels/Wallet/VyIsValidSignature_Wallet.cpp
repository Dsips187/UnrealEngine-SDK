#include "AutoGen/FnModels/Wallet//VyIsValidSignature_Wallet.h"

const TMap<FName, FName>& FVySignatureVerificationRequest::GetPropertyLUT() const
{
	static const TMap<FName, FName> LUT = {
	{TEXT("Chain"), TEXT("secretType")},
	};
	
	return LUT;
}
