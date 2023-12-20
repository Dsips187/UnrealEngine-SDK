#include "AutoGen/Optionals/VyOptFulfillmentState.h"
#include "VyJsonUtils.h"

FVyOptFulfillmentState::FVyOptFulfillmentState()
{
	Val = {};
	IsSet = false;
}

FVyOptFulfillmentState::FVyOptFulfillmentState(EVyFulfillmentState Val) : Val(Val)
{
	IsSet = true;
}

const void* FVyOptFulfillmentState::GetAddr() const { return &Val; }

void FVyOptFulfillmentState::Set(const void* Data)
{
	Val = *((EVyFulfillmentState*)Data);
	IsSet = true;
}

TSharedPtr<FJsonValue> FVyOptFulfillmentState::GetJsonValue() const
{
	if (!IsSet) return Super::GetJsonValue();
	
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	return VyJsonUtils::UPropertyToJsonValue(prop, &Val);
}

bool FVyOptFulfillmentState::SetJsonValue(const TSharedPtr<FJsonValue>& JsonValue)
{
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	IsSet = VyJsonUtils::JsonValueToUProperty(JsonValue, prop, &Val);
	return IsSet;
}