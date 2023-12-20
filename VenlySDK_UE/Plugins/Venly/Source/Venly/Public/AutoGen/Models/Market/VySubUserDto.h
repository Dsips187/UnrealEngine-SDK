#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/VyEnums_generated.h"
#include "VySubUserDto.generated.h"

/*
* Data structure representing a sub user
*/
USTRUCT(BlueprintType)
struct FVySubUserDto : public FVyDTO
{
	GENERATED_BODY()
	/**The ID of the parent user*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ParentUserId;
	/**The ID of the sub user*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Id;
	/**The nickname of the sub user*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Nickname;
	/**The type of the sub user*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyUserType Type;
};


UCLASS(BlueprintType)
class UVySubUserDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVySubUserDtoRef* ToObject(const FVySubUserDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVySubUserDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVySubUserDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVySubUserDto Data{};
};