// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/PureCPPTest.h"

#include "BSTSpeedTester.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"
#include "Util/BSTHelperMethodsFunctionLibrary.h"

// Sets default values
APureCPPTest::APureCPPTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	BoxCollision->SetCollisionResponseToAllChannels(ECR_Overlap);
	BoxCollision->SetHiddenInGame(false);
	SetRootComponent(BoxCollision);

	TextRender = CreateDefaultSubobject<UTextRenderComponent>("TextRender");
	TextRender->SetText(FText::FromString("C++"));
	TextRender->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void APureCPPTest::BeginPlay()
{
	Super::BeginPlay();

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &APureCPPTest::OnStartTest);
}

void APureCPPTest::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	BoxCollision->OnComponentBeginOverlap.RemoveDynamic(this, &APureCPPTest::OnStartTest);
	
	Super::EndPlay(EndPlayReason);
}

void APureCPPTest::OnStartTest(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                               UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bBFromSweep, const FHitResult& SweepResult)
{
	const auto SpeedTestTimer = UBSTSpeedTester::StartSpeedTest(this);
	const int32 Result = FibonacciIter(FibonacciNumber);
	const float Duration = SpeedTestTimer->StopSpeedTest();
	
	UBSTHelperMethodsFunctionLibrary::PrintTestResults(this, *GetNameSafe(this), FibonacciNumber, Result,  Duration, true);
}

int32 APureCPPTest::Fibonacci(int32 Number) const
{
	if (Number <= 1)
		return Number;
	
	return Fibonacci(Number - 1) + Fibonacci(Number - 2);
}

int32 APureCPPTest::FibonacciIter(int32 Number) const
{
	if(Number <= 1)
		return Number;

	int32 A = 0;
	int32 B = 1;
	int32 C = 0;
	const int32 Limit = Number + 1;
	for (int32 i = 2; i < Limit; i++)
	{
		C = A + B;
		A = B;
		B = C;
	}

	return B;
}

