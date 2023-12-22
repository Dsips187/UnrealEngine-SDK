#pragma once

#include "CoreMinimal.h"
#include "BeamableCore/Public/AutoGen/GetManifestResponse.h"

#include "GetManifestResponseLibrary.generated.h"


UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UGetManifestResponseLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Beam|Json", DisplayName="Beam - GetManifestResponse To JSON String")
	static FString GetManifestResponseToJsonString(const UGetManifestResponse* Serializable, const bool Pretty);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Make GetManifestResponse", meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer", NativeMakeFunc))
	static UGetManifestResponse* Make(UManifestView* Manifest, UObject* Outer);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Break GetManifestResponse", meta=(NativeBreakFunc))
	static void Break(const UGetManifestResponse* Serializable, UManifestView*& Manifest);
};