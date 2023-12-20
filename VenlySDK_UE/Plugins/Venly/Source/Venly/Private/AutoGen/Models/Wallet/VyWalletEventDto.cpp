#include "AutoGen/Models/Wallet/VyWalletEventDto.h"

const TMap<FName, FName>& FVyWalletEventDto::GetPropertyLUT() const
{
	static const TMap<FName, FName> LUT = {
	{TEXT("EventType"), TEXT("type")},
	};
	
	return LUT;
}
