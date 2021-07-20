// @Conor Quinn
// 2020/21

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_PlayerLocationIfSeenTH.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT1_API UBTService_PlayerLocationIfSeenTH : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UBTService_PlayerLocationIfSeenTH();



protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;


};
