#include "AutoGen/Optionals/VyOptTypeValueArray.h"
#include "VyJsonUtils.h"

FVyOptTypeValueArray::FVyOptTypeValueArray()
{
	Val = {};
	IsSet = false;
}

FVyOptTypeValueArray::FVyOptTypeValueArray(TArray<FVyTypeValueDto> Val) : Val(Val)
{
	IsSet = true;
}

const void* FVyOptTypeValueArray::GetAddr() const { return &Val; }

void FVyOptTypeValueArray::Set(const void* Data)
{
	Val = *((TArray<FVyTypeValueDto>*)Data);
	IsSet = true;
}

TSharedPtr<FJsonValue> FVyOptTypeValueArray::GetJsonValue() const
{
	if (!IsSet) return Super::GetJsonValue();
	
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	return VyJsonUtils::UPropertyToJsonValue(prop, &Val);
}

bool FVyOptTypeValueArray::SetJsonValue(const TSharedPtr<FJsonValue>& JsonValue)
{
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	IsSet = VyJsonUtils::JsonValueToUProperty(JsonValue, prop, &Val);
	return IsSet;
}