#include "AutoGen/FnModels/Nft//VyCreateContract_Nft.h"

const TMap<FName, FName>& FVyCreateContractRequest::GetPropertyLUT() const
{
	static const TMap<FName, FName> LUT = {
	{TEXT("ImageUrl"), TEXT("image")},
	};
	
	return LUT;
}
