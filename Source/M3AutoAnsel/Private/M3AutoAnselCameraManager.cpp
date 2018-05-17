//M3AutoAnsel (c) 2018 Mark Whitty


#include "M3AutoAnselCameraManager.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "M3AutoAnsel.h"




void AM3AutoAnselCameraManager::BeginPlay()
{
	Super::BeginPlay();
}

void AM3AutoAnselCameraManager::AdvanceFrame(uint32 FrameDelay)
{
	if (FrameDelay == 0)
	{
		StartCapture();
	}
	else
	{
		AdvanceFrame(FrameDelay - 1);
		UE_LOG(LogM3AutoAnsel, Display, TEXT("Countdown....... %d"), FrameDelay);
	}
}

void AM3AutoAnselCameraManager::OnPhotographyMultiPartCaptureEnd_Implementation()
{
	//Super::OnPhotographyMultiPartCaptureEnd();
	PCOwner->SetPause(false);
	AdvanceFrame(10);
}

void AM3AutoAnselCameraManager::StartCapture()
{
	PCOwner->SetPause(true);
}