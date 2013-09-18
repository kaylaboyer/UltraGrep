#include <vector>

class ProgramInput 
{
private:
	std::string args;
	std::string directory;
	std::vector<std::string> extensions;
	bool inVerboseMode;
	
public:
		
	ProgramInput()
	{
		args = "";
		directory = "";
		inVerboseMode = false;
	}

	std::string getArgs() {return args;}
	std::string getDirectory() {return directory;}
	std::vector<std::string> getExtensions() {return extensions;}
	bool getVerboseMode() { return inVerboseMode;}
	void addExtension(std::string x) {extensions.push_back(x);}
	int ParseInput(char *argv[], int i );

};

