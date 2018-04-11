// Nicholas Golden (c) 2018

#include "BuildingEscape.h"
#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	Owner = GetOwner(); //Clearly this makes sense because the door is the only thing of focus here.
	//Find pc
	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();

	//OpenDoor();


}

void UOpenDoor::OpenDoor()
{

	Owner->SetActorRotation(FRotator(0.0f, OpenAngle, 0.0f));
	
	//Debug code
	/**
	FString ObjectName = Owner->GetName(); //* is overloaded.
	FString ObjectRotate = Owner->GetTransform().GetRotation().ToString();
	bool IsActive = PressurePlate->IsOverlappingActor(ActorThatOpens);
	UE_LOG(LogTemp, Warning, TEXT("%s is at %d"), *ObjectName, IsActive);
	*/
}

void UOpenDoor::CloseDoor()
{
	Owner->SetActorRotation(FRotator(0.0f, CloseAngle, 0.0f));
}



// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	

	// Poll the Trigger Volume
	//If the ActorThatOpens is in the volume
	if (PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}

	// Check if it's time to close the door
	CurrentTime = GetWorld()->GetTimeSeconds();
	if ((CurrentTime  - LastDoorOpenTime) >= DoorCloseDelay) //Using a greater than or equal in case of lag or time disruptions.
	{
		CloseDoor();
	}
}

