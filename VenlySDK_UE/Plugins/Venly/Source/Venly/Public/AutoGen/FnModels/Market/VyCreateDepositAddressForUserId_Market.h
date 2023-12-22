#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Optionals/VyOptChain.h"
#include "AutoGen/Models/Market/VyDepositAddressDto.h"

#include "VyCreateDepositAddressForUserId_Market.generated.h"


//REQUEST [createDepositAddress]
/*
* Request parameters to create a deposit address
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyCreateDepositAddressRequest : public FVyDTO
{
	GENERATED_BODY()
	/**The preferred blockchain for the deposit address*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptChain Chain;
};


UCLASS(BlueprintType)
class VENLY_API UVyCreateDepositAddressRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyCreateDepositAddressRequestRef* ToObject(const FVyCreateDepositAddressRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyCreateDepositAddressRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyCreateDepositAddressRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyCreateDepositAddressRequest Data{};
};
//RESPONSE [DepositAddressDto]
USTRUCT(BlueprintType)
struct VENLY_API FVyCreateDepositAddressForUserIdResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyDepositAddressDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnCreateDepositAddressForUserIdCompleteBP, FVyCreateDepositAddressForUserIdResponse, Result);
