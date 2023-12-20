// Fill out your copyright notice in the Description page of Project Settings.


#include "VyGameInstanceWatcher.h"
#include "VyCore.h"

void UVyGameInstanceWatcher::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	//Notify VenlyCore that a new game instance started (useful for In-Editor settings reload onPlay)
	UVyCore::Get()->BeginPlay();
}

void UVyGameInstanceWatcher::Deinitialize()
{
	Super::Deinitialize();
	UVyCore::Get()->EndPlay();
}
