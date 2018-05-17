//M3AutoAnsel (c) 2018 Mark Whitty

using UnrealBuildTool;

public class M3AutoAnsel : ModuleRules
{
	public M3AutoAnsel(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				"M3AutoAnsel/Public"
		
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				"M3AutoAnsel/Private",
			
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
                "LevelSequence",
                "MovieScene",
                "MoviePlayer",
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
