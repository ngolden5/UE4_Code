#pragma once
#include <string>

using FText = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus //strongly typed enum as opposed to the more "global" non-class version. Similar to Java.
{
	OK,
	Not_Isogram,
	Empty,
	Invalid_Char,
	Wrong_Length,
	Not_Lowercase,
	Invalid_Status
};

//using namespace is never used in header files. Ever. Some people don't like using namespace in the code.
class FBullCowGame 
{
public:
	FBullCowGame(); //constructor

	void Reset(); // TODO make a more rich return value. int WordLength as input.
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	bool IsIsogram() const;
	EGuessStatus CheckGuessValidity(FText) const; 

	//struct bulls & cows check
	// provide a method for counting bulls & cows, and increasing turn #
	//counts bulls % cows, and increases try # assuming valid guess.
	FBullCowCount SubmitValidGuess(FText);


//Ignore this and focus on the interface ^
private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FText MyHiddenWord;
	bool bGameIsWon;
};