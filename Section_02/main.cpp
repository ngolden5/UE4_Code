/* This is the console executable, that makes use of BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interactions. For game logic see the FBullCowGame class.
*/
#pragma once

#include <iostream> 
#include <string>
#include "FBullCowGame.h"


//to make syntax Unreal friendly
using FText = std::string; 
using int32 = int; 

//function prototypes
void game_introduce();
void game_play();
void game_repeatGuess(FText &Guess);
bool game_askToPlayAgain();
void game_printSummary();

FText GetValidGuess();

FBullCowGame BCGame; //Instantiate a new game, which we re-use across plays

//The Entry Point for our program
int main()
{
	bool bPlayAgain = false;
	do
	{
		game_introduce();
		game_play();
		bPlayAgain = game_askToPlayAgain();
	} 
	while (bPlayAgain == true);

	return 0; //Exit the program.
}

void game_introduce()
{
	// introduce the game
	std::cout << "\n\nWelcome to Bulls and Cows, a fun word game." << std::endl;  
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?" << std::endl;

	return; //Good habit to place returns at the end.
}

//plays a single game to completion
void game_play()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	std::cout << std::endl;

	//loop asking for guesses while the game is NOT won AND there are still tries remaining.
	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText guess = GetValidGuess(); 

		//Submit valid guess to the game.
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(guess);

		//Print number of bulls and cows.
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
		game_repeatGuess(guess);
		std::cout << std::endl;
	}

	game_printSummary();
	return;
}

FText GetValidGuess() 
{
	FText Guess = "";
	int32 currentGuess = 0;
	//Check status and give feedback.
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do 
	{
		currentGuess = BCGame.GetCurrentTry();

		std::cout << "Try " << currentGuess << " of " << BCGame.GetMaxTries();
		std::cout << ". Make a guess: ";

		//get a guess from the player
		getline(std::cin, Guess); 
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
			case EGuessStatus::Wrong_Length:
				std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word. \n\n";
				break;
			case EGuessStatus::Not_Isogram:
				std::cout << "Please enter a word without repeating letters. \n\n";
				break;
			case EGuessStatus::Not_Lowercase:
				std::cout << "Please enter all lowercase lettrs. \n\n";
				break;
			default:
				break; //Assume the guess is valid.
		}
	} while (Status == EGuessStatus::OK); //Keep looping until we get valid input

	return Guess;
}

void game_repeatGuess(FText &Guess)
{
	//repeat the guess back to them
	std::cout << "Your guess is: ";
	std::cout << Guess;
	std::cout << std::endl;
}

bool game_askToPlayAgain()
{
	std::cout << "Do you want to play again with the same hidden word? (Y/N)";
	FText Response = "";
	getline(std::cin, Response);
	std::cout << std::endl;

	return (Response[0] == 'y') || (Response[0] == 'Y');
}

void game_printSummary()
{
	//Bad Grammar used intentionally here. Check Urban Dictionary for more info.
	if (BCGame.IsGameWon()) { std::cout << "You're winner!\n"; }
	else{ std::cout << "Too bad. You ran out of tries.\n"; }
}
