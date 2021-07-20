// @Conor Quinn
// 2020/21

#include "BTService_PlayerLocationTHIS.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"


UBTService_PlayerLocationTHIS::UBTService_PlayerLocationTHIS()
{
	NodeName = "Update Player Location This";
}


void UBTService_PlayerLocationTHIS::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	 APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	 if (PlayerPawn == nullptr)
	 {
		 return;
	 }

	 OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), PlayerPawn->GetActorLocation());

}

