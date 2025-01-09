// Fill out your copyright notice in the Description page of Project Settings.
#include "MyGameInstance.h"
#include "MyActor2.h"

void UMyGameInstance::Init()
{
	Super::Init();
	UWorld* world = GetWorld();

	if (world == nullptr)
		return;

	const FRotator Rotation = FRotator::ZeroRotator;
	FVector Location = FVector::ZeroVector;
	FVector Scae = { 1.f,1.f,1.f };
	FTransform transform = { Rotation ,Location,Scae };

	FActorSpawnParameters ActorParam;
	ActorParam.Name = TEXT("MyActor");
	ActorParam.Owner = nullptr;
	ActorParam.Instigator = nullptr;
	ActorParam.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	world->SpawnActor<AMyActor2>(Location, Rotation, ActorParam);
}
