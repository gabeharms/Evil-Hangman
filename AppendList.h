//AppendList.h - class that stores all of the appending list functions
//written by gabe harms

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class AppendList
{
public:

	AppendList()
	{
	}

	//Function that removes words that don't match the current high pattern
	vector<string> NarrowDownList(vector<string> head, string& highword, char letter) 
	{

		cout << "Computing. Please wait";
		int count =0;
		int display1, display2, display3, display4;
		display1 = head.size()/5; display2 = 2*display1; display3 = 3*display1; display4 = 4*display1;
		//loop runs through and checks every word to 
		//see if it matches the highpattern
		for (int i = 0; i < head.size(); i++)
		{
			if (count == display1 || count == display2 || count == display3 || count == display4)
				cout << ".";
			//converts word into a pattern for comparison
			string tempword =  MakeString(head[i], letter, head[i].length());

			//if the word's pattern doesn't match the highpattern
			//it is erased from the list
			if (tempword != highword)
			{
				head.erase(head.begin() + i) ;
				i--;
			}
			count++;
		}
		cout << endl;
		return head;
	}

	//Puts words from .txt into a vector of string arrays
	void PlaceWordsInList(vector<string> head[30], string filename)  {
		ifstream inputFile;
		inputFile.open(filename);
		string word;

		cout << "\nGathering Words. Please wait";

		//loop runs through and adds each word to a vector based on its length
		int wordcount = 0;
		while (inputFile >> word) {

			//displays a . every so often in the loop, so that the user
			//knows that it is working
			if(wordcount == 25400 || wordcount == 50800 || wordcount == 76200 || wordcount == 101600) 
				cout << ".";

			//adds words to a vector determined by its length
			head[word.length() - 1].push_back(word);
			wordcount++;
		}
		cout << "\nThis file contains " << wordcount << " words\n\n";

		inputFile.close();
	}

	//after the game has ran through once this 
	//function takes the vector of words that was used
	//and recompiles the list from the dictionary file
	//to recover words that may have been deleted during the game
	//so that it can be used in the next game
	vector<string> ResetUsedList (vector<string> head[30], string& filename, int lengthofword) {
		ifstream inputFile;
		inputFile.open(filename);
		string word;

		//goes through the vector that was used, and deletes every word from it
		while (!head[lengthofword -1].empty())
		{
			head[lengthofword-1].pop_back();
		}

		//the function now re-adds all of the words
		//including ones that were deleted from last game
		while (inputFile >> word) {
			if (word.length() == lengthofword) {
				head[lengthofword -1].push_back(word);
			}
		}
		inputFile.close();
		return head[lengthofword -1];
	}


	// Delete every element of the list to recycle the memory.
	void deleteList(vector<string> head[30]) {
		cout << "Deleting Words. Please wait";
		
		int count = 0;
		while (count <= 29)
		{
			//outputs a . every now and then to show user that
			//it is at work
			if (count == 4 || count == 7 || count == 14)
				cout << ".";

			while (!head[count].empty())
			{
				head[count].pop_back();

			}
			count++;
		}
	}
private:

	//converts a string into a pattern based on the letter that was guessed
	//if the letter is e, and the current word is eat, its pattern is e--
	string MakeString(string& word1, char letter, int length)
	{
		string wordresult;

		for (int i =0; i < length; i++) {
			char compare = word1[i];
			if (compare == letter) {
				wordresult += letter;
			}
			else {
				wordresult += "-";
			}

		}
		return wordresult;
	}

};