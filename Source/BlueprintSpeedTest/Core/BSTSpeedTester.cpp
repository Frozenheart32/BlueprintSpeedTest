// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/BSTSpeedTester.h"

UBSTSpeedTester* UBSTSpeedTester::StartSpeedTest(UObject* WorldContextObject)
{
	check(WorldContextObject);
	const auto Tester = NewObject<UBSTSpeedTester>(WorldContextObject);
	Tester->StartTest();
	return Tester;
}

void UBSTSpeedTester::StartTest()
{
	TickDelegateHandle = FTSTicker::GetCoreTicker()
		.AddTicker(
			FTickerDelegate::CreateUObject(this, &UBSTSpeedTester::OnTick),
			0.0f
			); // Интервал (0 = каждый кадр))
}

bool UBSTSpeedTester::OnTick(float DeltaTime)
{
	Time += DeltaTime;

	return true;
}

float UBSTSpeedTester::StopSpeedTest()
{
	FTSTicker::GetCoreTicker().RemoveTicker(TickDelegateHandle);
	this->ConditionalBeginDestroy();
	return Time;
}
