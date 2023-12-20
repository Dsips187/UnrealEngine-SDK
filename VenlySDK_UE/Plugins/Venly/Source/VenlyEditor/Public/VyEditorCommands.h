// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VyCoreStyle.h"

/**
 * 
 */
class VENLYEDITOR_API FVyEditorCommands : public TCommands<FVyEditorCommands>
{
public:
	FVyEditorCommands()
		: TCommands<FVyEditorCommands>
		(
			TEXT("VenlyEditor"),
			NSLOCTEXT("Contexts", "VenlyEditor", "Venly Plugin"),
			NAME_None,
			FVyCoreStyle::GetRef().GetStyleSetName()
		){}

	virtual void RegisterCommands() override;


	TSharedPtr<FUICommandInfo> OpenSdkManagerCommand;
};
