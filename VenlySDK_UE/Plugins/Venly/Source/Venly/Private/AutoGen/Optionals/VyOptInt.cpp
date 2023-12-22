#include "AutoGen/Optionals/VyOptInt.h"
#include "VyJsonUtils.h"

FVyOptInt::FVyOptInt()
{
	Val = {};
	IsSet = false;
}

FVyOptInt::FVyOptInt(int Val) : Val(Val)
{
	IsSet = true;
}

const void* FVyOptInt::GetAddr() const { return &Val; }

void FVyOptInt::Set(const void* Data)
{
	Val = *((int*)Data);
	IsSet = true;
}

TSharedPtr<FJsonValue> FVyOptInt::GetJsonValue() const
{
	if (!IsSet) return Super::GetJsonValue();
	
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	return VyJsonUtils::UPropertyToJsonValue(prop, &Val);
}

bool FVyOptInt::SetJsonValue(const TSharedPtr<FJsonValue>& JsonValue)
{
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	IsSet = VyJsonUtils::JsonValueToUProperty(JsonValue, prop, &Val);
	return IsSet;
}