/* This is the console executable, that makes use of BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interactions. For game logic see the FBullCowGame class.
*/

#include <iostream> //Standard libraries.
#include <string>
//#include "" Your code or other code.
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int; //primitive, technically a double declare.


//using namespace std; //This makes std::std::cout unnecessary.
//People don't like using FOR NAMESPACES ONLY.

//Gotta do this so it knows it's there.
//Called a prototype.
//Will eventually go into a header file.
void game_introduce();
void game_play();
FText GetValidGuess();
void game_repeatGuess(FText &Guess);
bool game_AskToPlayAgain();

FBullCowGame BCGame; //Global Scope
//Generally bad thing, is good for stuff that needs to be accessed by multiple things/a single instance.

//The Entry Point for our program
int main()
{
	//constexpr int NUMBER_OF_TURNS = 5;
	bool bPlayAgain = false;
	do
	{
		game_introduce();
		game_play();
		//TODO add a game summary
		bPlayAgain = game_AskToPlayAgain();
	} 
	while (bPlayAgain == true);

	return 0; //Exit the program.
}

void game_introduce()
{
	// introduce the game

	std::cout << "\n\nWelcome to Bulls and Cows, a fun word game." << std::endl;  //Curly braces, namespace to avoid confusion between same naming. std::cout is odd in that it uses overloaded operators. Piping, kinda.
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?" << std::endl;

	return;
}

void game_play()
{
//Default Constructor, Instantiate a new game.
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	//std::cout << MaxTries << std::endl;
	std::cout << std::endl;

	//loop asking for guesses while the game is NOT won AND there are still tries remaining.

	//loop for the number of turns asking for guesses.
	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	//for (int32 count = 0; count < MaxTries; count++) //TODO use a while loop in a for loop like way, but with logic proofreading.
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

	//Don't use todo for things that aren't inserted.
	//TODO summarise game
}

FText GetValidGuess() //loop continually until user gives a valid guess.
{
	FText Guess = "";
	int32 currentGuess = 0;
	//Check status and give feedback.
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do 
	{
		currentGuess = BCGame.GetCurrentTry();
		//get a guess from the player
		std::cout << "Try " << currentGuess << ". Make a guess: ";
		getline(std::cin, Guess); //Automatically ends at newline. Stops at spaces. If there's stuff left, you can eat it with other std::cin statements.
								  //std::cout << std::endl;


		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
			case EGuessStatus::Wrong_Length:
				std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word. \n";
				break;
			case EGuessStatus::Not_Isogram:
				std::cout << "Please enter a word without repeating letters. \n";
				break;
			case EGuessStatus::Not_Lowercase:
				std::cout << "Please enter all lowercase lettrs. \n";
				break;
			default:
				break; //Assume the guess is valid.
		}
	std::cout << std::endl;
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

bool game_AskToPlayAgain()
{
	std::cout << "Do you want to play again? (Y/N)";
	FText Response = "";
	getline(std::cin, Response);
	std::cout << std::endl;

	return (Response[0] == 'y') || (Response[0] == 'Y');
}
