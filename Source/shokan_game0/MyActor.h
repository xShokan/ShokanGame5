// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class SHOKAN_GAME0_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Location", BlueprintReadWrite)
		FVector NewLocation = FVector(230.0f, -290.0f, 260.0f);

	UPROPERTY(EditAnywhere, Category = "Location", BlueprintReadWrite)
		FQuat NewRotation;


};
