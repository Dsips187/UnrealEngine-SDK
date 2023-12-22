#pragma once
#include "Models/VyCoreModels.h"

#include "AutoGen/Optionals/VyOptNetwork.h"
#include "AutoGen/VyEnums_generated.h"
#include "AutoGen/Optionals/VyOptContractInputArray.h"
#include "AutoGen/Optionals/VyOptDouble.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "VyTransactionContractExecutionRequest.generated.h"

/*
* Request parameters for executing a contract transaction
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyTransactionContractExecutionRequest : public FVyDTO
{
	GENERATED_BODY()
	/**The ID of the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString WalletId;
	/**The address to which the transaction is being sent*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ToAddress;
	/**The preferred blockchain for the transaction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyChain Chain;
	/**The network to use for the transaction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptNetwork Network;
	/**Chain-specific fields for the transaction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString ChainSpecificFields;
	/**The name of the function to execute in the contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString FunctionName;
	/**The value to transfer in the transaction*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptDouble Value;
	/**The inputs for the contract function*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptContractInputArray Inputs;
	/**(read-only) The transaction type, should be "CONTRACT_EXECUTION"*/
	UPROPERTY(BlueprintReadOnly, Category="Venly") FString Type{TEXT("CONTRACT_EXECUTION")};
	
	virtual ~FVyTransactionContractExecutionRequest() = default;
	virtual bool HasPropertyLUT() const override { return true; }
	virtual const TMap<FName, FName>& GetPropertyLUT() const override;
};


UCLASS(BlueprintType)
class VENLY_API UVyTransactionContractExecutionRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyTransactionContractExecutionRequestRef* ToObject(const FVyTransactionContractExecutionRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyTransactionContractExecutionRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyTransactionContractExecutionRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyTransactionContractExecutionRequest Data{};
};