// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/HybridTest.h"

#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"

// Sets default values
AHybridTest::AHybridTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	BoxCollision->SetCollisionResponseToAllChannels(ECR_Overlap);
	BoxCollision->SetHiddenInGame(false);
	SetRootComponent(BoxCollision);

	TextRender = CreateDefaultSubobject<UTextRenderComponent>("TextRender");
	TextRender->SetText(FText::FromString("Blueprint AND C++"));
	TextRender->SetupAttachment(GetRootComponent());
}

int32 AHybridTest::Fibonacci(int32 Number) const
{
	if (Number <= 1)
		return Number;
	
	return Fibonacci(Number - 1) + Fibonacci(Number - 2);
}

int32 AHybridTest::FibonacciIter(int32 Number) const
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
