// @Conor Quinn
// 2020/21

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class MYPROJECT1_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();

	void PullTrigger();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Custom)
		float Damage = 10;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	UPROPERTY(VisibleAnywhere)
		USceneComponent* Root;
		
	UPROPERTY(EditAnywhere)
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
		float MaxRange = 1000;

	bool GunTrace(FHitResult& Hit, FVector& ShotDirection);

	AController* GetOwnerController() const; 



};
