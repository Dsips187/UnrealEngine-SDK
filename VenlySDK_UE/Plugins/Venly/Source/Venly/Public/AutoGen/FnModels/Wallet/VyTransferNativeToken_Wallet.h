#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Wallet/VyTransactionResultDto.h"
#include "AutoGen/Models/Wallet/VyNativeTokenTransactionRequest.h"

#include "VyTransferNativeToken_Wallet.generated.h"


//REQUEST [transferNativeToken]
/*
* Request parameters to transfer native blockchain tokens
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyTransferNativeTokenRequest : public FVyDTO
{
	GENERATED_BODY()
	/**Parameters for the token transfer transaction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyNativeTokenTransactionRequest TransactionRequest;
	/**Pincode to authorize the token transfer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Pincode;
};


UCLASS(BlueprintType)
class VENLY_API UVyTransferNativeTokenRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyTransferNativeTokenRequestRef* ToObject(const FVyTransferNativeTokenRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyTransferNativeTokenRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyTransferNativeTokenRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyTransferNativeTokenRequest Data{};
};
//RESPONSE [TransactionResult]
USTRUCT(BlueprintType)
struct VENLY_API FVyTransferNativeTokenResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyTransactionResultDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnTransferNativeTokenCompleteBP, FVyTransferNativeTokenResponse, Result);
