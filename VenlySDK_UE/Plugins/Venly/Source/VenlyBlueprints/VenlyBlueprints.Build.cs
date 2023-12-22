// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class VenlyBlueprints : ModuleRules
{
	public VenlyBlueprints(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
				//"VenlyBlueprints/Public"
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
				"VenlyBlueprints/Public/Autogen",
                "Venly/Public/AutoGen",
                "Venly/Public/AutoGen/Models",
                "Venly/Public/AutoGen/Optionals",
                "Venly/Public/Models",
                "Venly/Public/Utils",
                "Venly/Public/Misc"
            }
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"Engine",
				"CoreUObject",
				"Venly",
				"UnrealEd",
                "BlueprintGraph",
                "GraphEditor",
				"EditorStyle",
				"Kismet",
				"KismetCompiler",
				"Projects"
            }
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
                "CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
            }
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
