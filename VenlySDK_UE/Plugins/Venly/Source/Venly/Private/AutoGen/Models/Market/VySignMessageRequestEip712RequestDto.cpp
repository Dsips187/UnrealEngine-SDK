#include "AutoGen/Models/Market/VySignMessageRequestEip712RequestDto.h"

const TMap<FName, FName>& FVySignMessageRequestEip712RequestDto::GetPropertyLUT() const
{
	static const TMap<FName, FName> LUT = {
	{TEXT("Chain"), TEXT("secretType")},
	};
	
	return LUT;
}
