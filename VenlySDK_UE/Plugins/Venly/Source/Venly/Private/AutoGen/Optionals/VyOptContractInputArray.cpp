#include "AutoGen/Optionals/VyOptContractInputArray.h"
#include "VyJsonUtils.h"

FVyOptContractInputArray::FVyOptContractInputArray()
{
	Val = {};
	IsSet = false;
}

FVyOptContractInputArray::FVyOptContractInputArray(TArray<FVyContractInputDto> Val) : Val(Val)
{
	IsSet = true;
}

const void* FVyOptContractInputArray::GetAddr() const { return &Val; }

void FVyOptContractInputArray::Set(const void* Data)
{
	Val = *((TArray<FVyContractInputDto>*)Data);
	IsSet = true;
}

TSharedPtr<FJsonValue> FVyOptContractInputArray::GetJsonValue() const
{
	if (!IsSet) return Super::GetJsonValue();
	
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	return VyJsonUtils::UPropertyToJsonValue(prop, &Val);
}

bool FVyOptContractInputArray::SetJsonValue(const TSharedPtr<FJsonValue>& JsonValue)
{
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	IsSet = VyJsonUtils::JsonValueToUProperty(JsonValue, prop, &Val);
	return IsSet;
}