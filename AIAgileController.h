// @Conor Quinn
// 2020/21

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIAgileController.generated.h"

/**
 *
 */
UCLASS()
class MYPROJECT1_API AAIAgileController : public AAIController
{
	GENERATED_BODY()


public:
	virtual void Tick(float DeltaSeconds) override;



protected:
	virtual void BeginPlay() override;


private:

	//setup which behavior tree to use
	UPROPERTY(EditAnywhere)
		class UBehaviorTree* AIBehavior;

};
