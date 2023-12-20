#include "AutoGen/Optionals/VyOptOrderType.h"
#include "VyJsonUtils.h"

FVyOptOrderType::FVyOptOrderType()
{
	Val = {};
	IsSet = false;
}

FVyOptOrderType::FVyOptOrderType(EVyOrderType Val) : Val(Val)
{
	IsSet = true;
}

const void* FVyOptOrderType::GetAddr() const { return &Val; }

void FVyOptOrderType::Set(const void* Data)
{
	Val = *((EVyOrderType*)Data);
	IsSet = true;
}

TSharedPtr<FJsonValue> FVyOptOrderType::GetJsonValue() const
{
	if (!IsSet) return Super::GetJsonValue();
	
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	return VyJsonUtils::UPropertyToJsonValue(prop, &Val);
}

bool FVyOptOrderType::SetJsonValue(const TSharedPtr<FJsonValue>& JsonValue)
{
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	IsSet = VyJsonUtils::JsonValueToUProperty(JsonValue, prop, &Val);
	return IsSet;
}