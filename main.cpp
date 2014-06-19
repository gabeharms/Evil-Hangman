//main.cpp -- jump off point for evil hangman game
//written by gabe harms
//810 lines



#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include "GameSettings.h"
#include "PatternCalculations.h"
#include "AppendList.h"
#include "HiddenWord.h"


using namespace std;



int main() {

	vector<string> head[30];

	string LettersGuessed;
	string TempWord;
	string DiffTemp;
	string FileName; 
	string TheHiddenWord;
	bool PlayAgain = true;	 
	bool RunningTotal;
	int LengthOfWord; 
	int Guesses;
	int HighCount;
	int Index;
	char Letter;

	//game setttings class has all of settings functions
	GameSettings gameSettings;

	//display class has all display functions
	Display display;

	//pattern calculations class 
	PatternCalculations patternCalculations;

	//Append List class has all list change functions
	AppendList appendList;

	//Hidden word class stores all hidden word functions
	HiddenWord hiddenWordFunctions;


	//Get Name Of File
	FileName = gameSettings.GetFileName();

	//Open dictionary File and store in a linked list by length
	appendList.PlaceWordsInList(head, FileName);

	//loop continues until the game is over and the user chooses not
	//to play again making "PlayAgain" false
	while(PlayAgain) {
		

		LettersGuessed = "";

		//Gets Length of word
		LengthOfWord = gameSettings.GetWordLength();


		//Create Array Index to use latter
		Index = LengthOfWord - 1;

		//Create a "hidden" word
		TheHiddenWord = hiddenWordFunctions.CreateHiddenWord(LengthOfWord);

		//Get number of Guesses
		Guesses = gameSettings.GetNumberOfGuesses();


		//Find whether they would like to have a running total of remaining words
		RunningTotal = gameSettings.DisplayRunningTotal();

		//Loop continues until the user runs out of guess, in which case they lose
		while (Guesses > 0)  {

			//Display information for the user
			gameSettings.DisplayGameInfo(head[Index], Guesses, RunningTotal, LettersGuessed, LengthOfWord); 


			//function used only for debugging
			//display.DisplayList(head[Index]);


			//Get Letter to guess from console
			Letter = gameSettings.GetLetterToBeGuessed(LettersGuessed);
			LettersGuessed =LettersGuessed + " " + Letter;


			//calculates the pattern count that has the highest amount of words in it
			//this pattern will be used to remove words that don't match the pattern
			TempWord =  patternCalculations.GetHighPatternCount(head[Index], LengthOfWord, Letter);

			//Attempt to delete cells that didn't belong to the highest pattern group. Realized that if the function is void, the edited node pointers don't get returned
			head[Index] = appendList.NarrowDownList(head[Index], TempWord, Letter);

			

			//For comparison later
			DiffTemp = TheHiddenWord;

			//Reveals information in the hidden word which is 
			//decided using the high pattern
			TheHiddenWord = hiddenWordFunctions.RevealPartOfHiddenWord(LengthOfWord, TheHiddenWord, TempWord);

			
			//if the user has revealed all of the characters of the hidden word
			//then they win
			if (display.WonGame(TheHiddenWord, LengthOfWord)) {
			break;
			}
		
			Guesses--;
		}
		//displays whether user won or lost and asks if they would like to play again
		PlayAgain = display.DisplayGameResult(TheHiddenWord, LengthOfWord, head[Index]);
		//the current vector has been edited and words have been removed from it
		//this function uses the dictionary file to restore the deleted words, 
		//so that they can be used again in the next game
		head[Index] = appendList.ResetUsedList(head, FileName, LengthOfWord);
	
	}

	//deletes list
	appendList.deleteList(head);
	
	

	system("pause");
}


