//M3AutoAnsel (c) 2018 Mark Whitty

#include "M3AutoAnselPlayerController.h"
#include "M3AutoAnselCameraManager.h"

AM3AutoAnselPlayerController::AM3AutoAnselPlayerController()
	: Super()
{
	PlayerCameraManagerClass = AM3AutoAnselCameraManager::StaticClass();
}


