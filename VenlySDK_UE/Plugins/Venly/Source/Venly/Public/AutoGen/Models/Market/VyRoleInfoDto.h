#pragma once
#include "Models/VyCoreModels.h"

#include "VyRoleInfoDto.generated.h"

/*
* Role information data transfer object
*/
USTRUCT(BlueprintType)
struct FVyRoleInfoDto : public FVyDTO
{
	GENERATED_BODY()
	/**The authority of the role*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Authority;
};


UCLASS(BlueprintType)
class UVyRoleInfoDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyRoleInfoDtoRef* ToObject(const FVyRoleInfoDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyRoleInfoDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyRoleInfoDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyRoleInfoDto Data{};
};