#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/Optionals/VyOptChain.h"
#include "AutoGen/Optionals/VyOptBool.h"
#include "AutoGen/Optionals/VyOptStorage.h"
#include "AutoGen/Models/Shared/VyContractDto.h"
#include "AutoGen/Optionals/VyOptTypeValueArray.h"

#include "VyCreateContract_Nft.generated.h"


//REQUEST [createContract]
/*
* Request parameters to create a contract
*/
USTRUCT(BlueprintType)
struct FVyCreateContractRequest : public FVyDTO
{
	GENERATED_BODY()
	/**The name of the contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Name;
	/**The symbol of the contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString Symbol;
	/**The description of the contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Description;
	/**The URL of the image associated with the contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ImageUrl;
	/**The external URL associated with the contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString ExternalUrl;
	/**The media associated with the contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptTypeValueArray Media;
	/**The owner of the contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString Owner;
	/**Indicates if auto-approved addresses are locked*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptBool AutoApprovedAddressesLocked;
	/**The storage options for the contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptStorage Storage;
	/**The preferred blockchain for the contract*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptChain Chain;
	
	virtual ~FVyCreateContractRequest() = default;
	virtual bool HasPropertyLUT() const override { return true; }
	virtual const TMap<FName, FName>& GetPropertyLUT() const override;
};


UCLASS(BlueprintType)
class UVyCreateContractRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyCreateContractRequestRef* ToObject(const FVyCreateContractRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyCreateContractRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyCreateContractRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyCreateContractRequest Data{};
};
//RESPONSE [TokenContractView]
USTRUCT(BlueprintType)
struct FVyCreateContractResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyContractDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnCreateContractCompleteBP, FVyCreateContractResponse, Result);
