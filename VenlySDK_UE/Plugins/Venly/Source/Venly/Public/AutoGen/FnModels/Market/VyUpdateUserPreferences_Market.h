#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Market/VyUserPreferencesDto.h"
#include "AutoGen/Optionals/VyOptBool.h"

#include "VyUpdateUserPreferences_Market.generated.h"


//REQUEST [updateUserPreferences]
/*
* Request parameters to update user preferences
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyUpdateUserPreferencesRequest : public FVyDTO
{
	GENERATED_BODY()
	/**Flag to enable or disable email notifications*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptBool EmailNotifications;
	/**Flag to enable or disable marketing emails*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptBool MarketingEmails;
};


UCLASS(BlueprintType)
class VENLY_API UVyUpdateUserPreferencesRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyUpdateUserPreferencesRequestRef* ToObject(const FVyUpdateUserPreferencesRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyUpdateUserPreferencesRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyUpdateUserPreferencesRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyUpdateUserPreferencesRequest Data{};
};
//RESPONSE [UserPreferencesDto]
USTRUCT(BlueprintType)
struct VENLY_API FVyUpdateUserPreferencesResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyUserPreferencesDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnUpdateUserPreferencesCompleteBP, FVyUpdateUserPreferencesResponse, Result);
