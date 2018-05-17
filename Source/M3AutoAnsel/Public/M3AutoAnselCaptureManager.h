//M3AutoAnsel (c) 2018 Mark Whitty

#pragma once

#include "CoreMinimal.h"
#include "M3AutoAnsel.h"
#include "GameFramework/Actor.h"
#include "Runtime/LevelSequence/Public/LevelSequencePlayer.h"
#include "Runtime/LevelSequence/Public/LevelSequence.h"
#include "Runtime/LevelSequence/Public/LevelSequenceActor.h"
#include "M3AutoAnselCaptureManager.generated.h"



UCLASS()
class M3AUTOANSEL_API AM3AutoAnselCaptureManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AM3AutoAnselCaptureManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	bool bCaptureEnabled;

	UPROPERTY(EditAnywhere)
	ECaptureMode CaptureMode;

	UPROPERTY(EditAnywhere)
	ALevelSequenceActor* SequenceActor;


	void StartCapture();
	
};
