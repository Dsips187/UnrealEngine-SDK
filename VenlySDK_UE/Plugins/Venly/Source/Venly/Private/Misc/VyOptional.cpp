#include "VyOptional.h"

FVyOptional::~FVyOptional() = default;

const void* FVyOptional::GetAddr() const
{
	ensure(false);
	return nullptr;
}

bool FVyOptional::TryGet(void* OutData, size_t& OutSize) const
{
	ensure(false);
	return false;
}

void FVyOptional::Set(const void* Data)
{
	ensure(false);
}

bool FVyOptional::ToString(FString& Value) const
{
	const auto Writer = TJsonWriterFactory<>::Create(&Value);
	FJsonSerializer::Serialize(GetJsonValue(), TEXT(""), Writer);

	FRegexMatcher SanitizeRegex{ FRegexPattern{TEXT("^,\\s+\"?([a-zA-Z0-9]+)[\"]?")}, Value };
	if (SanitizeRegex.FindNext())
	{
		Value = SanitizeRegex.GetCaptureGroup(1);
		return !Value.IsEmpty();
	}

	return false;
}
