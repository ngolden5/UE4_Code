<<<<<<< HEAD
// Fill out your copyright notice in the Description page of Project Settings.
//#include "BuildingEscapeGameMode.h" if 4.17+, has to be first.
#include "BuildingEscape.h"
#include "PositionReporter.h"
//#include "Gameframework/Actor.h" Use this if 4.16 and above.


// Sets default values for this component's properties
UPositionReporter::UPositionReporter()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	

	// ...
}


// Called when the game starts
void UPositionReporter::BeginPlay()
{
	Super::BeginPlay(); //Do whatever is up the inheritance tree. Do this first. Generated.
	//Runs once at the start of the game.
	FString ObjectName = GetOwner()->GetName(); //* is overloaded.
	UE_LOG(LogTemp, Warning, TEXT("Position report reporting for duty on %s"), *ObjectName); //UE_LOG and TEXT are macros.
	//Macros are scary.
}


// Called every frame
void UPositionReporter::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

=======
// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingEscape.h"
#include "PositionReporter.h"


// Sets default values for this component's properties
UPositionReporter::UPositionReporter()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPositionReporter::BeginPlay()
{
	Super::BeginPlay(); //Do whatever is up the inheritance tree. Do this first. Generated.
	//Runs once at the start of the game.
	// ... New.
	
}


// Called every frame
void UPositionReporter::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

>>>>>>> origin/master
