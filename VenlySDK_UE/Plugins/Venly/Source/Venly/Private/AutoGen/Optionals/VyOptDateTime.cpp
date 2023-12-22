#include "AutoGen/Optionals/VyOptDateTime.h"
#include "VyJsonUtils.h"

FVyOptDateTime::FVyOptDateTime()
{
	Val = {};
	IsSet = false;
}

FVyOptDateTime::FVyOptDateTime(FDateTime Val) : Val(Val)
{
	IsSet = true;
}

const void* FVyOptDateTime::GetAddr() const { return &Val; }

void FVyOptDateTime::Set(const void* Data)
{
	Val = *((FDateTime*)Data);
	IsSet = true;
}

TSharedPtr<FJsonValue> FVyOptDateTime::GetJsonValue() const
{
	if (!IsSet) return Super::GetJsonValue();
	
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	return VyJsonUtils::UPropertyToJsonValue(prop, &Val);
}

bool FVyOptDateTime::SetJsonValue(const TSharedPtr<FJsonValue>& JsonValue)
{
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	IsSet = VyJsonUtils::JsonValueToUProperty(JsonValue, prop, &Val);
	return IsSet;
}