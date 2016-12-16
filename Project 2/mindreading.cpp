//
// CS 31 Winter 2015
// File: HW #2 - Reading My Mind
// Author:
// SID:
// Date: 2015-1-26
// Version 1.0
// Description: Project #2 for Computer Science 31
//


#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	cout << "======================================" << endl;
	cout << "Mindreading (v1.0)" << endl;
	cout << "Copyright 2015 Bruinie" << endl;
	cout << "" << endl;
	cout << "Welcome to Mindreading Game!" << endl;
	cout << "Good luck and have fun!" << endl;
	cout << "======================================" << endl;

	cout << "Please make the following selections: " << endl;

	string playerName;

	//Get users name
	cout << "Your Name: ";

	//Error trapping for user name
	while (playerName.length() == 0) {
		getline(std::cin, playerName);
		if (playerName.length() == 0) {
			cout << "You must enter your name." << endl;
		}
	}

	//Get level of difficulty
	int levelOfDifficulty;
	cout << "Level of Difficulty (1 - Easy; 2 - Hard): ";
	cin >> levelOfDifficulty;
	while (levelOfDifficulty != 1 && levelOfDifficulty != 2) {
		switch (levelOfDifficulty) {
		case 1:
		case 2:
			break;
		default:
			//Error trapping for invalid level
			cout << "Level of difficulty must be 1 (Easy) or 2 (Hard)." << endl;
			cin >> levelOfDifficulty;
			continue;
		}
	}

	//Get the smallest integer that the user wants to guess
	int smallestInt;
	cout << "The smallest positive integer you want to guess: ";
	cin >> smallestInt;

	//Error trapping for invalid integer
	while (smallestInt <= 0) {
		cout << "It must be a positive integer." << endl;
		cin >> smallestInt;
		continue;
	}

	//Get the largest integer that the user wants to guess
	int largestInt;
	cout << "The largest positive integer you want to guess: ";
	cin >> largestInt;
	
	//Get the largest integer that the user wants to guess
	while (largestInt <= 0) {
		cout << "It must be a positive integer." << endl;
		cin >> largestInt;
		continue;
	}

	//Error trapping for range of integers
	while (largestInt < smallestInt) {
		cout << "The biggest integer must be greater than the smallest integer." << endl;
		cin >> largestInt;
		continue;
	}

	//Calculate the number of guesses each difficulty will have based on integer range
	double amountOfGuesses;
	if (levelOfDifficulty == 1) {
		amountOfGuesses = ceil(0.8 * log2(largestInt - smallestInt + 1));
	}
	else if (levelOfDifficulty == 2) {
		amountOfGuesses = ceil(0.4 * log2(largestInt - smallestInt + 1));
	}

	//Loop of actual game
	char newGame = 'Y';
	while (newGame = 'Y') {
		int attemptedGuesses = 0;

		int randomGeneratedNumber = rand() % largestInt + smallestInt;
		srand(randomGeneratedNumber);

		int guessingNumber;

		cout << "Awesome, " << playerName << "! I'm thinking of an integer between " << smallestInt << " and " << largestInt
			<< ". Make a guess." << endl;
		cin >> guessingNumber;
		while (guessingNumber != -1) {
			attemptedGuesses++;
			if (guessingNumber == randomGeneratedNumber) {
				cout << "Congratulations, " << playerName << "! You guessed the secret number " << randomGeneratedNumber << "!"
					<< endl;
				cout << "<Play Statistics>" << endl;
				cout << "- Name: " << playerName << endl;
				cout << "- Level: " << levelOfDifficulty << endl;
				cout << "- Total number of times to guess " << randomGeneratedNumber << ": " << attemptedGuesses << endl;
				break;
			}
			else {
				if (attemptedGuesses == amountOfGuesses) {
					cout << "Sorry, " << playerName << "! Game Over!" << endl;
					break;

				}
				else {
					switch (levelOfDifficulty) {
					case 1:
						if (guessingNumber < randomGeneratedNumber){
							cout << "Sorry, " << playerName
								<< "! I'm thinking of a larger number. Try again or enter -1 to exit." << endl;
						}
						else {
							cout << "Sorry, " << playerName
								<< "! I'm thinking of a smaller number. Try again or enter -1 to exit." << endl;
						}
						break;
					case 2:
						if (guessingNumber < randomGeneratedNumber) {
							cout << "Sorry, " << playerName << "! Try again or enter -1 to exit." << endl;
						}
						else {
							cout << "Sorry, " << playerName << "! Try again or enter -1 to exit." << endl;
						}
						break;
					}
				}
				cin >> guessingNumber;
				//Exit the game
				if (guessingNumber == -1) {
					cout << "Sorry, " << playerName << "! Goodbye!" << endl;
					return 0;
				}
			}
		}
		//Start new game
		if (guessingNumber != -1)
		{
			cout << "Do you want to play another game (Y/N)?" << endl;
			cin >> newGame;
			//Check for valid input
			while (newGame != 'Y' && newGame != 'N')
			{
				cout << "You must enter either Y or N." << endl;
				cin >> newGame;
			}
			if (newGame == 'N' && attemptedGuesses == amountOfGuesses)
			{
				//Exit program for no more games played
				cout << "Sorry, " << playerName << "! Goodbye!" << endl;
				return 0;
			}
			if (newGame == 'N')
			{
				cout << "Thank you for reading my mind, " << playerName << "! Goodbye!" << endl;
				return 0;
			}
		}
		else
		{
			cout << "Sorry, " << playerName << "! Goodbye!" << endl;
			return 0;
		}
	}
}
