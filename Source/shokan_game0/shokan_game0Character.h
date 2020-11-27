// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "shokan_game0Character.generated.h"

UCLASS(config=Game)
class Ashokan_game0Character : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

public:
	Ashokan_game0Character();

	// Called every frame
	virtual void Tick(float DeltaTime) override;
		
	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class USkeletalMeshComponent* HandWeapon;					//定义武器

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isHip = true;																// 定义是否开镜

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isFire = false;																// 定义是否开火

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UAnimMontage* FireMontage;									// 定义开枪动画

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UAnimMontage* CutMontage;									// 定义 sword attack 动画

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USoundBase* FireSound;											// 定义开枪声音

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USoundBase* FireSound5;											// 定义Gun5开枪声音

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USoundBase* CutSound;											// 定义 sword attack 声音

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Score = 0;														            // 定义得分

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int KindOfWeapon = 1;														// 定义武器种类，1为Gun，2为Sword

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int KindOfGun = 1;														// 定义Gun种类

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")			
	class USkeletalMesh* GunMesh;						//定义武器Gun1的Mesh

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	class USkeletalMesh* SwordMesh;					//定义武器Sword的Mesh

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	class USkeletalMesh* Gun3Mesh;						//定义武器Gun3的Mesh

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	class USkeletalMesh* Gun4Mesh;						//定义武器Gun4的Mesh

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	class USkeletalMesh* Gun5Mesh;						//定义武器Gun5的Mesh

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	class USkeletalMesh* EmptyMesh;					//定义空的Mesh
//#if 0
//
//#endif

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isFreeView = false;										// 定义是否是自由视角
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawning")
	TSubclassOf<AActor>  Gun1ToSpawn;										// 定义要生成的Gun1类

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	TSubclassOf<AActor>  Gun3ToSpawn;										// 定义要生成的Gun3类

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	TSubclassOf<AActor>  Gun4ToSpawn;										// 定义要生成的Gun4类

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	TSubclassOf<AActor>  Gun5ToSpawn;										// 定义要生成的Gun5类

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	TSubclassOf<AActor>  AmmoGun5ToSpawn;										// 定义要生成的Gun5子弹类

	UPROPERTY(BlueprintReadWrite)
	AActor* OverlappingWeaponActor;							// 定义overlapping类

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bEquipWeapon = true;										// 定义是否有武器

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bShowPressF = false;										// 定义是否显示PressF UMG

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bShowYouEquipWeapon = false;										// 定义是否显示You already have equipped a weapon!

	UPROPERTY(BlueprintReadWrite)
	int OverlappingKindOfWeapon = 0;										// 定义overlapping武器类型, 1是默认Gun, 2是剑(先不考虑), 后面为其他Gun

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HitParticle")
	class UParticleSystem* EmitterTemplateLowerBody;										     // 定义打下半身粒子特效

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HitParticle")
	class UParticleSystem* EmitterTemplateUpperBody;										     // 定义打下半身粒子特效

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HitParticle")
	class UParticleSystem* EmitterTemplateHead;										     // 定义打下半身粒子特效

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HitParticle")
	class UParticleSystem* EmitterTemplateGun5Fire;										     // 定义Gun5开火粒子特效

protected:

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	void IronsightDown();
	void IronsightUp();

	void Fire();
	void FireDown();
	void FireUp();

	void RunDown();
	void RunUp();

	void SwitchGun();
	void SwitchSword();

	void FreeViewDown();
	void FreeViewUp();

	void DropWeaponDown();
	void SpawnObject(TSubclassOf<AActor> ToSpawn);

	void PickWeaponDown();

	void SpawnAmmo(TSubclassOf<AActor> ToSpawn);

	FHitResult OutHit;

};

