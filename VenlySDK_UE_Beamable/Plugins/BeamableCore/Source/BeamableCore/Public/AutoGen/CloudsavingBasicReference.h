#pragma once

#include "CoreMinimal.h"

#include "Serialization/BeamJsonSerializable.h"


#include "CloudsavingBasicReference.generated.h"

UCLASS(BlueprintType, Category="Beam")
class BEAMABLECORE_API UCloudsavingBasicReference : public UObject, public IBeamJsonSerializableUObject
{
	GENERATED_BODY()

public:
	

	

	virtual void BeamSerializeProperties(TUnrealJsonSerializer& Serializer) const override;
	virtual void BeamSerializeProperties(TUnrealPrettyJsonSerializer& Serializer) const override;
	virtual void BeamDeserializeProperties(const TSharedPtr<FJsonObject>& Bag) override;
	
};