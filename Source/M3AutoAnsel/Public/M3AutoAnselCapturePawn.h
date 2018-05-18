//M3AutoAnsel (c) 2018 Mark Whitty

#pragma once

#include "CoreMinimal.h"
#include "M3AutoAnsel.h"
#include "GameFramework/Pawn.h"
#include "M3AutoAnselPlayerController.h"
#include "Runtime/LevelSequence/Public/LevelSequenceActor.h"
#include "Runtime/LevelSequence/Public/LevelSequencePlayer.h"
#include "Runtime/LevelSequence/Public/LevelSequence.h"
#include "M3AutoAnselCapturePawn.generated.h"



UCLASS()
class M3AUTOANSEL_API AM3AutoAnselCapturePawn : public APawn
{
	GENERATED_BODY()

	UPROPERTY(VisibleDefaultsOnly)
	class UCameraComponent* CameraComponent;

	
public:	
	AM3AutoAnselCapturePawn();

protected:
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void StartCapture();

	UFUNCTION()
	void FrameForwardInput();

	UFUNCTION()
	void NextFrame(bool DelayFinished);

	UPROPERTY(EditAnywhere, Category = CaptureSettings)
	bool bCaptureEnabled;

	UPROPERTY(EditAnywhere, Category = CaptureSettings)
	ECaptureMode CaptureMode;

	UPROPERTY(EditAnywhere, Category = CaptureSettings)
	ALevelSequenceActor* SequenceActor;

	UPROPERTY(EditAnywhere, Category = CaptureSettings)
	float EyeHeight;

	AM3AutoAnselPlayerController* PlayerController;

};
