// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BSTSpeedTester.generated.h"

/**
 * 
 */
UCLASS(NotBlueprintable, BlueprintType)
class BLUEPRINTSPEEDTEST_API UBSTSpeedTester : public UObject
{
	GENERATED_BODY()

private:

	UPROPERTY()
	FDateTime StartTime = {};
	
	FTSTicker::FDelegateHandle TickDelegateHandle;

public:

	UFUNCTION(BlueprintCallable, meta=(WorldContext = "WorldContextObject"), Category = "Speed Test")
	static UBSTSpeedTester* StartSpeedTest(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category = "Speed Test")
	float StopSpeedTest();

private:

	UFUNCTION()
	void StartTest();
};
