// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class BlueprintSpeedTestEditorTarget : TargetRules
{
	public BlueprintSpeedTestEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		bLegacyParentIncludePaths = false;
		CppStandard = CppStandardVersion.Latest;
		ExtraModuleNames.Add("BlueprintSpeedTest");
	}
}
