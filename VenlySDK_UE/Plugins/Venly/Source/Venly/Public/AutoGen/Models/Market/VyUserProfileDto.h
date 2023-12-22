#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/VyEnums_generated.h"
#include "VyUserProfileDto.generated.h"

/*
* User profile information
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyUserProfileDto : public FVyDTO
{
	GENERATED_BODY()
	/**User ID*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Id;
	/**User nickname*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Nickname;
	/**User verification status*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyVerificationState VerificationStatus;
};


UCLASS(BlueprintType)
class VENLY_API UVyUserProfileDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyUserProfileDtoRef* ToObject(const FVyUserProfileDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyUserProfileDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyUserProfileDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyUserProfileDto Data{};
};