#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/VyEnums_generated.h"
#include "AutoGen/Optionals/VyOptContractInputArray.h"
#include "AutoGen/Models/Wallet/VyReadContractResultDto.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/Optionals/VyOptContractOutputArray.h"

#include "VyReadContract_Wallet.generated.h"


//REQUEST [readContract]
/*
* Request parameters to read a contract
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyReadContractRequest : public FVyDTO
{
	GENERATED_BODY()
	/**The preferred blockchain for the contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyChain Chain;
	/**Address of the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString WalletAddress;
	/**Address of the contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ContractAddress;
	/**Name of the contract function to call*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString FunctionName;
	/**Array of input parameters for the contract function*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptContractInputArray Inputs;
	/**Array of output parameters for the contract function*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptContractOutputArray Outputs;
	
	virtual ~FVyReadContractRequest() = default;
	virtual bool HasPropertyLUT() const override { return true; }
	virtual const TMap<FName, FName>& GetPropertyLUT() const override;
};


UCLASS(BlueprintType)
class VENLY_API UVyReadContractRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyReadContractRequestRef* ToObject(const FVyReadContractRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyReadContractRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyReadContractRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyReadContractRequest Data{};
};
//RESPONSE [ContractReadResult]
USTRUCT(BlueprintType)
struct VENLY_API FVyReadContractResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") TArray<FVyReadContractResultDto> Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnReadContractCompleteBP, FVyReadContractResponse, Result);
