// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Editor/Blutility/Classes/EditorUtilityWidget.h"
#include "VySettingsBaseWidget.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class VENLYEDITOR_API UVySettingsBaseWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void RefreshData();
};
