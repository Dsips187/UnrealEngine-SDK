#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/VyEnums_generated.h"
#include "VyWalletEventDto.generated.h"

/*
* Data structure representing a wallet event
*/
USTRUCT(BlueprintType)
struct FVyWalletEventDto : public FVyDTO
{
	GENERATED_BODY()
	/**The timestamp of the event*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString EventTimestamp;
	/**The client associated with the event*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Client;
	/**The API token associated with the event*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ApiToken;
	/**The type of the wallet event*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyWalletEventType EventType;
	/**Additional metadata for the event*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Metadata;
	/**The ID of the wallet associated with the event*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString WalletId;
	
	virtual ~FVyWalletEventDto() = default;
	virtual bool HasPropertyLUT() const override { return true; }
	virtual const TMap<FName, FName>& GetPropertyLUT() const override;
};


UCLASS(BlueprintType)
class UVyWalletEventDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyWalletEventDtoRef* ToObject(const FVyWalletEventDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyWalletEventDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyWalletEventDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyWalletEventDto Data{};
};