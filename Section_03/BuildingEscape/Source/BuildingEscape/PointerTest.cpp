// Nicholas Golden (c) 2018

#include "BuildingEscape.h"
#include "PointerTest.h"


// Sets default values for this component's properties
UPointerTest::UPointerTest()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UPointerTest::ValueLog()
{
	UE_LOG(LogTemp, Warning, TEXT("Val1 is %d"), val1)
	UE_LOG(LogTemp, Warning, TEXT("Val2 is %d"), val2)
	UE_LOG(LogTemp, Warning, TEXT("Valptr is %d"), *valptr)
	UE_LOG(LogTemp, Warning, TEXT("Valref is %d"), valref)

	UE_LOG(LogTemp, Warning, TEXT("Val1 is at %p"), val1)
	UE_LOG(LogTemp, Warning, TEXT("Val2 is at %p"), val2)
	UE_LOG(LogTemp, Warning, TEXT("Valptr is at %p"), *valptr)
	UE_LOG(LogTemp, Warning, TEXT("Valref is at %p"), valref)
}

// Called when the game starts
void UPointerTest::BeginPlay()
{
	Super::BeginPlay();

	ValueLog();

	valptr = &val2;
	UE_LOG(LogTemp, Error, TEXT("Repoint the pointer."))
	ValueLog();

	*valptr = 12;
	UE_LOG(LogTemp, Error, TEXT("Change the pointer"))
	ValueLog();

	valref = 42;
	UE_LOG(LogTemp, Error, TEXT("Change the reference."))
	ValueLog();


}



// Called every frame
void UPointerTest::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

