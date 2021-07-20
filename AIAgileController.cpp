// @Conor Quinn
// 2020/21


#pragma once



#include "AIAgileController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"


void AAIAgileController::BeginPlay()
{
	Super::BeginPlay();

	if (AIBehavior != nullptr)
	{
		RunBehaviorTree(AIBehaviorAgile);

		APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);


		// GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());


	}

}

void AAIAgileController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

}