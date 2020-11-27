// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GrenadeAmmo.generated.h"

UCLASS()
class SHOKAN_GAME0_API AGrenadeAmmo : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGrenadeAmmo();

	// 定义榴弹爆炸粒子特效
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UParticleSystem* EmitterTemplateAmmoBoom;	

	// 定义榴弹爆炸声音
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USoundBase* AmmoBoomSound;

	// 定义榴弹爆炸在金属上声音
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USoundBase* BoomAtMetalSound;

	// 定义榴弹爆炸在草地声音
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USoundBase* BoomAtGrassSound;

	// 定义榴弹爆炸在木头声音
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USoundBase* BoomAtWoodSound;

	//定义爆炸冲击力
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class URadialForceComponent * RadialForce;

	UPROPERTY()
	class UStaticMeshComponent* StaticMeshComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

};
