#include "AutoGen/Optionals/VyOptSignatureRequestBase.h"
#include "VyJsonUtils.h"

FVyOptSignatureRequestBase::FVyOptSignatureRequestBase()
{
	Val = {};
	IsSet = false;
}

FVyOptSignatureRequestBase::FVyOptSignatureRequestBase(FVySignatureRequestBase Val) : Val(Val)
{
	IsSet = true;
}

const void* FVyOptSignatureRequestBase::GetAddr() const { return &Val; }

void FVyOptSignatureRequestBase::Set(const void* Data)
{
	Val = *((FVySignatureRequestBase*)Data);
	IsSet = true;
}

TSharedPtr<FJsonValue> FVyOptSignatureRequestBase::GetJsonValue() const
{
	if (!IsSet) return Super::GetJsonValue();
	
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	return VyJsonUtils::UPropertyToJsonValue(prop, &Val);
}

bool FVyOptSignatureRequestBase::SetJsonValue(const TSharedPtr<FJsonValue>& JsonValue)
{
	const auto prop = StaticStruct()->FindPropertyByName(TEXT("Val"));
	IsSet = VyJsonUtils::JsonValueToUProperty(JsonValue, prop, &Val);
	return IsSet;
}