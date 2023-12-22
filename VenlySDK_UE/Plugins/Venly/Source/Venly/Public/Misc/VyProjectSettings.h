// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Models/VyCoreModels.h"
#include "Engine/DeveloperSettings.h"
#include "VyProjectSettings.generated.h"

/**
 * 
 */
UCLASS(Config=Game, defaultconfig, meta=(DisplayName="Venly"))
class VENLY_API UVyProjectSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	virtual FName GetContainerName() const override { return FName("Project"); }
	virtual FName GetSectionName() const override { return FName("Venly"); }
	virtual FName GetCategoryName() const override { return FName("Plugins"); }

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "General")
	EVyEnvironment Environment;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "General")
	EVyProviderType ProviderType;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Provider|PlayFab")
	FString PlayFabCloudFunction;
};
