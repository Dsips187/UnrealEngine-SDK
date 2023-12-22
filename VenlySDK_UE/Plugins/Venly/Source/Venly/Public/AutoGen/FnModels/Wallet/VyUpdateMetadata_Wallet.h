#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/Models/Wallet/VyWalletDto.h"
#include "AutoGen/Optionals/VyOptBool.h"

#include "VyUpdateMetadata_Wallet.generated.h"


//REQUEST [UpdateWalletMetadataRequest]
/*
* Request parameters to update wallet metadata
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyUpdateWalletMetadataRequest : public FVyDTO
{
	GENERATED_BODY()
	/**A new description for the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString Description;
	/**Indicates whether the wallet should be set as primary*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptBool Primary;
	/**Indicates whether the wallet should be archived*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptBool Archived;
};


UCLASS(BlueprintType)
class VENLY_API UVyUpdateWalletMetadataRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyUpdateWalletMetadataRequestRef* ToObject(const FVyUpdateWalletMetadataRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyUpdateWalletMetadataRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyUpdateWalletMetadataRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyUpdateWalletMetadataRequest Data{};
};
//RESPONSE [ViewWalletResult]
USTRUCT(BlueprintType)
struct VENLY_API FVyUpdateMetadataResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyWalletDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnUpdateMetadataCompleteBP, FVyUpdateMetadataResponse, Result);
