// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "M3AutoAnsel.h"

#define LOCTEXT_NAMESPACE "FM3AutoAnselModule"
DEFINE_LOG_CATEGORY(LogM3AutoAnsel);

void FM3AutoAnselModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
}

void FM3AutoAnselModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FM3AutoAnselModule, M3AutoAnsel)