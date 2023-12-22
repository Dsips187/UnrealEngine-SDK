// Copyright Epic Games, Inc. All Rights Reserved.

using Internal;
using UnrealBuildTool;

public class Venly : ModuleRules
{
	public Venly(ReadOnlyTargetRules Target) : base(Target)
	{
		bUseRTTI = true;
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        //bEnforceIWYU = true;
        //IWYUSupport = IWYUSupport.Full;

        //PrivatePCHHeaderFile = "Private/VenlyCorePCH.h";

        PublicIncludePaths.AddRange(
			new string[] {});
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
                "Venly/Public",
                "Venly/Public/AutoGen",
                "Venly/Public/AutoGen/Optionals",
                "Venly/Public/AutoGen/Models",
                "Venly/Public/AutoGen/Models/Wallet",
                "Venly/Public/AutoGen/Models/Nft",
                "Venly/Public/AutoGen/Models/Market",
				"Venly/Public/Misc",
                "Venly/Public/Models",
                "Venly/Public/Providers",
                "Venly/Public/Utils",
            }
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
                "Json",
                "JsonUtilities",
                "HTTP",
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
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
    }
}
