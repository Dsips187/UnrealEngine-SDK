#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/Models/Market/VySubUserDto.h"
#include "AutoGen/Optionals/VyOptUserType.h"

#include "VyCreateSubUser_Market.generated.h"


//REQUEST [createSubUser]
/*
* Request parameters to create a sub user
*/
USTRUCT(BlueprintType)
struct FVyCreateSubUserRequest : public FVyDTO
{
	GENERATED_BODY()
	/**Nickname of the sub user*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString Nickname;
	/**Type of the sub user*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptUserType Type;
};


UCLASS(BlueprintType)
class UVyCreateSubUserRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyCreateSubUserRequestRef* ToObject(const FVyCreateSubUserRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyCreateSubUserRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyCreateSubUserRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyCreateSubUserRequest Data{};
};
//RESPONSE [SubUserDto]
USTRUCT(BlueprintType)
struct FVyCreateSubUserResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVySubUserDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnCreateSubUserCompleteBP, FVyCreateSubUserResponse, Result);
