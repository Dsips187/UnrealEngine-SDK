#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Wallet/VyTransactionResultDto.h"
#include "AutoGen/VyEnums_generated.h"

#include "VyCancelTransaction_Wallet.generated.h"


//REQUEST [transactionCancel]
/*
* Request parameters to cancel a transaction
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyTransactionCancelRequest : public FVyDTO
{
	GENERATED_BODY()
	/**The blockchain on which the transaction is taking place*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyChain Chain;
	/**The hash of the transaction to be cancelled*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString TransactionHash;
	/**Pincode to access the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Pincode;
	
	virtual ~FVyTransactionCancelRequest() = default;
	virtual bool HasPropertyLUT() const override { return true; }
	virtual const TMap<FName, FName>& GetPropertyLUT() const override;
};


UCLASS(BlueprintType)
class VENLY_API UVyTransactionCancelRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyTransactionCancelRequestRef* ToObject(const FVyTransactionCancelRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyTransactionCancelRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyTransactionCancelRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyTransactionCancelRequest Data{};
};
//RESPONSE [TransactionResult]
USTRUCT(BlueprintType)
struct VENLY_API FVyCancelTransactionResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyTransactionResultDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnCancelTransactionCompleteBP, FVyCancelTransactionResponse, Result);
