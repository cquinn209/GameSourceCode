// @Conor Quinn
// 2020/21

#include "BTTask_Shoot.h"
#include "AIController.h"
#include "MainCharacter.h"

UBTTask_Shoot::UBTTask_Shoot()
{
	NodeName = "Shoot";
}

 EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	AMainCharacter* Character = Cast<AMainCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	
	if (Character == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	Character->Shoot();

	return EBTNodeResult::Succeeded;
}