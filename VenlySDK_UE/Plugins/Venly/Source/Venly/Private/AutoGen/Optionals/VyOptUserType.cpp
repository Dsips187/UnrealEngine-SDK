#include "AutoGen/Optionals/VyOptUserType.h"
#include "VyJsonUtils.h"

FVyOptUserType::FVyOptUserType()
{
	Val = {};
	IsSet = false;
}

FVyOptUserType::FVyOptUserType(EVyUserType Val) : Val(Val)
{
	IsSet = true;
}

const void* FVyOptUserType::GetAddr() const { return &Val; }

void FVyOptUserType::Set(const void* Data)
{
	Val = *((EVyUserType*)Data);
	IsSet = true;
}

TSharedPtr<FJsonValue> FVyOptUserType::GetJsonValue() const
{
	if (!IsSet) return Super::GetJsonValue();
	
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	return VyJsonUtils::UPropertyToJsonValue(prop, &Val);
}

bool FVyOptUserType::SetJsonValue(const TSharedPtr<FJsonValue>& JsonValue)
{
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	IsSet = VyJsonUtils::JsonValueToUProperty(JsonValue, prop, &Val);
	return IsSet;
}