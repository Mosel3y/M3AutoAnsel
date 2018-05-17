//M3AutoAnsel (c) 2018 Mark Whitty

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "M3AutoAnselCaptureManager.h"
#include "M3AutoAnselGameMode.generated.h"

/**
 * 
 */
UCLASS()
class M3AUTOANSEL_API AM3AutoAnselGameMode : public AGameModeBase
{
	GENERATED_BODY()

	
public:
	AM3AutoAnselGameMode();


protected:
	virtual void BeginPlay();

	
	
};
