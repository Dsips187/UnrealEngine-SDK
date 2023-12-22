#include "AutoGen/Optionals/VyOptStorage.h"
#include "VyJsonUtils.h"

FVyOptStorage::FVyOptStorage()
{
	Val = {};
	IsSet = false;
}

FVyOptStorage::FVyOptStorage(FVyStorageDto Val) : Val(Val)
{
	IsSet = true;
}

const void* FVyOptStorage::GetAddr() const { return &Val; }

void FVyOptStorage::Set(const void* Data)
{
	Val = *((FVyStorageDto*)Data);
	IsSet = true;
}

TSharedPtr<FJsonValue> FVyOptStorage::GetJsonValue() const
{
	if (!IsSet) return Super::GetJsonValue();
	
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	return VyJsonUtils::UPropertyToJsonValue(prop, &Val);
}

bool FVyOptStorage::SetJsonValue(const TSharedPtr<FJsonValue>& JsonValue)
{
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	IsSet = VyJsonUtils::JsonValueToUProperty(JsonValue, prop, &Val);
	return IsSet;
}