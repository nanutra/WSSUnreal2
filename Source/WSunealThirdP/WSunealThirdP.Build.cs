// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class WSunealThirdP : ModuleRules
{
	public WSunealThirdP(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
