#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <boost/progress.hpp> //contains a process timer that when you put it in a function will print out 
								//how long the function took to run
#include <filesystem>
#include <regex>
#include "ProgramInput.hpp"
#include "DirectorySearch.hpp"
using namespace std;
using namespace std::tr2::sys;

namespace fs = std::tr2::sys;

int main(int argc, char *argv[])
{
	ProgramInput input;
	if(argc != 0 && argv != NULL)
	{
		if(input.ParseInput(argv, argc) == 0)
		{
			cout << "im sorry the parameters you have entered are incorrect.";
			return EXIT_FAILURE;
		}
	}
	else
	{
		cout << "im sorry the parameters you have entered are incorrect.";
		return EXIT_FAILURE;
	}
		 
	if(input.getArgs().empty())
	{
		"im sorry the parameters you have entered are incorrect.";
		return EXIT_FAILURE;
	}

	if(input.getExtensions().size() == 0)
	{
		//add a txt extension to search for as the default. 
		input.addExtension(".txt");
	}
	DirectorySearch search;
	if(search.SearchThroughDirectory(input.getArgs(), input.getDirectory(), input.getExtensions(), input.getVerboseMode()) == 0)
	{
		cout << "im sorry the parameters you have entered are incorrect.";
		return EXIT_FAILURE;	
	}

	
	cout << "Matches found: " << endl;
	//Verbose mode (-v) displays the name of each file scanned (as they are scanned) and each match found (as they are found).
	if(!input.getVerboseMode())
	{

		//The report sorts the matches, first by file, then by line number (so you must not report results until the scan is complete).  
		for(unsigned int i = 0; i < search.getMatchingLines().size(); ++i)
		{
			cout <<  search.getMatchingLines()[i].file << " line: " << search.getMatchingLines()[i].lineNumber << endl;
		}
	}

	system("pause");
}