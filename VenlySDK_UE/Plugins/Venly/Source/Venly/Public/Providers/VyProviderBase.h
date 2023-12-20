// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Models/VyCoreModels.h"

#include "VyProviderBase.generated.h"

class UVyCore;

/**
 * 
 */
UCLASS(Blueprintable, Abstract)
class VENLY_API UVyProviderBase : public UObject
{
	GENERATED_BODY()

public:
	void Initialize();
	void Deinitialize();

	virtual ~UVyProviderBase() {}

	//UFUNCTION(BlueprintInternalUseOnly)
	virtual void ProcessRequest(FVyRequestContext& Context, const FVyOnComplete_ResponseContext& OnComplete);
	virtual void OnRequestComplete(FVyRequestId Id) {}

protected:

	virtual void OnInitialize(){};
	virtual void OnDeinitialize(){};

	UVyCore* GetBackend();

	UPROPERTY(BlueprintReadOnly, Category="Venly")
	bool IsInitialized;

private:
	UPROPERTY()
	UVyCore* Backend;
};
