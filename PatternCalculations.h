//PatternCalculation - class that holds functions that calculate the patterns

#include <iostream>
#include <string>
#include <vector>
#include "Display.h"


using namespace std;

class PatternCalculations 
{
public:
	PatternCalculations()
	{
	}

	//function that gets the pattern with the highest frequency
	//so that it can elliminate words without that pattern later
	string GetHighPatternCount (vector<string> head, int WordLength, char letter) 
	{

		string temppattern;
		string secondtemp;
		PatternList patterns;

		//generate a list of patterns and store the count of each pattern in the patterncount vector
		for(int i=0; i < head.size(); i++) {
			temppattern = MakeString(head[i], letter, WordLength);

			//adds the pattern to the vector if its the first pattern
			if (i == 0) {
				patterns.push_back(temppattern);
			}
			//otherwise it compares it with the other patterns in the pattern vector
			//if the pattern already exists, it increments the patterncount of that pattern
			//if it doesn't exist it adds the pattern to the vector
			else {

				patterns.compare(temppattern, i);

			}
		}

		int size = patterns.patterncount.size(); 
		int highcount = patterns.patterncount[0];
		string HighPattern = patterns.pattern[0];

		//compares all the patterns
		for (int j = 1; j < patterns.patterncount.size();j++) {
			
			//if a pattern has a higher count than another, then it becomes the highpattern 
			if (highcount <= patterns.patterncount[j]) {
				if (highcount == patterns.patterncount[j]) {
					if (HighPattern > patterns.pattern[j]) {
						HighPattern = patterns.pattern[j];
					}
				}
				else{ 
					HighPattern = patterns.pattern[j];
				}
			}


		}



		//used only for debugging
		//Display display;
		//display.DisplayPattern(patterns);
		
		patterns.Delete();
		return HighPattern;		
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