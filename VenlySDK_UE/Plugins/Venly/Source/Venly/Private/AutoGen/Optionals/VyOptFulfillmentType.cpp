#include "AutoGen/Optionals/VyOptFulfillmentType.h"
#include "VyJsonUtils.h"

FVyOptFulfillmentType::FVyOptFulfillmentType()
{
	Val = {};
	IsSet = false;
}

FVyOptFulfillmentType::FVyOptFulfillmentType(EVyFulfillmentType Val) : Val(Val)
{
	IsSet = true;
}

const void* FVyOptFulfillmentType::GetAddr() const { return &Val; }

void FVyOptFulfillmentType::Set(const void* Data)
{
	Val = *((EVyFulfillmentType*)Data);
	IsSet = true;
}

TSharedPtr<FJsonValue> FVyOptFulfillmentType::GetJsonValue() const
{
	if (!IsSet) return Super::GetJsonValue();
	
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	return VyJsonUtils::UPropertyToJsonValue(prop, &Val);
}

bool FVyOptFulfillmentType::SetJsonValue(const TSharedPtr<FJsonValue>& JsonValue)
{
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	IsSet = VyJsonUtils::JsonValueToUProperty(JsonValue, prop, &Val);
	return IsSet;
}