#include "AutoGen/Optionals/VyOptTokenAttributeArray.h"
#include "VyJsonUtils.h"

FVyOptTokenAttributeArray::FVyOptTokenAttributeArray()
{
	Val = {};
	IsSet = false;
}

FVyOptTokenAttributeArray::FVyOptTokenAttributeArray(TArray<FVyTokenAttributeDto> Val) : Val(Val)
{
	IsSet = true;
}

const void* FVyOptTokenAttributeArray::GetAddr() const { return &Val; }

void FVyOptTokenAttributeArray::Set(const void* Data)
{
	Val = *((TArray<FVyTokenAttributeDto>*)Data);
	IsSet = true;
}

TSharedPtr<FJsonValue> FVyOptTokenAttributeArray::GetJsonValue() const
{
	if (!IsSet) return Super::GetJsonValue();
	
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	return VyJsonUtils::UPropertyToJsonValue(prop, &Val);
}

bool FVyOptTokenAttributeArray::SetJsonValue(const TSharedPtr<FJsonValue>& JsonValue)
{
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	IsSet = VyJsonUtils::JsonValueToUProperty(JsonValue, prop, &Val);
	return IsSet;
}