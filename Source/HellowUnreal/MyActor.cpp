// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

static void TestUELogExamples()
{
    // 1. 일반 로그(Log) - 개발자가 디버깅을 위해 사용하는 기본 메시지
    UE_LOG(LogTemp, Log, TEXT("Game has started. Player has joined the game."));

    // 2. 중요 정보(Display) - 항상 표시되는 정보 메시지
    FString PlayerName = TEXT("Player1");
    UE_LOG(LogTemp, Display, TEXT("Welcome, %s! Enjoy the game."), *PlayerName);

    // 3. 경고(Warning) - 잠재적 문제가 있을 때 경고를 출력
    int PlayerHealth = 50;
    if (PlayerHealth < 100)
    {
        UE_LOG(LogTemp, Warning, TEXT("Player health is below maximum: %d"), PlayerHealth);
    }

    // 4. 오류(Error) - 실행에 영향을 줄 수 있는 문제
    int AmmoCount = 0;
    if (AmmoCount == 0)
    {
        UE_LOG(LogTemp, Error, TEXT("No ammo left! Player cannot shoot."));
    }

    // 5. 치명적 오류(Fatal) - 프로그램이 더 이상 실행될 수 없는 경우 (종료됨)
    bool bCriticalFailure = true;
    if (bCriticalFailure)
    {
        UE_LOG(LogTemp, Fatal, TEXT("A critical failure occurred. Shutting down..."));
    }

    // 6. 문자열 결합 - 다양한 데이터를 한 메시지로 출력
    int Score = 150;
    int TimeLeft = 120;
    UE_LOG(LogTemp, Log, TEXT("Score: %d, Time Left: %d seconds."), Score, TimeLeft);

    // 7. 부동소수점(Floating Point) 값 출력
    float PlayerSpeed = 325.5f;
    UE_LOG(LogTemp, Display, TEXT("Player speed: %.2f units/sec"), PlayerSpeed);

    // 8. 여러 심각도 사용 - 게임 상태에 따라 로그를 구분
    bool bIsPaused = true;
    if (bIsPaused)
    {
        UE_LOG(LogTemp, Warning, TEXT("Game is currently paused."));
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("Game is running normally."));
    }

    // 9. 디버깅용 메시지 (Developer Note)
    UE_LOG(LogTemp, Display, TEXT("This message is for developers to debug the game state."));
}
static void game369()
{
    for (int i = 1; i < 30; ++i)
    {
        FString nubmer = FString::FromInt(i);
        bool blsClap = false;

        for (TCHAR chr : nubmer)
        {
            if (chr == '3' || chr == '6' || chr == '9')
            {
                blsClap = true;
                break;
            }
        }
        if (blsClap)
        {
            UE_LOG(LogTemp, Warning, TEXT("짝"));
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("%d"), i);
        }
    }
}
static void rnadint()
{
    int minValue = 1;
    int maxValue = 100;

    int randNumber1 = FMath::RandRange(minValue, maxValue);
    int randNumber2 = FMath::RandRange(minValue, maxValue);
    int randNumber3 = FMath::RandRange(minValue, maxValue);

    int sum = randNumber1 + randNumber2 + randNumber3;
    UE_LOG(LogTemp, Warning, TEXT("Generated Numbers : %d %d %d"), randNumber1, randNumber2, randNumber3);
    UE_LOG(LogTemp, Warning, TEXT("Sum of Numbers : %d"), sum);
}
static void lotto()
{
    int lottoArr[45] = {};
    // 번호생성
    for (int i = 0; i < 45; ++i)
    {
        lottoArr[i] = i + 1;
    }

    // 섞기
    for (int i = 0; i < 100; ++i)
    {
        int n1 = FMath::RandRange(0, 44);
        int n2 = FMath::RandRange(0, 44);
        std::swap(lottoArr[n1], lottoArr[n2]);
    }

    UE_LOG(LogTemp, Warning, TEXT("Lotto Numbers : %d,%d,%d,%d,%d,%d"), lottoArr[0], lottoArr[1], lottoArr[2], lottoArr[3], lottoArr[4], lottoArr[5]);
}
// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
    TArray<int32> LottoNumbers;
    const int32 MinNumber = 1;
    const int32 MaxNumber = 45;
    const int32 TotalNumbers = 6;

    // 랜덤한 숫자 6개 생성 (중복되지 않도록)
    while (LottoNumbers.Num() < TotalNumbers)
    {
        int32 RandomNumber = FMath::RandRange(MinNumber, MaxNumber);
        if (!LottoNumbers.Contains(RandomNumber))
        {
            LottoNumbers.Add(RandomNumber);
        }
    }

    // 숫자 배열을 문자열로 변환
    FString LottoNumbersStr;
    for (int32 Number : LottoNumbers)
    {
        LottoNumbersStr += FString::FromInt(Number) + TEXT(", ");
    }
    LottoNumbersStr.RemoveFromEnd(TEXT(", "));

    // 로또 번호 출력
    UE_LOG(LogTemp, Warning, TEXT("로또 번호: %s"), *LottoNumbersStr);

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("로또 번호: %s"), *LottoNumbersStr));
    }
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

