// @Conor Quinn
// 2020/21


#pragma once



#include "AIBossController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"


void AAIBossController::BeginPlay()
{
	Super::BeginPlay();

	if (AIBehavior != nullptr)
	{
		RunBehaviorTree(AIBehaviorBoss);

		APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);


		// GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());


	}

}

void AAIBossController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

}