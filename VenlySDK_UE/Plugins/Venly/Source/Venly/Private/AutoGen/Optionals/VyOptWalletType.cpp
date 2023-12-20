#include "AutoGen/Optionals/VyOptWalletType.h"
#include "VyJsonUtils.h"

FVyOptWalletType::FVyOptWalletType()
{
	Val = {};
	IsSet = false;
}

FVyOptWalletType::FVyOptWalletType(EVyWalletType Val) : Val(Val)
{
	IsSet = true;
}

const void* FVyOptWalletType::GetAddr() const { return &Val; }

void FVyOptWalletType::Set(const void* Data)
{
	Val = *((EVyWalletType*)Data);
	IsSet = true;
}

TSharedPtr<FJsonValue> FVyOptWalletType::GetJsonValue() const
{
	if (!IsSet) return Super::GetJsonValue();
	
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	return VyJsonUtils::UPropertyToJsonValue(prop, &Val);
}

bool FVyOptWalletType::SetJsonValue(const TSharedPtr<FJsonValue>& JsonValue)
{
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	IsSet = VyJsonUtils::JsonValueToUProperty(JsonValue, prop, &Val);
	return IsSet;
}