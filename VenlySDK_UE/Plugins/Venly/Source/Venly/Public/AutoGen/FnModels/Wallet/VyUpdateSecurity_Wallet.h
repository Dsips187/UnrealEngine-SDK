#pragma once

#include "Models/VyCoreModels.h"
#include "AutoGen/Optionals/VyOptString.h"
#include "AutoGen/Models/Wallet/VyWalletDto.h"
#include "AutoGen/Optionals/VyOptBool.h"

#include "VyUpdateSecurity_Wallet.generated.h"


//REQUEST [UpdateWalletSecurityRequest]
/*
* Request parameters to update the security settings of a wallet
*/
USTRUCT(BlueprintType)
struct VENLY_API FVyUpdateWalletSecurityRequest : public FVyDTO
{
	GENERATED_BODY()
	/**Current pincode of the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString Pincode;
	/**New pincode to set for the wallet*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptString NewPincode;
	/**Flag indicating if the wallet has a custom pin*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptBool HasCustomPin;
	/**Flag indicating if the wallet is recoverable*/
	UPROPERTY(BlueprintReadWrite, Category="Venly") FVyOptBool Recoverable;
};


UCLASS(BlueprintType)
class VENLY_API UVyUpdateWalletSecurityRequestRef : public UObject
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static UVyUpdateWalletSecurityRequestRef* ToObject(const FVyUpdateWalletSecurityRequest& _Data, UObject* WorldContextObject)
	{
		auto obj = NewObject<UVyUpdateWalletSecurityRequestRef>(WorldContextObject);
		obj->Data = _Data;
		return obj;
	}
	UFUNCTION(BlueprintCallable, Category="Venly")
	const FVyUpdateWalletSecurityRequest& GetData() const { return Data; }
	private:
	UPROPERTY()
	FVyUpdateWalletSecurityRequest Data{};
};
//RESPONSE [ViewWalletResult]
USTRUCT(BlueprintType)
struct VENLY_API FVyUpdateSecurityResponse : public FVyApiResponse
{
	GENERATED_BODY();
	UPROPERTY(BlueprintReadOnly, Category="Venly") FVyWalletDto Result;
};

//ON COMPLETE DELEGATE
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_OneParam(FVyOnUpdateSecurityCompleteBP, FVyUpdateSecurityResponse, Result);
