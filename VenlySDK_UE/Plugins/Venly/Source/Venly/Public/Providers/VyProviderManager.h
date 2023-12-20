// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "VyEnums.h"
#include "Subsystems/EngineSubsystem.h"
#include "VyProviderManager.generated.h"

class UVyCore;
class UVyProviderBase;
enum class EVyProviderType : uint8;

/**
 * 
 */
UCLASS()
class VENLY_API UVyProviderManager : public UEngineSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, BlueprintInternalUseOnly)
	static UVyProviderManager* GetSelf() { return  GEngine->GetEngineSubsystem<UVyProviderManager>(); }

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	void EndPlay();

	bool IsProviderAvailable(EVyProviderType ProviderType) const;
	bool IsProviderAvailable(EVyProviderType ProviderType, FString& errorMsg) const;
	UVyProviderBase* CreateProvider(EVyProviderType ProviderType, UVyCore* BackendCore, FString& errorMsg) const;

	void BindCustomProvider(UVyProviderBase* _CustomProvider);

private:
	//Constants
	const FName NAME_VenlyPlayFabModule{ FName("VenlyPlayFab") };
	const FName NAME_VenlyBeamableModule{ FName("VenlyBeamable") };

	bool DoesExternalProviderExist(EVyProviderType ProviderType, const FString& ModuleName, FString& errorMsg) const;
	UVyProviderBase* CreateExternalProvider(UVyCore* BackendCore, const FName& ModuleName, FString& errorMsg) const;

	UPROPERTY()
	UVyProviderBase* CustomProvider{ nullptr };
};
