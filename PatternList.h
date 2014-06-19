
#include<string>
#include<iostream>
#include<vector>

using namespace std;

class PatternList
{

public:
	//constructor
	PatternList()
	{

	}


	//Inserts the value into this Vector at specified index
	//oves the tail to the right to accomodate the new element
	void push_back(const string& value)
	{
		pattern.push_back(value);
		patterncount.push_back(1);

	}

	//void insert(const string& value, int index)


	//compares a pattern to the patterns already in the list
	//if the pattern already is in the list, it increments the count of that pattern
	//if the pattern doesn't exist yet, then it adds it to the list
	void compare(string& value , const int index)
	{
		for ( int i = 0; i < pattern.size();i++)
		{
			//if pattern matches a pattern already in the list,
			//then it increases the count of that pattern
			if ( pattern[i] == value )
			{
				patterncount[i]++;
				break;
			}
			else if (pattern[i] < value) 
			{
				//if if has reached the end of the list it adds the new pattern
				//else it does nothing, and the for loop continues to run
				if (i == pattern.size()-1) {

					pattern.push_back(value);
					patterncount.push_back(1);
					break;
				}		
			}
			else if (pattern[i] > value) 
			{	
				//pattern has reached end of the list and adds the new pattern
				pattern.insert(pattern.begin() + i, value);
				patterncount.insert(patterncount.begin()+i, 1);
				break;
			}
		}
	}

	
	


	//destructor
	void Delete()
	{
		while (pattern.size() != 0)
		{
			pattern.pop_back();
		}
		while (patterncount.size() != 0)
		{
			patterncount.pop_back();
		}
	}


	vector<string> pattern;
	vector<int> patterncount;
private:


};