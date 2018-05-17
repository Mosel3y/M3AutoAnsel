//M3AutoAnsel (c) 2018 Mark Whitty

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "Runtime/Engine/Classes/Engine/LatentActionManager.h"
#include "M3AutoAnselCameraManager.generated.h"

/**
 * 
 */
UCLASS()
class M3AUTOANSEL_API AM3AutoAnselCameraManager : public APlayerCameraManager
{
	GENERATED_BODY()

private:
	void DelayByFrame(int32 DelayFrames, FLatentActionInfo LatentActionInfo);
	
protected:
	virtual void BeginPlay();

	virtual void OnPhotographyMultiPartCaptureEnd_Implementation() override;

public:
	void StartCapture();
};
