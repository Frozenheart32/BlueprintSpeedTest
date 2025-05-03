// Fill out your copyright notice in the Description page of Project Settings.


#include "Util/BSTHelperMethodsFunctionLibrary.h"

#include "Kismet/KismetSystemLibrary.h"

void UBSTHelperMethodsFunctionLibrary::PrintTestResults(UObject* WorldContextObject, const FString& TestName, int32 FibonacciNum, int32 Result, float Duration, bool bPrintToLog)
{
	const FString OutputString = FString::Printf(TEXT("FibonacciNum: %d, Result: %d, %.1f ms, TestName: %s "), FibonacciNum, Result, Duration, *TestName);
	UKismetSystemLibrary::PrintString(WorldContextObject, OutputString, true, bPrintToLog, FLinearColor::Green, 5.0f);
}
