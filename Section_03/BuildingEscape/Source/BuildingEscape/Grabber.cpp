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
	/// Look for attached Physics Handle, interface
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (PhysicsHandle)
	{

	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("%s lacks PhysicsHandleComponent"), *(GetOwner()->GetName() ) )
	}
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	///Get player viewpoint this tick
	FRotator PlayerViewPointRotation;
	FVector PlayerViewPointLocation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerViewPointLocation, OUT PlayerViewPointRotation); //Returns void, so stuff in there.

	///TODO log out to test

	///UE_LOG(LogTemp, Warning, TEXT("Current Player Viewpoint \n Player Location: %s \n Player View: %s"), *PlayerVector.ToString(), *PlayerRotate.ToString() )

	FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;
	///Draw a red trace in the world to visualize
	DrawDebugLine(
		GetWorld(),
		PlayerViewPointLocation,
		LineTraceEnd,
		FColor(255, 255, 0),
		false,
		0.f,
		0.f,
		10.f
	);

	///Setup query parameters
	FCollisionQueryParams TraceParameters = FCollisionQueryParams(FName(TEXT("")), false, GetOwner());
	///Alternatively: FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());

	///Ray-cast (superman lazer. Monolazer) out to reach distance
	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		PlayerViewPointLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParameters
	);
	AActor* ActorHit = Hit.GetActor();
	///log
	if (ActorHit != nullptr)
	//Null Pointer Check
	/// Equivalent to if (ActorHit) because of implicit conversions.
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has gotten hit."), *(ActorHit->GetName()) )
	}
	///See what we hit

}

