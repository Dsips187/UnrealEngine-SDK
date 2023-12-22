#pragma once

#include "CoreMinimal.h"
#include "VyNode_Api.h"
#include "VyNode_Wallet_GetWalletEvents.generated.h"

UCLASS()
class VENLYBLUEPRINTS_API UVyNode_Wallet_GetWalletEvents : public UVyNode_Api
{
	GENERATED_BODY()
	
public:
	
	virtual UClass* GetApiClass() const override;
	virtual UScriptStruct* GetResponseType() const override;
	virtual FName GetSelfFunctionName() const override;
	virtual FName GetRequestFunctionName() const override;
	virtual FName GetOnCompleteDelegateName() const override;
	virtual FName GetApiName() const override;
	virtual FName GetAuthoredName() const override;
	
private:
	
	inline static const FName NAME_OnCompleteDelegate{TEXT("VyOnGetWalletEventsCompleteBP")};
	inline static const FName NAME_ApiName{TEXT("Wallet")};
	inline static const FName NAME_AuthoredName{TEXT("GetWalletEvents")};
};