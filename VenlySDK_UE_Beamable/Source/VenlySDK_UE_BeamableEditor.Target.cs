// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class VenlySDK_UE_BeamableEditorTarget : TargetRules
{
	public VenlySDK_UE_BeamableEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V3;
		//CppStandard = CppStandardVersion.Cpp17;

		ExtraModuleNames.AddRange( new string[] { "VenlySDK_UE_Beamable" } );
	}
}
