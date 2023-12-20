#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Wallet/VyTransactionResultDto.h"
#include "AutoGen/Models/Wallet/VyGasTransactionRequest.h"

#include "VyTransferGas_Wallet.generated.h"


//REQUEST [transferGas]
/*
* Request parameters to transfer gas
*/
USTRUCT(BlueprintType)
struct FVyTransferGasRequest : public FVyDTO
{
	GENERATED_BODY()
	/**The transaction request for gas transfer*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyGasTransactionRequest TransactionRequest;
	/**Pincode to access the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Pincode;
};


UCLASS(BlueprintType)
class UVyTransferGasRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyTransferGasRequestRef* ToObject(const FVyTransferGasRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyTransferGasRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyTransferGasRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyTransferGasRequest Data{};
};
//RESPONSE [TransactionResult]
USTRUCT(BlueprintType)
struct FVyTransferGasResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyTransactionResultDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnTransferGasCompleteBP, FVyTransferGasResponse, Result);
