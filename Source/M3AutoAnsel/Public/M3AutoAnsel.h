//M3AutoAnsel (c) 2018 Mark Whitty

#pragma once

#include "ModuleManager.h"
DECLARE_LOG_CATEGORY_EXTERN(LogM3AutoAnsel, Log, All);

UENUM(BlueprintType)
enum class ECaptureMode : uint8
{
	EScreenshot	UMETA(DisplayName = "Screenshot"),
	ESuperResolution	UMETA(DisplayName = "Super Resolution"),
	E360Degree	UMETA(DisplayName = "360"),
	EStereo	UMETA(DisplayName = "Stereo"),
	E360Stereo	UMETA(DisplayName = "360 Stereo")
};

static const FText GetCaptureModeName(uint8 EnumValue)
{
	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("ECaptureMode"), true);
	return EnumPtr->GetDisplayNameTextByIndex((int32)EnumValue); 
}

class FM3AutoAnselModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};