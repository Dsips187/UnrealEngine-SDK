#include "AutoGen/Models/Nft/VyTokenTypeDto.h"

const TMap<FName, FName>& FVyTokenTypeDto::GetPropertyLUT() const
{
	static const TMap<FName, FName> LUT = {
	{TEXT("ImageUrl"), TEXT("image")},
	{TEXT("ImageThumbnailUrl"), TEXT("imageThumbnail")},
	{TEXT("ImagePreviewUrl"), TEXT("imagePreview")},
	};
	
	return LUT;
}
