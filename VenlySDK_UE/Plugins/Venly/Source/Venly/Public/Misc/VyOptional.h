#pragma once

#include "VyOptional.generated.h"

USTRUCT(BlueprintType)
struct VENLY_API FVyOptional
{
	GENERATED_BODY()
		virtual ~FVyOptional();

	UPROPERTY(BlueprintReadOnly, Category = "Venly")
	bool IsSet = false;

	virtual const void* GetAddr() const;

	virtual bool TryGet(void* OutData, size_t& OutSize) const;;

	virtual void Set(const void* Data);

	virtual TSharedPtr<FJsonValue> GetJsonValue() const { return nullptr; }
	virtual bool SetJsonValue(const TSharedPtr<FJsonValue>& JsonValue) { return false; }
	virtual bool ToString(FString& value) const;

	template <typename T>
	static void Set(FVyOptional* Optional, const T* Data) { Optional->Set(static_cast<const void*>(Data)); }

	template <typename T>
	static void Reset(FVyOptional* Optional)
	{
		T defaultVal = T{};
		Optional->Set(static_cast<void*>(&defaultVal));
		Optional->IsSet = false;
	}

	template <typename T>
	static const T& GetValue(const FVyOptional* Optional) { return *static_cast<const T*>(Optional->GetAddr()); }
};
