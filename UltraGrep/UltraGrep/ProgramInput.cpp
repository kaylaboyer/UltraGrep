#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <Windows.h>
#include <algorithm>
#include <string>
#include <process.h>
#include <boost/regex.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string/split.hpp>
#include "ProgramInput.hpp"
using namespace std;

int ProgramInput::ParseInput(char *argv[], int i)
{
	//boost::trim_left(parse);
	vector<string> eachWord;
	for( int j = 1; j < i; ++j)
	{
		eachWord.push_back(argv[j]);
	}

	if(eachWord[0] != "ultragrep")
	{
		return 0;
	}

	if(eachWord.size() > 1)
	{
		if(eachWord[1] == "-v")
		{
			this->inVerboseMode = true;
			if(eachWord.size() == 4)
				{
					args = eachWord[3];
					directory = eachWord[2];
				}
				if(eachWord.size() == 5)
				{
					args = eachWord[3];
					directory = eachWord[2];
					eachWord[4].erase(0,1); //get rid of leading period 
					boost::split(extensions, eachWord[4], boost::is_any_of("."));
					for(unsigned int j = 0; j < extensions.size(); ++j)
					{
						extensions[j] = "." + extensions[j];
					}
				}
		}//end if verbose. 
		else
		{
			//we were not given verbose. 
			if(eachWord.size() == 3)
			{
				directory = eachWord[1];
				args = eachWord[2];
			}
			else if(eachWord.size() == 4)
			{
				directory = eachWord[1];
				args = eachWord[2];
				eachWord[3].erase(0,1); //get rid of leading period 
				boost::split(extensions, eachWord[3], boost::is_any_of("."));
				for(unsigned int j = 0; j < extensions.size(); ++j)
				{
					extensions[j] = "." + extensions[j];
				}
					
			}//end else if 
			else
			{
				//we have been given an incorrect number of parameters
				return 0;
			}
		}//end else 
	}//end size check 


	return 1;
}//end method 