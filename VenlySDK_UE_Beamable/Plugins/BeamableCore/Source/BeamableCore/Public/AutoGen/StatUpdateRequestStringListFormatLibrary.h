#pragma once

#include "CoreMinimal.h"
#include "BeamableCore/Public/AutoGen/StatUpdateRequestStringListFormat.h"

#include "StatUpdateRequestStringListFormatLibrary.generated.h"


UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UStatUpdateRequestStringListFormatLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Beam|Json", DisplayName="Beam - StatUpdateRequestStringListFormat To JSON String")
	static FString StatUpdateRequestStringListFormatToJsonString(const UStatUpdateRequestStringListFormat* Serializable, const bool Pretty);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Make StatUpdateRequestStringListFormat", meta=(DefaultToSelf="Outer", AdvancedDisplay="Set, Outer", NativeMakeFunc))
	static UStatUpdateRequestStringListFormat* Make(FOptionalArrayOfStatStringListEntry Set, UObject* Outer);

	UFUNCTION(BlueprintPure, Category="Beam|Backend", DisplayName="Beam - Break StatUpdateRequestStringListFormat", meta=(NativeBreakFunc))
	static void Break(const UStatUpdateRequestStringListFormat* Serializable, FOptionalArrayOfStatStringListEntry& Set);
};