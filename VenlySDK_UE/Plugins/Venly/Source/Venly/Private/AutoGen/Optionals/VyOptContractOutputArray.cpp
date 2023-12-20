#include "AutoGen/Optionals/VyOptContractOutputArray.h"
#include "VyJsonUtils.h"

FVyOptContractOutputArray::FVyOptContractOutputArray()
{
	Val = {};
	IsSet = false;
}

FVyOptContractOutputArray::FVyOptContractOutputArray(TArray<FVyContractOutputDto> Val) : Val(Val)
{
	IsSet = true;
}

const void* FVyOptContractOutputArray::GetAddr() const { return &Val; }

void FVyOptContractOutputArray::Set(const void* Data)
{
	Val = *((TArray<FVyContractOutputDto>*)Data);
	IsSet = true;
}

TSharedPtr<FJsonValue> FVyOptContractOutputArray::GetJsonValue() const
{
	if (!IsSet) return Super::GetJsonValue();
	
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	return VyJsonUtils::UPropertyToJsonValue(prop, &Val);
}

bool FVyOptContractOutputArray::SetJsonValue(const TSharedPtr<FJsonValue>& JsonValue)
{
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	IsSet = VyJsonUtils::JsonValueToUProperty(JsonValue, prop, &Val);
	return IsSet;
}