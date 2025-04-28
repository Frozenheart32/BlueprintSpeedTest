// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class BlueprintSpeedTestTarget : TargetRules
{
	public BlueprintSpeedTestTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		bLegacyParentIncludePaths = false;
		CppStandard = CppStandardVersion.Latest;
		ExtraModuleNames.Add("BlueprintSpeedTest");
	}
}
