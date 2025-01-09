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
			vMove.X, vMove.Y, FVector::Dist(vActorLot, vMove));

		if (FMath::RandRange(0, 1))
			createEvent();
	}
	UE_LOG(LogTemp, Warning, TEXT("Event Count : %d , tot Distance : %lf"),m_eventCount, FVector::Dist(lot, vMove));
}

FVector AMyActor2::step()
{
	// ������ �̵� ���� ����
	FVector Lot;
	Lot.X = FMath::RandRange(0, 1);
	Lot.Y = FMath::RandRange(0, 1);
	Lot.Z = 0;

	// ���� �̵�
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

// Called every frame
void AMyActor2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
