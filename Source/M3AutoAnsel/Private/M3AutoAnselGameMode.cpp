//M3AutoAnsel (c) 2018 Mark Whitty

#include "M3AutoAnselGameMode.h"
#include "M3AutoAnselPlayerController.h"
#include "M3AutoAnsel.h"


AM3AutoAnselGameMode::AM3AutoAnselGameMode()
	: Super()
{
	PlayerControllerClass = AM3AutoAnselPlayerController::StaticClass();
}

void AM3AutoAnselGameMode::BeginPlay()
{
	Super::BeginPlay();
}
