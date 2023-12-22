#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Market/VyOfferDto.h"

#include "VyApproveOfferTx_Market.generated.h"


//REQUEST [approveOfferTx]
/*
* Request parameters to approve an offer transaction
*/
USTRUCT(BlueprintType)
struct FVyApproveOfferTxRequest : public FVyDTO
{
	GENERATED_BODY()
	/**The hash of the transaction to approve*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString TransactionHash;
	
	virtual ~FVyApproveOfferTxRequest() = default;
	virtual bool HasPropertyLUT() const override { return true; }
	virtual const TMap<FName, FName>& GetPropertyLUT() const override;
};


UCLASS(BlueprintType)
class UVyApproveOfferTxRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyApproveOfferTxRequestRef* ToObject(const FVyApproveOfferTxRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyApproveOfferTxRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyApproveOfferTxRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyApproveOfferTxRequest Data{};
};
//RESPONSE [update_merged]
USTRUCT(BlueprintType)
struct FVyApproveOfferTxResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyOfferDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnApproveOfferTxCompleteBP, FVyApproveOfferTxResponse, Result);
