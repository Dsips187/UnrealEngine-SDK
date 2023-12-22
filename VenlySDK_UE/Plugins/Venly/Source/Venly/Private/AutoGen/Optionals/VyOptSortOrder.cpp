#include "AutoGen/Optionals/VyOptSortOrder.h"
#include "VyJsonUtils.h"

FVyOptSortOrder::FVyOptSortOrder()
{
	Val = {};
	IsSet = false;
}

FVyOptSortOrder::FVyOptSortOrder(EVySortOrder Val) : Val(Val)
{
	IsSet = true;
}

const void* FVyOptSortOrder::GetAddr() const { return &Val; }

void FVyOptSortOrder::Set(const void* Data)
{
	Val = *((EVySortOrder*)Data);
	IsSet = true;
}

TSharedPtr<FJsonValue> FVyOptSortOrder::GetJsonValue() const
{
	if (!IsSet) return Super::GetJsonValue();
	
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	return VyJsonUtils::UPropertyToJsonValue(prop, &Val);
}

bool FVyOptSortOrder::SetJsonValue(const TSharedPtr<FJsonValue>& JsonValue)
{
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	IsSet = VyJsonUtils::JsonValueToUProperty(JsonValue, prop, &Val);
	return IsSet;
}