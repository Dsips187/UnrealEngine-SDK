#pragma once
#include "Models/VyCoreModels.h"

#include "VyUserPreferencesDto.generated.h"

/*
* User preferences
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyUserPreferencesDto : public FVyDTO
{
	GENERATED_BODY()
	/**Flag indicating whether email notifications are enabled*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") bool EmailNotifications;
	/**Flag indicating whether marketing emails are enabled*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") bool MarketingEmails;
};


UCLASS(BlueprintType)
class VENLY_API UVyUserPreferencesDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyUserPreferencesDtoRef* ToObject(const FVyUserPreferencesDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyUserPreferencesDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyUserPreferencesDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyUserPreferencesDto Data{};
};