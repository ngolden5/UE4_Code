// Nicholas Golden (c) 2018
//IWYU-code
//#include DrawDebugHelpers.h
#include "BuildingEscape.h"
#include "Grabber.h"

#define OUT 
//empty but descriptive

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//Get player viewpoint this tick
	FRotator PlayerViewPointRotation;
	FVector PlayerViewPointLocation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerViewPointLocation, OUT PlayerViewPointRotation); //Returns void, so stuff in there.

	//TODO log out to test

	//UE_LOG(LogTemp, Warning, TEXT("Current Player Viewpoint \n Player Location: %s \n Player View: %s"), *PlayerVector.ToString(), *PlayerRotate.ToString() )

	FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;
	//Draw a red trace in the world to visualize
	DrawDebugLine(
		GetWorld(),
		PlayerViewPointLocation,
		LineTraceEnd,
		FColor(255, 0, 0),
		false,
		0.f,
		0.f,
		10.f
	);

	//Ray-cast (superman lazer. Monolazer) out to reach distance

	//See what we hit
}

