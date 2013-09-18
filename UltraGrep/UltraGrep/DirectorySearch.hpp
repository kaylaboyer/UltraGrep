#include <regex>
#include <string>
#include <filesystem>
#include <vector>
#include <fstream>
#include <sstream>
#include <queue>
#include <map>
#include <iostream>

//needed to make a structure that simply keeps track of these 3 values. map would only keep track of two 
class fileLineMatch
{
public: 
	unsigned count;
	unsigned lineNumber;
	std::string file;
	std::string line;
};


class DirectorySearch
{
private:
	unsigned lineCount;
	std::regex reg;
	std::smatch m;
	std::vector<fileLineMatch> matchingLines;
	//std::vector<std::string> matchedFiles;

	unsigned int matchedFileCount;
	int SearchFileForWord(std::string args, std::string file, bool isVerbose);
 
public:
	DirectorySearch()
	{
		matchedFileCount = 0;
		lineCount = 0;
	}
	int SearchThroughDirectory(std::string args, std::string directory, std::vector<std::string> extensions, bool isVerbose);
	//std::vector<std::string> getMatchedFiles() {return matchedFiles;}
	int getMatchedFileCount() { return matchedFileCount;}
	std::vector<fileLineMatch> getMatchingLines() { return matchingLines;}
};

int DirectorySearch::SearchFileForWord(std::string args, std::string file, bool isVerbose)
{
	std::string line;
	this->reg = args;
	std::ifstream myFile(file);
	if(isVerbose)
	{
		std::cout << "File: " << file << ":"<< std::endl;
	}
	if(!myFile.is_open())
	{
		return 0;
	}
	else
	{
		while(myFile.good()) 
		{
			while(getline (myFile, line))
			{
				lineCount++;
				auto it = line.cbegin();
				auto end = line.cend();
				while(regex_search(it, end, m, reg))
				{
					if(m[0].matched == true)
					{
						this->matchedFileCount++;
						fileLineMatch match;
						match.file = file;
						match.lineNumber = lineCount;
						match.count = 1;
						match.line = line;
						if(isVerbose)
						{
							std::cout << "matched line: " << line << std::endl;
						}
						this->matchingLines.push_back(match);
						it = m[0].second;
					}						
				}//end while search
			}//end while getline 
			std::cout << "\n";
			lineCount = 0;
		}//end while myfile good 
	
	}

	return 1;
}

int DirectorySearch::SearchThroughDirectory(std::string args, std::string directory, std::vector<std::string> extensions, bool isVerbose)
{

		std::tr2::sys::path fullPath(directory);
		if( !exists( fullPath))
		{
			return 0;
		}
		if( !is_directory( fullPath ) ) 
		{
			return EXIT_FAILURE;
		}
		
		for( std::tr2::sys::recursive_directory_iterator dirIter( fullPath ), endIter; dirIter != endIter; ++ dirIter )
		{
			if(is_directory( dirIter->path() ) )
			{
				for(unsigned int i = 0; i < extensions.size(); ++i)
				{
					std::string test = dirIter->path().extension();
					if(dirIter->path().extension() == extensions[i])
					{
				
						int search = SearchFileForWord(args, dirIter->path(), isVerbose);
					}
				}
			}
			else
			{
				for(unsigned int i = 0; i < extensions.size(); ++i)
				{
					std::string test = dirIter->path().extension();
					if(dirIter->path().extension() == extensions[i])
					{
						int search = SearchFileForWord(args, dirIter->path(), isVerbose);
					}
				}
			}
		}
	return 1;
}