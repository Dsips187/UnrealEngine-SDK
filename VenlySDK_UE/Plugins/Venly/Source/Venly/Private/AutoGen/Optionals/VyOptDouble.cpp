#include "AutoGen/Optionals/VyOptDouble.h"
#include "VyJsonUtils.h"

FVyOptDouble::FVyOptDouble()
{
	Val = {};
	IsSet = false;
}

FVyOptDouble::FVyOptDouble(double Val) : Val(Val)
{
	IsSet = true;
}

const void* FVyOptDouble::GetAddr() const { return &Val; }

void FVyOptDouble::Set(const void* Data)
{
	Val = *((double*)Data);
	IsSet = true;
}

TSharedPtr<FJsonValue> FVyOptDouble::GetJsonValue() const
{
	if (!IsSet) return Super::GetJsonValue();
	
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	return VyJsonUtils::UPropertyToJsonValue(prop, &Val);
}

bool FVyOptDouble::SetJsonValue(const TSharedPtr<FJsonValue>& JsonValue)
{
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	IsSet = VyJsonUtils::JsonValueToUProperty(JsonValue, prop, &Val);
	return IsSet;
}