#pragma once

#include "FBullCowGame.h"
#include <map>

//To make the code more easily transferable to Unreal. Using is more complicated because of parameters.
#define TMap std::map 

//Magic words and constants.
constexpr int32 DEFAULT_MAX_TRIES = 8;
const FString HIDDEN_WORD = "planet"; //Add other words, maybe dictionary, let user choose word length.
using int32 = int;

FBullCowGame::FBullCowGame(){ Reset(); }//default constructor

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }
bool FBullCowGame::bCheckForDupeLetters() { return false; }

void FBullCowGame::Reset()
{
	MyCurrentTry = 1;
	MyHiddenWord = HIDDEN_WORD;
	return;
}

int32 FBullCowGame::GetMaxTries() const
{
	TMap<int32, int32> WordLengthToMaxTries{ {3, 4}, {4,7}, {5,10}, {6,16}, {7, 20} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen;

	for (auto Letter : Word)
	{
		Letter = tolower(Letter); 
		if(LetterSeen[Letter]) { return false; }
		else{ LetterSeen[Letter] = true; }
	}

	return true; //for example in cases where /0 is entered
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (isupper(Letter)) { return false; }
	}
	return true;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	//Implicit dependencies. 

	//if guess isn't an isogram, return error
	if (!IsIsogram(Guess)) 	{ return EGuessStatus::Not_Isogram; }
	//if guess isn't all lowercase, return error
	else if (!IsLowercase(Guess) )	{ return EGuessStatus::Not_Lowercase; }
	//if guess length is wrong, return error
	else if (GetHiddenWordLength() != Guess.length()) { return EGuessStatus::Wrong_Length; }
	//else return ok
	else { return EGuessStatus::OK;	}
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = GetHiddenWordLength(); 

	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
	{
		for (int32 GChar = 0; GChar < WordLength; GChar++)
		{
			if (Guess[GChar] == MyHiddenWord[MHWChar])
			{
				//increment bulls
				if (MHWChar == GChar) { BullCowCount.Bulls++; }
				//increment cows
				else { BullCowCount.Cows++; }
			}
		}
	}

	if (BullCowCount.Bulls == WordLength) { bGameIsWon = true; }
	else { bGameIsWon = false; }

	return BullCowCount;
}

