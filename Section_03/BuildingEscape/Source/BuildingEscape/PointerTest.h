// Nicholas Golden (c) 2018

#pragma once

#include "Components/ActorComponent.h"
#include "PointerTest.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UPointerTest : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPointerTest();

private:
	int32 val1 = 1;
	int32 val2 = 2;
	int32* valptr = &val1;
	int32& valref = val1;

	void ValueLog();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
