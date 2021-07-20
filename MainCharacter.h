// @Conor Quinn
// 2020/21

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

class AGun;

UCLASS()
class MYPROJECT1_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Sets default values for this character's properties
	AMainCharacter();


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Health;


//	UPROPERTY(EditAnywhere, BlueprintReadWrite)

	float Lives = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool deathset;

	//Death
	UFUNCTION(BlueprintCallable, Category="Dead?")
		bool IsDead() const; 

	//shooting
	void Shoot();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;




	//Taking Damage
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser);


	

private:
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	



	// only subclasses of gun 
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGun> GunClass;

	UPROPERTY()
		AGun* Gun;



};
