#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/VyEnums_generated.h"
#include "AutoGen/Models/Nft/VyCompanyWalletDto.h"
#include "AutoGen/Optionals/VyOptCompanyWalletType.h"

#include "VyCreateCompanyWallet_Nft.generated.h"


//REQUEST [createCompanyWallet]
/*
* Request parameters to create a company wallet
*/
USTRUCT(BlueprintType)
struct FVyCreateCompanyWalletRequest : public FVyDTO
{
	GENERATED_BODY()
	/**The type of the company wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptCompanyWalletType Type;
	/**The preferred blockchain for the company wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") EVyChain Chain;
};


UCLASS(BlueprintType)
class UVyCreateCompanyWalletRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyCreateCompanyWalletRequestRef* ToObject(const FVyCreateCompanyWalletRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyCreateCompanyWalletRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyCreateCompanyWalletRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyCreateCompanyWalletRequest Data{};
};
//RESPONSE [create_merged]
USTRUCT(BlueprintType)
struct FVyCreateCompanyWalletResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyCompanyWalletDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnCreateCompanyWalletCompleteBP, FVyCreateCompanyWalletResponse, Result);
