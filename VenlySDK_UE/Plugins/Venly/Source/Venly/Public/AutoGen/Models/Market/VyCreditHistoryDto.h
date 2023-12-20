#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/VyEnums_generated.h"
#include "AutoGen/Models/Market/VyReferenceDto.h"
#include "AutoGen/Models/Market/VyUserCreditHistoryFeeDto.h"
#include "VyCreditHistoryDto.generated.h"

/*
* Represents a credit history entry
*/
USTRUCT(BlueprintType)
struct FVyCreditHistoryDto : public FVyDTO
{
	GENERATED_BODY()
	/**The date of the credit history entry*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Date;
	/**The ID of the user associated with the credit history entry*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString UserId;
	/**The type of the credit history entry*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyCreditHistoryType Type;
	/**The gross amount of the credit history entry*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double Gross;
	/**The net amount of the credit history entry*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") double Net;
	/**The reference associated with the credit history entry*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyReferenceDto Reference;
	/**The fees associated with the credit history entry*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") TArray<FVyUserCreditHistoryFeeDto> Fees;
	/**The status of the credit history entry*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyCreditHistoryState Status;
};


UCLASS(BlueprintType)
class UVyCreditHistoryDtoRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyCreditHistoryDtoRef* ToObject(const FVyCreditHistoryDto& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyCreditHistoryDtoRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyCreditHistoryDto& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyCreditHistoryDto Data{};
};