//M3AutoAnsel (c) 2018 Mark Whitty


#include "M3AutoAnselCameraManager.h"
#include "Runtime/Engine/Classes/Engine/LatentActionManager.h";
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "M3AutoAnsel.h"




void AM3AutoAnselCameraManager::BeginPlay()
{
	Super::BeginPlay();
}

void AM3AutoAnselCameraManager::DelayByFrame(int32 DelayFrames, FLatentActionInfo LatentActionInfo)
{

}

void AM3AutoAnselCameraManager::OnPhotographyMultiPartCaptureEnd_Implementation()
{
	//Super::OnPhotographyMultiPartCaptureEnd();


	PCOwner->SetPause(false);
}

void AM3AutoAnselCameraManager::StartCapture()
{
	PCOwner->SetPause(true);
}