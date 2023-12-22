#include "AutoGen/FnModels/Nft//VyCreateTokenType_Nft.h"

const TMap<FName, FName>& FVyCreateTokenTypeRequest::GetPropertyLUT() const
{
	static const TMap<FName, FName> LUT = {
	{TEXT("ImageUrl"), TEXT("image")},
	};
	
	return LUT;
}
