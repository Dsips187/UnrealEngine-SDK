#include "AutoGen/Optionals/VyOptBool.h"
#include "VyJsonUtils.h"

FVyOptBool::FVyOptBool()
{
	Val = {};
	IsSet = false;
}

FVyOptBool::FVyOptBool(bool Val) : Val(Val)
{
	IsSet = true;
}

const void* FVyOptBool::GetAddr() const { return &Val; }

void FVyOptBool::Set(const void* Data)
{
	Val = *((bool*)Data);
	IsSet = true;
}

TSharedPtr<FJsonValue> FVyOptBool::GetJsonValue() const
{
	if (!IsSet) return Super::GetJsonValue();
	
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	return VyJsonUtils::UPropertyToJsonValue(prop, &Val);
}

bool FVyOptBool::SetJsonValue(const TSharedPtr<FJsonValue>& JsonValue)
{
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	IsSet = VyJsonUtils::JsonValueToUProperty(JsonValue, prop, &Val);
	return IsSet;
}