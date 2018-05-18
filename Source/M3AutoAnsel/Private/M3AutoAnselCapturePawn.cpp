//M3AutoAnsel (c) 2018 Mark Whitty

#include "M3AutoAnselCapturePawn.h"
#include "M3AutoAnsel.h"
#include "M3AutoAnselGameMode.h"
#include "M3AutoAnselPlayerController.h"
#include "Runtime/LevelSequence/Public/LevelSequenceActor.h"
#include "Runtime/LevelSequence/Public/LevelSequencePlayer.h"
#include "Runtime/LevelSequence/Public/LevelSequence.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "M3AutoAnselCameraManager.h"
#include "TimerManager.h"
#include "Engine/World.h"


AM3AutoAnselCapturePawn::AM3AutoAnselCapturePawn()
{
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	CaptureMode = ECaptureMode::E360Stereo;
	SetTickableWhenPaused(true);
	EyeHeight = 150.0f;

	//Root component
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	//Camera component
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(RootComponent);
	CameraComponent->bUsePawnControlRotation = false;
}


void AM3AutoAnselCapturePawn::BeginPlay()
{
	Super::BeginPlay();

	PlayerController = Cast<AM3AutoAnselPlayerController>(Controller);

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

void AM3AutoAnselCapturePawn::OnConstruction(const FTransform& Transform)
{
	CameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, EyeHeight));
}


void AM3AutoAnselCapturePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AM3AutoAnselCapturePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//InputComponent->BindKey(EKeys::F, IE_Pressed, this, &AM3AutoAnselCapturePawn::FrameForwardInput);
	InputComponent->BindAction("ForwardFrame", IE_Pressed, this, &AM3AutoAnselCapturePawn::FrameForwardInput) .bExecuteWhenPaused = true;
}

void AM3AutoAnselCapturePawn::FrameForwardInput()
{
	UE_LOG(LogM3AutoAnsel, Error, TEXT("Input"));
	if (PlayerController)
	{
		NextFrame(false);
	}
}

void AM3AutoAnselCapturePawn::NextFrame(bool DelayFinished)
{
	if (!DelayFinished)
	{
		PlayerController->SetPause(false);
		FTimerDelegate DelayDelegate;
		FTimerHandle DelayHandle;
		DelayDelegate.BindUFunction(this, FName("NextFrame"), true);
		GetWorldTimerManager().SetTimer(DelayHandle, DelayDelegate, 3.0f, false);
	}
	else
	{
		PlayerController->SetPause(true);
	}
}

void AM3AutoAnselCapturePawn::StartCapture()
{
	UE_LOG(LogM3AutoAnsel, Display, TEXT("Starting %s capture..."), *GetCaptureModeName((uint8)CaptureMode).ToString());
	PlayerController->SetPause(true);
	SequenceActor->SequencePlayer->Play();

	//AM3AutoAnselCameraManager* CameraManager = Cast<AM3AutoAnselCameraManager>(GetWorld()->GetFirstPlayerController()->PlayerCameraManager);
	//CameraManager->StartCapture();
}
