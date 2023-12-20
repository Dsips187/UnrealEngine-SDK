#include "AutoGen/Optionals/VyOptNetwork.h"
#include "VyJsonUtils.h"

FVyOptNetwork::FVyOptNetwork()
{
	Val = {};
	IsSet = false;
}

FVyOptNetwork::FVyOptNetwork(FVyNetworkDto Val) : Val(Val)
{
	IsSet = true;
}

const void* FVyOptNetwork::GetAddr() const { return &Val; }

void FVyOptNetwork::Set(const void* Data)
{
	Val = *((FVyNetworkDto*)Data);
	IsSet = true;
}

TSharedPtr<FJsonValue> FVyOptNetwork::GetJsonValue() const
{
	if (!IsSet) return Super::GetJsonValue();
	
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	return VyJsonUtils::UPropertyToJsonValue(prop, &Val);
}

bool FVyOptNetwork::SetJsonValue(const TSharedPtr<FJsonValue>& JsonValue)
{
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	IsSet = VyJsonUtils::JsonValueToUProperty(JsonValue, prop, &Val);
	return IsSet;
}