#include "AutoGen/Optionals/VyOptWalletImportType.h"
#include "VyJsonUtils.h"

FVyOptWalletImportType::FVyOptWalletImportType()
{
	Val = {};
	IsSet = false;
}

FVyOptWalletImportType::FVyOptWalletImportType(EVyWalletImportType Val) : Val(Val)
{
	IsSet = true;
}

const void* FVyOptWalletImportType::GetAddr() const { return &Val; }

void FVyOptWalletImportType::Set(const void* Data)
{
	Val = *((EVyWalletImportType*)Data);
	IsSet = true;
}

TSharedPtr<FJsonValue> FVyOptWalletImportType::GetJsonValue() const
{
	if (!IsSet) return Super::GetJsonValue();
	
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	return VyJsonUtils::UPropertyToJsonValue(prop, &Val);
}

bool FVyOptWalletImportType::SetJsonValue(const TSharedPtr<FJsonValue>& JsonValue)
{
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	IsSet = VyJsonUtils::JsonValueToUProperty(JsonValue, prop, &Val);
	return IsSet;
}