//M3AutoAnsel (c) 2018 Mark Whitty

#include "M3AutoAnselCaptureManager.h"
#include "M3AutoAnsel.h"
#include "M3AutoAnselGameMode.h"
#include "Runtime/LevelSequence/Public/LevelSequencePlayer.h"
#include "Runtime/LevelSequence/Public/LevelSequence.h"
#include "Runtime/LevelSequence/Public/LevelSequenceActor.h"
#include "M3AutoAnselCameraManager.h"
#include "Engine/World.h"


AM3AutoAnselCaptureManager::AM3AutoAnselCaptureManager()
{
	PrimaryActorTick.bCanEverTick = true;
	CaptureMode = ECaptureMode::E360Stereo;
}


void AM3AutoAnselCaptureManager::BeginPlay()
{
	Super::BeginPlay();
	if (bCaptureEnabled)
	{
		if (GetWorld()->GetAuthGameMode()->GetClass() != AM3AutoAnselGameMode::StaticClass())
		{
			UE_LOG(LogM3AutoAnsel, Error, TEXT("Gamemode must be set to M3AutoAnselGameMode"));
		}
		else if (!SequenceActor)
		{
			UE_LOG(LogM3AutoAnsel, Error, TEXT("No Level Sequence Actor has been set in the Capture Manager. Select one from your scene"));
		}
		else
		{
			StartCapture();
		}
	}
}


void AM3AutoAnselCaptureManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AM3AutoAnselCaptureManager::StartCapture()
{
	UE_LOG(LogM3AutoAnsel, Display, TEXT("Starting %s capture..."), *GetCaptureModeName((uint8)CaptureMode).ToString());


	AM3AutoAnselCameraManager* CameraManager = Cast<AM3AutoAnselCameraManager>(GetWorld()->GetFirstPlayerController()->PlayerCameraManager);
	CameraManager->StartCapture();
	SequenceActor->SequencePlayer->Play();

}
