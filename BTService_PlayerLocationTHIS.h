// @Conor Quinn
// 2020/21

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_PlayerLocationTHIS.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT1_API UBTService_PlayerLocationTHIS : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UBTService_PlayerLocationTHIS();



protected: 
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
