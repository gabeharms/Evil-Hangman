//HiddenWord.h - stores all hidden word functions
//written by gabe harms


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class HiddenWord
{
public:

	HiddenWord()
	{
	}
	//generates a hidden word based on the length of the word
	//chosen by the user
	string CreateHiddenWord(int lengthofword) {
		string hiddenword;

		//for loop adds the - character for lengthofword many times
		for (int i =0; i < lengthofword; i++) {
			hiddenword += "-";
		}
		return hiddenword;
	}

	//reveals part of the hidden word based on the highpattern count
	//if the high pattern count is -a--, then the hidden word now becomes -a--
	string RevealPartOfHiddenWord (int lengthofword, string& hiddenword, string& tempword) {
		string temp = hiddenword;

		//runs through the highpattern and the hiddenword
		//if the hiddenword changes to make sure it matches the highpattern
		for ( int i=0; i < lengthofword; i++) {
			if (tempword[i] != '-') {
				hiddenword[i] = tempword[i];
			}
		}
		cout << "\nWord:\n" << hiddenword << "\n";

		//tells if letter wasn't in word
		if (temp == hiddenword) {
			cout << "\nSorry, that letter is not in the word";
		}
		//tells if letter was in word
		else {
			cout <<"\nCongradulations, that letter is in the word";
		}

		return hiddenword;
	}



private:

};