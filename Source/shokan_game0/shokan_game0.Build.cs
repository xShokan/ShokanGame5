// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class shokan_game0 : ModuleRules
{
	public shokan_game0(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
