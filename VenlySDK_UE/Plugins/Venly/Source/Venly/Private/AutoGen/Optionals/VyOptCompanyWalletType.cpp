#include "AutoGen/Optionals/VyOptCompanyWalletType.h"
#include "VyJsonUtils.h"

FVyOptCompanyWalletType::FVyOptCompanyWalletType()
{
	Val = {};
	IsSet = false;
}

FVyOptCompanyWalletType::FVyOptCompanyWalletType(EVyCompanyWalletType Val) : Val(Val)
{
	IsSet = true;
}

const void* FVyOptCompanyWalletType::GetAddr() const { return &Val; }

void FVyOptCompanyWalletType::Set(const void* Data)
{
	Val = *((EVyCompanyWalletType*)Data);
	IsSet = true;
}

TSharedPtr<FJsonValue> FVyOptCompanyWalletType::GetJsonValue() const
{
	if (!IsSet) return Super::GetJsonValue();
	
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	return VyJsonUtils::UPropertyToJsonValue(prop, &Val);
}

bool FVyOptCompanyWalletType::SetJsonValue(const TSharedPtr<FJsonValue>& JsonValue)
{
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	IsSet = VyJsonUtils::JsonValueToUProperty(JsonValue, prop, &Val);
	return IsSet;
}