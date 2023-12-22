#pragma once

#include "CoreMinimal.h"
#include "BeamableCore/Public/AutoGen/UploadRequestsFromPortal.h"

#include "UploadRequestsFromPortalLibrary.generated.h"


UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UUploadRequestsFromPortalLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Beam|Json", DisplayName="Beam - UploadRequestsFromPortal To JSON String")
	static FString UploadRequestsFromPortalToJsonString(const UUploadRequestsFromPortal* Serializable, const bool Pretty);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Make UploadRequestsFromPortal", meta=(DefaultToSelf="Outer", AdvancedDisplay="PlayerId, Outer", NativeMakeFunc))
	static UUploadRequestsFromPortal* Make(TArray<UUploadRequestFromPortal*> Request, FOptionalInt64 PlayerId, UObject* Outer);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Break UploadRequestsFromPortal", meta=(NativeBreakFunc))
	static void Break(const UUploadRequestsFromPortal* Serializable, TArray<UUploadRequestFromPortal*>& Request, FOptionalInt64& PlayerId);
};