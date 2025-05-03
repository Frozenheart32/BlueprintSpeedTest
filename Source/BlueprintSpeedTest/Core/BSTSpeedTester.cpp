// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/BSTSpeedTester.h"

#include "Kismet/KismetMathLibrary.h"

UBSTSpeedTester* UBSTSpeedTester::StartSpeedTest(UObject* WorldContextObject)
{
	check(WorldContextObject);
	const auto Tester = NewObject<UBSTSpeedTester>(WorldContextObject);
	Tester->StartTest();
	return Tester;
}

void UBSTSpeedTester::StartTest()
{
	StartTime = FDateTime::Now();
}

float UBSTSpeedTester::StopSpeedTest(bool bSelfDestroy)
{
	const float Duration = UKismetMathLibrary::GetTotalMilliseconds(FDateTime::Now() - StartTime);
	if(bSelfDestroy)
		this->ConditionalBeginDestroy();
	
	return Duration;
}
