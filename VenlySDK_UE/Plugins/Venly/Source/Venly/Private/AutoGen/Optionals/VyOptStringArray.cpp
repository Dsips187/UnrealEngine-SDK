#include "AutoGen/Optionals/VyOptStringArray.h"
#include "VyJsonUtils.h"

FVyOptStringArray::FVyOptStringArray()
{
	Val = {};
	IsSet = false;
}

FVyOptStringArray::FVyOptStringArray(TArray<FString> Val) : Val(Val)
{
	IsSet = true;
}

const void* FVyOptStringArray::GetAddr() const { return &Val; }

void FVyOptStringArray::Set(const void* Data)
{
	Val = *((TArray<FString>*)Data);
	IsSet = true;
}

TSharedPtr<FJsonValue> FVyOptStringArray::GetJsonValue() const
{
	if (!IsSet) return Super::GetJsonValue();
	
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	return VyJsonUtils::UPropertyToJsonValue(prop, &Val);
}

bool FVyOptStringArray::SetJsonValue(const TSharedPtr<FJsonValue>& JsonValue)
{
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	IsSet = VyJsonUtils::JsonValueToUProperty(JsonValue, prop, &Val);
	return IsSet;
}