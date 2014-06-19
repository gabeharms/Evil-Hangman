//Display.h - holds all of the functions that output to the console
//written by game harms

#include <iostream>
#include <vector>
#include <string>
#include "PatternList.h"

using namespace std;

class Display
{
public:

	Display()
	{
	}


	//This function is only used for debugging and displays words in a given length group 
	void DisplayList(vector<string> head) 
	{
		cout << "List:\n";
		int counter = 0;
		while (counter < head.size()) {
			cout  <<head[counter] << "      " << head[counter].size() <<"\n";
			counter++;
		}
	}

	//This function is used only for debugging and displays the patterns
	void DisplayPattern(PatternList patterns) 
	{
		cout << "Patterns:\n";
		for (int i =0; i < patterns.pattern.size(); i++) 
		{
			cout  <<patterns.pattern[i] << "      " << patterns.patterncount[i] <<"\n";
		}
	}

	//Checks to see if you have won the game
	bool WonGame(string& hiddenword, int wordlength) {

		//if all of the -'s have been removed from the hiddenword
		//then you win
		for(int i =0; i < wordlength; i++) {
			if (hiddenword[i] == '-' ) {
				return false;
			}

		}
		return true;
	}



	//Displays if the user won or lost and what the word was
	bool DisplayGameResult(string& hiddenword, int lengthofword,vector<string> head) {
		string YesorNo;	
		bool playagain;

		//the user won, and reveals the word
		if(WonGame(hiddenword, lengthofword)) {
			cout << "\nCongratulations You Win!\n";
			cout << "The word was " << hiddenword << "\n";
		}
		//user lost
		else {
			string randomanswer;

			//generates random answer, since there are multiple words
			//left, we have to choose one to tell the user
			randomanswer = head[lengthofword-1];
			cout << "\nYou lose.\n";
			cout <<"The word was " << randomanswer << "\n";
		}
		
		//finds out whether the user wants to play again
		cout << "Would You like to play again? Y(y)/N(n)\n";
		cin >> YesorNo;
		if (YesorNo == "Y" || YesorNo == "y") {
			playagain = true;
		}
		else {
			playagain = false;
		}
		return playagain;
	}




private:



};