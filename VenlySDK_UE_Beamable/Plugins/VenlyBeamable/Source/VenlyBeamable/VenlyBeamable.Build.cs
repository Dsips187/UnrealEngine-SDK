// Copyright Epic Games, Inc. All Rights Reserved.

using Internal;
using UnrealBuildTool;

public class VenlyBeamable : ModuleRules
{
	public VenlyBeamable(ReadOnlyTargetRules Target) : base(Target)
	{
		bUseRTTI = true;
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
			new string[] {
			});
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
            }
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
                "Json",
                "JsonUtilities",
                "HTTP",
				"Venly"
                // ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
                "DeveloperSettings"

				// ... add private dependencies that you statically link with here ...	
			}
			);

        //PlayFab
        PrivateDependencyModuleNames.AddRange(new string[] { "BeamableCore", "BeamableCoreRuntime", "BeamableCoreBlueprintNodes" });


        DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
    }
}
