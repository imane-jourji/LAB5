#include <iostream>
#include <string>

#ifndef GUESSINGGAME_H
#define GUESSINGGAME_H

class GuessingGame
{
public:
	GuessingGame();                     //constructor
	~GuessingGame();                    //destructor
	void playGame();                    //play the number guessing game
	void displayAllTimeScores();        //display the total wins and losses
	void resetScores();                 //reset all time scores (wins and losses) to 0

private: 
	void getAllTimeScores();			//get the total wins and losses from the file
	void saveAllTimeScores();           //save the total wins and losses to the file
	void getMessagesWinlost(bool won);  //display a random win/loss message
	void getMessages();                 //display a random message to play again


	int guess = 0;						//the user's guess
	int RandomNumber = 0;               //the random number to guess
	int MaxOfGuesses = 0;				//the maximum number of guesses					
	int AmountOfGuesses = 0;			//the amount of guesses the user has made
	std::string playAgain; 			    //the user's choice to play again
	int TotalOfWins = 0;			    //the total number of wins
	int TotalOfLosses = 0;              //the total number of losses
};


#endif									//!GUESSINGGAME_H
