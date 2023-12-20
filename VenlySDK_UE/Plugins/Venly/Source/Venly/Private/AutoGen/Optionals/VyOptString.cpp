#include "AutoGen/Optionals/VyOptString.h"
#include "VyJsonUtils.h"

FVyOptString::FVyOptString()
{
	Val = {};
	IsSet = false;
}

FVyOptString::FVyOptString(FString Val) : Val(Val)
{
	IsSet = true;
}

const void* FVyOptString::GetAddr() const { return &Val; }

void FVyOptString::Set(const void* Data)
{
	Val = *((FString*)Data);
	IsSet = true;
}

TSharedPtr<FJsonValue> FVyOptString::GetJsonValue() const
{
	if (!IsSet) return Super::GetJsonValue();
	
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	return VyJsonUtils::UPropertyToJsonValue(prop, &Val);
}

bool FVyOptString::SetJsonValue(const TSharedPtr<FJsonValue>& JsonValue)
{
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	IsSet = VyJsonUtils::JsonValueToUProperty(JsonValue, prop, &Val);
	return IsSet;
}