/*
	Imane Jourji
	Computer Science Fall 2024
	Due : Monday October 12, 2024 11:59pm
	Lab 4 : Guessing Game
	This lab's goal is to make a number-guessing game in which the computer selects a random number in the range of 0 to 100
*/


#include<iostream>
#include"GuessingGame.h"

int main ()
{
	//create an object of the GuessingGame class
	GuessingGame GuessingGame;
	int choice = 0;         //stores the user's choice

	std::cout << "Welcome to the Number Guessing Game!" << std::endl;

	while (true)            //display the menu until the user chooses to exit
	{
		std::cout << "1. Play Game" << std::endl;
		std::cout << "2. Display All Time Scores" << std::endl;
		std::cout << "3. Reset Scores" << std::endl;
		std::cout << "4. Exit" << std::endl;

		std::cout << "Enter your choice: ";
		std::cin >> choice;

		switch (choice) 
		{
			case 1:
				GuessingGame.playGame();
				break;
			case 2:
				GuessingGame.displayAllTimeScores();
				break;
			case 3:
				GuessingGame.resetScores();
				break;
			case 4:
				std::cout << "Goodbye!" << std::endl;
				return 0;
			default:
				std::cout << "Invalid choice. Please try again." << std::endl;
				break;
		}
	}
	return 0;
}