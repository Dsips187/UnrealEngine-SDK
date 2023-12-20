#include "AutoGen/Optionals/VyOptTokenDestinationArray.h"
#include "VyJsonUtils.h"

FVyOptTokenDestinationArray::FVyOptTokenDestinationArray()
{
	Val = {};
	IsSet = false;
}

FVyOptTokenDestinationArray::FVyOptTokenDestinationArray(TArray<FVyTokenDestinationDto> Val) : Val(Val)
{
	IsSet = true;
}

const void* FVyOptTokenDestinationArray::GetAddr() const { return &Val; }

void FVyOptTokenDestinationArray::Set(const void* Data)
{
	Val = *((TArray<FVyTokenDestinationDto>*)Data);
	IsSet = true;
}

TSharedPtr<FJsonValue> FVyOptTokenDestinationArray::GetJsonValue() const
{
	if (!IsSet) return Super::GetJsonValue();
	
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	return VyJsonUtils::UPropertyToJsonValue(prop, &Val);
}

bool FVyOptTokenDestinationArray::SetJsonValue(const TSharedPtr<FJsonValue>& JsonValue)
{
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	IsSet = VyJsonUtils::JsonValueToUProperty(JsonValue, prop, &Val);
	return IsSet;
}