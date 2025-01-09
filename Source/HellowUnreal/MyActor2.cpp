// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor2.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
// Sets default values
AMyActor2::AMyActor2() :
	m_eventCount(NULL)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	USceneComponent* RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = RootComp;

	RootComp->Mobility = EComponentMobility::Movable;
}

// Called when the game starts or when spawned
void AMyActor2::BeginPlay()
{
	Super::BeginPlay();
	FVector lot = GetActorLocation();
	FVector dist = lot;
	FVector vMove;
	for (int i = 0; i < 10; ++i)
	{
		FVector vActorLot = GetActorLocation();
		vMove = move();
		UE_LOG(LogTemp, Warning, TEXT("Actor Move Coord: x : %lf y : %lf \n Actor Move Distance : %lf"),
			vMove.X, vMove.Y, vector_dist(vActorLot, vMove));

		if (FMath::RandRange(0, 1))
			createEvent();
	}
	UE_LOG(LogTemp, Warning, TEXT("Event Count : %d , tot Distance : %lf"),m_eventCount, vector_dist(lot, vMove));
}

FVector AMyActor2::step()
{
	// ·£´ýÇÑ ÀÌµ¿ º¤ÅÍ »ý¼º
	FVector Lot;
	Lot.X = FMath::RandRange(0, 1);
	Lot.Y = FMath::RandRange(0, 1);
	Lot.Z = 0;

	// ¿¢ÅÍ ÀÌµ¿
	FVector ActorLot = GetActorLocation();
	FVector MoveLot = ActorLot + Lot;
	return MoveLot;
}

FVector AMyActor2::move()
{
	FVector vector = step();
	SetActorLocation(vector);
	return vector;
}

void AMyActor2::createEvent()
{
	++m_eventCount;
	UE_LOG(LogTemp, Error, TEXT("Create Event!. Event Count : %d "),m_eventCount);
}

double AMyActor2::vector_dist(const FVector& v1, const FVector& v2)
{
	return FMath::Square(v2.X - v1.X) + FMath::Square(v2.Y - v1.Y) + FMath::Square(v2.Z - v1.Z);
}
