#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Models/Market/VyFulfillmentAssociationDto.h"

#include "VyUpdateFulfillmentAssociation_Market.generated.h"


//REQUEST [updateFulfillmentAssociation]
/*
* Request parameters to update a fulfillment association
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyUpdateFulfillmentAssociationRequest : public FVyDTO
{
	GENERATED_BODY()
	/**The ID of the fulfillment association*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString Id;
	/**The transaction association*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FString TxAssociation;
};


UCLASS(BlueprintType)
class VENLY_API UVyUpdateFulfillmentAssociationRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyUpdateFulfillmentAssociationRequestRef* ToObject(const FVyUpdateFulfillmentAssociationRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyUpdateFulfillmentAssociationRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyUpdateFulfillmentAssociationRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyUpdateFulfillmentAssociationRequest Data{};
};
//RESPONSE [updateAssociation_merged]
USTRUCT(BlueprintType)
struct VENLY_API FVyUpdateFulfillmentAssociationResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyFulfillmentAssociationDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnUpdateFulfillmentAssociationCompleteBP, FVyUpdateFulfillmentAssociationResponse, Result);
