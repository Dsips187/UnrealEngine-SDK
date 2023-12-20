#include "AutoGen/Optionals/VyOptRelationType.h"
#include "VyJsonUtils.h"

FVyOptRelationType::FVyOptRelationType()
{
	Val = {};
	IsSet = false;
}

FVyOptRelationType::FVyOptRelationType(EVyRelationType Val) : Val(Val)
{
	IsSet = true;
}

const void* FVyOptRelationType::GetAddr() const { return &Val; }

void FVyOptRelationType::Set(const void* Data)
{
	Val = *((EVyRelationType*)Data);
	IsSet = true;
}

TSharedPtr<FJsonValue> FVyOptRelationType::GetJsonValue() const
{
	if (!IsSet) return Super::GetJsonValue();
	
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	return VyJsonUtils::UPropertyToJsonValue(prop, &Val);
}

bool FVyOptRelationType::SetJsonValue(const TSharedPtr<FJsonValue>& JsonValue)
{
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	IsSet = VyJsonUtils::JsonValueToUProperty(JsonValue, prop, &Val);
	return IsSet;
}