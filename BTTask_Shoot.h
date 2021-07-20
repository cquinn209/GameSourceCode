// @Conor Quinn
// 2020/21

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_Shoot.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT1_API UBTTask_Shoot : public UBTTaskNode
{
	GENERATED_BODY()

public:
	
	UBTTask_Shoot();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

};
