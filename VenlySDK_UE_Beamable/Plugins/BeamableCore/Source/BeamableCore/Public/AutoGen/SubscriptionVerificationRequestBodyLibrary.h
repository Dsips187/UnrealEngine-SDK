#pragma once

#include "CoreMinimal.h"
#include "BeamableCore/Public/AutoGen/SubscriptionVerificationRequestBody.h"

#include "SubscriptionVerificationRequestBodyLibrary.generated.h"


UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API USubscriptionVerificationRequestBodyLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Beam|Json", DisplayName="Beam - SubscriptionVerificationRequestBody To JSON String")
	static FString SubscriptionVerificationRequestBodyToJsonString(const USubscriptionVerificationRequestBody* Serializable, const bool Pretty);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Make SubscriptionVerificationRequestBody", meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer", NativeMakeFunc))
	static USubscriptionVerificationRequestBody* Make(FString HubMode, FString HubChallenge, FString HubVerifyToken, UObject* Outer);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Break SubscriptionVerificationRequestBody", meta=(NativeBreakFunc))
	static void Break(const USubscriptionVerificationRequestBody* Serializable, FString& HubMode, FString& HubChallenge, FString& HubVerifyToken);
};