#include "AutoGen/Optionals/VyOptCurrencyType.h"
#include "VyJsonUtils.h"

FVyOptCurrencyType::FVyOptCurrencyType()
{
	Val = {};
	IsSet = false;
}

FVyOptCurrencyType::FVyOptCurrencyType(EVyCurrencyType Val) : Val(Val)
{
	IsSet = true;
}

const void* FVyOptCurrencyType::GetAddr() const { return &Val; }

void FVyOptCurrencyType::Set(const void* Data)
{
	Val = *((EVyCurrencyType*)Data);
	IsSet = true;
}

TSharedPtr<FJsonValue> FVyOptCurrencyType::GetJsonValue() const
{
	if (!IsSet) return Super::GetJsonValue();
	
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	return VyJsonUtils::UPropertyToJsonValue(prop, &Val);
}

bool FVyOptCurrencyType::SetJsonValue(const TSharedPtr<FJsonValue>& JsonValue)
{
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	IsSet = VyJsonUtils::JsonValueToUProperty(JsonValue, prop, &Val);
	return IsSet;
}