#include "AutoGen/Optionals/VyOptChain.h"
#include "VyJsonUtils.h"

FVyOptChain::FVyOptChain()
{
	Val = {};
	IsSet = false;
}

FVyOptChain::FVyOptChain(EVyChain Val) : Val(Val)
{
	IsSet = true;
}

const void* FVyOptChain::GetAddr() const { return &Val; }

void FVyOptChain::Set(const void* Data)
{
	Val = *((EVyChain*)Data);
	IsSet = true;
}

TSharedPtr<FJsonValue> FVyOptChain::GetJsonValue() const
{
	if (!IsSet) return Super::GetJsonValue();
	
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	return VyJsonUtils::UPropertyToJsonValue(prop, &Val);
}

bool FVyOptChain::SetJsonValue(const TSharedPtr<FJsonValue>& JsonValue)
{
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	IsSet = VyJsonUtils::JsonValueToUProperty(JsonValue, prop, &Val);
	return IsSet;
}