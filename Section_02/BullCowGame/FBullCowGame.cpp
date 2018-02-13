#include "FBullCowGame.h"
//Magic words and constants.
constexpr int32 DEFAULT_MAX_TRIES = 8;
const FText HIDDEN_WORD = "planet";
using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	MyCurrentTry = 1;
	MyMaxTries = DEFAULT_MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	return;
}

int32 FBullCowGame::GetMaxTries() const //Can't modify variables.
{
	return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const //Only works on member/class functions.
{
	return MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

bool FBullCowGame::IsGameWon() const
{
	return bGameIsWon;
}

bool FBullCowGame::IsIsogram() const
{
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FText Guess) const
{
	if (false) 	//if guess isn't an isogram, return error
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false) 	//if guess isn't all lowercase, return error
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (GetHiddenWordLength() != Guess.length()) 	//if guess length is wrong, return error
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;	//else return ok
	}
}

//@input valid guess
//increments
FBullCowCount FBullCowGame::SubmitValidGuess(FText Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;

	//loop through all letters in the hidden word
	int32 WordLength = GetHiddenWordLength(); //assuming same length as guess
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
	{
		//compare letters against the guess
		for (int32 GChar = 0; GChar < WordLength; GChar++)
		{
			//if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar])
			{
				if (MHWChar == GChar) //If they're in the same place.
				{
					BullCowCount.Bulls++; //increment bulls
				}
				else
				{
					BullCowCount.Cows++; //increment cows
				}
			}
		}

	}
	if (BullCowCount.Bulls == WordLength)
		bGameIsWon = true;
	else
		bGameIsWon = false;

	return BullCowCount;
}
