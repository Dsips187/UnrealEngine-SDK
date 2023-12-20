// Fill out your copyright notice in the Description page of Project Settings.
#include "VyEditorCommands.h"

#define LOCTEXT_NAMESPACE "FVenlyEditorModule"

void FVyEditorCommands::RegisterCommands()
{
	UI_COMMAND(OpenSdkManagerCommand, "Venly", "Opens the Venly SDK Manager!", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE