#include"GuessingGame.h"
#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>

//constructor
GuessingGame::GuessingGame()
{
	getAllTimeScores();                      //get the total wins and losses from the file	
	srand(time(0));                          //seed random once
}

//destructor
GuessingGame::~GuessingGame()
{
}

//play the number guessing game
void GuessingGame::playGame()
{
	RandomNumber = rand() % 100 + 1;          //generate a random number between 1 and 100
	MaxOfGuesses = 20;                        //set the maximum number of guesses to 20
	AmountOfGuesses = 0;                      //initialize the amount of guesses the user has made to 0
	bool CorrectGuess = false;		          //initialize the correct guess to false

	std::cout << "You have 20 attempts to guess the correct number between 0 and 100!" << std::endl;

	while (AmountOfGuesses < MaxOfGuesses)
	{
		std::cout << "Please enter your guess: ";
		std::cin >> guess;

		
		if (guess < 1 || guess>100)           //ensure the user's guess is between 1 and 100
		{
			std::cout << "Invalid choice, please enter a number between 1 and 100!" << std::endl;
			continue;                 
		}

		AmountOfGuesses++;                    //increment the amount of guesses the user has made

		if (guess == RandomNumber)            //checks if the user's guess is correct
		{
			CorrectGuess = true;
			getMessagesWinlost(true);         //display a random win message
			TotalOfWins++; 		              //increment the total number of wins
			break;
		}
		else if (guess < RandomNumber) {
			std::cout << "Too low! ";         //provide feedback if the user's guess is too low
		}
		else {
			std::cout << "Too high! ";        //provide feedback if the user's guess is too high
		}
		std::cout << "You have " << MaxOfGuesses - AmountOfGuesses << " guesses left!" << std::endl;
	}

			
	if (!CorrectGuess)                 
	{
		getMessagesWinlost(false);            //display a random loss message
		std::cout << "Sorry, you have run out of guesses! The correct number was: " << RandomNumber << std::endl;
		TotalOfLosses++;                      //increment the total number of losses
	}

	saveAllTimeScores();                      //save the total wins and losses to the file

	while (true) {                            //ask the user if they would like to play again
		getMessages();                        //display a random message to play again
		std::cin >> playAgain;

		if (playAgain == "y")
		{
			std::cout << "You have chosen to play the game!Welcome Again" << std::endl;
			playGame();                       //play the game again
			break;
		}
		else if (playAgain == "n")
		{
			std::cout << "Thank you for playing, Goodbye !" << std::endl;
			break;
		}
		else
		{
			std::cout << "Invalid choice, please try again! enter 'y' or 'n'" << std::endl;
		}

	}
}
//get the total wins and losses from the file
void GuessingGame::getAllTimeScores()
{
	std::ifstream inputfile;
	inputfile.open("GuessingGameData.dat");    //open the file
	inputfile >> TotalOfWins;		           //read the total number of wins from the file
	inputfile >> TotalOfLosses;                //read the total number of losses from the file
	inputfile.close();                         //close the file


}

//save the total wins and losses to the file
void GuessingGame::saveAllTimeScores()
{
	std::ofstream outputfile;                   
	outputfile.open("GuessingGameData.dat");    //open the file
	outputfile << TotalOfWins << std::endl;     //save the total number of wins to the file
	outputfile << TotalOfLosses << std::endl;   //save the total number of losses to the file
	outputfile.close();     	                //close the file
}

//display the total wins and losses
void GuessingGame::displayAllTimeScores()
{
	std::cout << "Total Wins: " << TotalOfWins << std::endl;
	std::cout << "Total Losses: " << TotalOfLosses << std::endl;
}

//reset all time scores (wins and losses) to 0
void GuessingGame::resetScores()
{
	TotalOfWins = 0;
	TotalOfLosses = 0;
	saveAllTimeScores();
	std::cout << "Scores have been reset!" << std::endl;
}

//display a random win/loss message
void GuessingGame::getMessagesWinlost(bool win)
{
	int RandomMessage = rand() % 10 + 1;         //generate a random message between 1 and 10
	
	if (win)                                     //if the user has won the game
	{
		switch (RandomMessage)
		{
			case 1:
				std::cout << "CONGRATS! You are on fire, you guessed the correct number!" << std::endl;
				break;
			case 2:
				std::cout << "Fantastic ! You have guessed the correct number!" << std::endl;
				break;
			case 3:
				std::cout << "Genius! GOT IT RIGHT !" << std::endl;
				break;
			case 4:
				std::cout << "What a win! correct number indeed!" << std::endl;
				break;
			case 5:
				std::cout << "RIGHT!! No one have done it better! You are a pro!" << std::endl;
				break;
			case 6:
				std::cout << "Ding, ding, ding! We have a winner!" << std::endl;
				break;
			case 7:
				std::cout << "Woohoo! That’s the winning guess right there!" << std::endl;
				break;
			case 8:
				std::cout << "Boom! That’s what we’re talking about!" << std::endl;
				break;
			case 9:
				std::cout << "Winner, winner, number-guessing champion!" << std::endl;
				break;
			case 10:
				std::cout << "Yes! That’s how it’s done, amazing work!" << std::endl;
				break;

		}
	}
	
	else
	{

		switch (RandomMessage)                   //if the user has lost the game
		{
			case 1:
				std::cout << "Close, but no cigar!" << std::endl;
				break;
			case 2:
				std::cout << "Missed it this time, but I believe in you!" << std::endl;
				break;
			case 3:
				std::cout << "Better luck next time! The number’s still hiding!" << std::endl;
				break;
			case 4:
				std::cout << "Nope! The number remains a mystery!" << std::endl;
				break;
			case 5:
				std::cout << "Not even close! The number laughs in your face!" << std::endl;
				break;
			case 6:
				std::cout << "Wrong answer! Better sharpen those guessing skills!" << std::endl;
				break;
			case 7:
				std::cout << "Swing and a miss! The number survives!" << std::endl;
				break;
			case 8:
				std::cout << "Fail! The number stays safe for now!" << std::endl;
				break;
			case 9:
				std::cout << "Absolutely not! That guess was tragic" << std::endl;
				break;
			case 10:
				std::cout << "Big miss! The number remains undefeated!" << std::endl;
				break;
		}
	}
}


//display a random message to play again
void GuessingGame::getMessages()
{
	
	int RandomMessage = rand() % 10 + 1;         //generate a random message between 1 and 10

	switch (RandomMessage)
	{
		case 1:
			std::cout << "Hmm, care to give it another shot?" << std::endl;
			break;
		case 2:
			std::cout << "Not quite—want to take another guess?" << std::endl;
			break;
		case 3:
			std::cout << "Missed it! Shall we go again?" << std::endl;
			break;
		case 4:
			std::cout << "Ready for another round?" << std::endl;
			break;
		case 5:
			std::cout << "Wrong guess! Wanna give it another go?" << std::endl;
			break;
		case 6:
			std::cout << "So close! Feel like trying again?" << std::endl;
			break;
		case 7:
			std::cout << "Oops, not the one! Up for another attempt?" << std::endl;
			break;
		case 8:
			std::cout << "Missed it! What do you say to another round?" << std::endl;
			break;
		case 9:
			std::cout << "Missed it! Feel lucky enough to try again?" << std::endl;
			break;
		case 10:
			std::cout << "Swing and a miss! Ready to strike out again?" << std::endl;
			break;
	}
}
