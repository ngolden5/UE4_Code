// Nicholas Golden (c) 2018

#pragma once

//#include "Engine/TriggerVolume.h" for later versions.

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h" 
//This has to be the last include.



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();
	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();
	void CloseDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere) //Macro
	float OpenAngle = 0.0f;

	UPROPERTY(EditAnywhere)
	float CloseAngle = 90.0f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate;

	//UPROPERTY(EditAnywhere)
	AActor* ActorThatOpens;
		//Remember pawn inherits from actor.

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 1.f;

	float CurrentTime = 0.0f;
	float LastDoorOpenTime = 0.0f;

	AActor* Owner; //The owning door.
};
