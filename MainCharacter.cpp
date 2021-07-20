// @Conor Quinn
// 2020/21

#include "MainCharacter.h"
#include "Gun.h"
#include "Components/CapsuleComponent.h"


// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame 
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
// Health System 
//Health = MaxHealth;

	// spawn the gun 
	Gun = GetWorld()->SpawnActor<AGun>(GunClass);

	// hide actor bone
	GetMesh()->HideBoneByName(TEXT("weapon_r"), EPhysBodyOp::PBO_None);

	// Attach it to the character
	Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("WeaponSocket"));
	Gun->SetOwner(this);

}



// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}





// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	//Movement Setup
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMainCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMainCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAction(TEXT("Shoot"), EInputEvent::IE_Pressed, this, &AMainCharacter::Shoot);
}





bool AMainCharacter::IsDead() const
{
	return Health <= 0;
}






float AMainCharacter::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	float DamageToApplied = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	DamageToApplied = FMath::Min(Health, DamageToApplied);
	Health -= DamageToApplied;

//	UE_LOG(LogTemp, Warning, TEXT("Health Left %f"), Health);


	if (IsDead())
	{
		DetachFromControllerPendingDestroy();
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		 Lives--; 
	
	}

	return DamageToApplied;

}




void AMainCharacter::MoveForward(float AxisValue)
{

AddMovementInput(GetActorForwardVector() * AxisValue);


}

//void AMainCharacter::LookUp(float AxisValue)
//{

//AddControllerPitchInput(AxisValue);

//}

void AMainCharacter::MoveRight(float AxisValue)
{

	AddMovementInput(GetActorRightVector() * AxisValue);


}

void AMainCharacter::Shoot()
{
	Gun->PullTrigger();
}



