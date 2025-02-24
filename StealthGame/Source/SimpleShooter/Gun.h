// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class SIMPLESHOOTER_API AGun : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGun();

	void PullTrigger();

	void Reload(int32 AmmoToLoad);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 Ammo;

	UPROPERTY(EditAnywhere)
	FString Name;

	UPROPERTY(EditAnywhere)
	int32 MaxAmmo = 30;

private:
	UPROPERTY(VisibleAnywhere)
		USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
		USkeletalMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
		UParticleSystem* MuzzleFlash;

	UPROPERTY(EditAnywhere)
		USoundBase* MuzzleSound;

	UPROPERTY(EditAnywhere)
		UParticleSystem* ImpactEffect;

	UPROPERTY(EditAnywhere)
		USoundBase* ImpactSound;

	UPROPERTY(EditAnywhere)
		USoundBase* EmptySound;

	UPROPERTY(EditAnywhere)
		USoundBase* ReloadSound;

	UPROPERTY(EditAnywhere)
		float MaxRange = 1000.f;

	UPROPERTY(EditAnywhere)
		float Damage = 10.f;

	FTimerHandle ReloadTimer;


	bool GunTrace(FHitResult& Hit, FVector& ShotDirection);

	AController* GetOwnerController() const;
};