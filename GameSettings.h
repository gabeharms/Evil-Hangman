//GameSettings.h - meant to hold all functions that create the game settings
//written by gabe harms

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class GameSettings
{
public:
	GameSettings()
	{
	}

	//Prompts user for a word length
	int GetWordLength() {
		cout <<"How many letters do you want your word to have\n";
		int lengthofword;
		cin >> lengthofword;

		//checks to make sure wordlength 
		//that was choosen is valid
		while(lengthofword <= 0 || lengthofword > 30 || lengthofword ==26 || lengthofword == 27) {
			cout <<"\nSorry that is not a valid word length.\nHow many letters do you want your word to have\n";
			cin >> lengthofword;
		}
		cout << "\n";
		return lengthofword;
	}

	//Prompts user for number of guesses
	int GetNumberOfGuesses() {
		cout << "How many guesses would you like to have\n";
		int guesses;
		cin >> guesses;

		//makes sure the user enters a number 
		//greater than zero
		while (guesses <= 0) {
			cout << "Sorry, Please enter a number greater than zero.\nHow many guesses would you like to have\n";
			cin >> guesses;
		}
		cout << "\n";
		return guesses;
	}


	//Finds out if the user wants a running total
	bool DisplayRunningTotal() {
		bool showwordsremaining;
		string YesorNo;
		cout << "Do you want to know the remaining total number of word? Y(y)/N(n)\n";
		cin >> YesorNo;
		cout << "\n";

		//if yes the function returns true
		if (YesorNo == "Y" || YesorNo == "y") {
			showwordsremaining = true;
		}
		//if not the function returns false
		else {
			showwordsremaining = false;
		}
		return showwordsremaining;
	}


	//Displays all of the information the user needs to know
	void DisplayGameInfo(vector<string> head, int guesses, bool RunningTotal, string& lettersguessed, int lengthofword) {
		int wordsremaining = 0;
		//words remaining is equal to the size of the vector
		wordsremaining = head.size();

		cout << "\nNumber of guesses remaining: " << guesses << "\n";
		//iff user wants a running total, it displays it
		if (RunningTotal) {
			cout << "Number of Words Remaining: " << wordsremaining << "\n";
		}
		cout << "Letters that have been guessed: " << lettersguessed << "\n\n";

	}

	//Prompts user for a filename and verifys that it exists
	string GetFileName() {

		string filename;
		string word;
		ifstream inputFile;
		inputFile.open(filename);

		

		while (1>0) {	
			cout <<"What is the name of the dictionary file? (dictionary.txt)\n";
			cin >> filename;
			inputFile.open(filename);
			
			//makes sure that file exists
			//if it does not then it displays an error
			//and makes them try again
			if(inputFile >> word) {
				inputFile.close();
				return filename;
			}
			else {
				cout << "Error: This File does not exist. Please Try again\n";
			}
		}
	}

	//Prompts user to enter a letter to guess
	char GetLetterToBeGuessed(string& WordsGuessed) {
		cout <<"What Letter?\n";
		char letter;
		int StringLength = WordsGuessed.length();
		cin >> letter;
	
		//if letter was already guessed, then 
		//it makes the user re-enter
		while (1>0) {
			if (WasLetterAlreadyGuessed(WordsGuessed, StringLength, letter)) {
				cout <<"Error: Invalid letter\nWhat Letter?\n";
				cin >> letter;
			}
			else {
				cout << "\n";
				return letter;
			}
		}
	}

private:


	//Checks to see if letter was already guessed 
	bool WasLetterAlreadyGuessed(string& WordsGuessed, int StringLength, char letter) {

		//if letter = letters guessed, then it returns true
		for(int i = 0; i < StringLength; i++) {
			if (letter == WordsGuessed[i]) {
				return true;
			}
		}	

		//makes sure the user entered a letter
		bool IsItALetter = IsLetterActuallyALetter(letter);
		if(IsItALetter == true) {
			return false;
		}
		else {
			return true;
		}
	}



	//check if char input is a letter
	bool IsLetterActuallyALetter(char letter) {
		
		//if the char is between a and z it is a letter
		//otherwise it is not
		if (letter >= 'A' && letter <= 'z') {
			if (letter < '[' || letter >= 'a') {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}



};
