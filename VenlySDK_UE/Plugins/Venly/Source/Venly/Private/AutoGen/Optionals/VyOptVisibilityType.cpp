#include "AutoGen/Optionals/VyOptVisibilityType.h"
#include "VyJsonUtils.h"

FVyOptVisibilityType::FVyOptVisibilityType()
{
	Val = {};
	IsSet = false;
}

FVyOptVisibilityType::FVyOptVisibilityType(EVyVisibilityType Val) : Val(Val)
{
	IsSet = true;
}

const void* FVyOptVisibilityType::GetAddr() const { return &Val; }

void FVyOptVisibilityType::Set(const void* Data)
{
	Val = *((EVyVisibilityType*)Data);
	IsSet = true;
}

TSharedPtr<FJsonValue> FVyOptVisibilityType::GetJsonValue() const
{
	if (!IsSet) return Super::GetJsonValue();
	
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	return VyJsonUtils::UPropertyToJsonValue(prop, &Val);
}

bool FVyOptVisibilityType::SetJsonValue(const TSharedPtr<FJsonValue>& JsonValue)
{
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	IsSet = VyJsonUtils::JsonValueToUProperty(JsonValue, prop, &Val);
	return IsSet;
}