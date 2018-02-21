#pragma once
#include <string>

//to make syntax Unreal friendly
using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	OK,
	Not_Isogram,
	Empty,
	Invalid_Char,
	Wrong_Length,
	Not_Lowercase,
	Invalid_Status
};


class FBullCowGame 
{
public:
	FBullCowGame(); //constructor
	void Reset(); 

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;

	EGuessStatus CheckGuessValidity(FString) const; 
	FBullCowCount SubmitValidGuess(FString);

private:
	bool IsIsogram(FString) const; //Check to see if prefix b is used in Unreal Coding Standards
	bool IsLowercase(FString) const;
	bool bCheckForDupeLetters();
	bool bGameIsWon;
	int32 MyCurrentTry;
	FString MyHiddenWord;

};