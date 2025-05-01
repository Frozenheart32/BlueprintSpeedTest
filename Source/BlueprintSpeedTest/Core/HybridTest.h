// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HybridTest.generated.h"

class UTextRenderComponent;
class UBoxComponent;

UCLASS()
class BLUEPRINTSPEEDTEST_API AHybridTest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHybridTest();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UBoxComponent> BoxCollision;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UTextRenderComponent> TextRender;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "HybridTest Settings")
	int32 FibonacciNumber = 2;

	UFUNCTION(BlueprintCallable, Category = "HybridTest")
	int32 Fibonacci(int32 Number) const;

	UFUNCTION(BlueprintCallable, Category = "HybridTest")
	int32 FibonacciIter(int32 Number) const;
};
