// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BSTHelperMethodsFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class BLUEPRINTSPEEDTEST_API UBSTHelperMethodsFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Speed Test", meta=(WorldContext = "WorldContextObject"))
	static void PrintTestResults(UObject* WorldContextObject, const FString& TestName, int32 FibonacciNum, int32 Result, float Duration, bool bPrintToLog = false);
};
