#include <iostream>
#include <fstream>
#include <sstream>
#include "Statements.h"

int main()
{
	// in stream
	std::ifstream in("D:/WoW/Gitlab/ProgramingLanguage/Programming-Language/Debug/Example.kiex");
	std::streambuf* instream = std::cin.rdbuf();
	std::cin.rdbuf(in.rdbuf());
	std::vector<char> file;
	
	// removing useless characters
	bool inString = false;
	while (!std::cin.eof())
	{
		int character = std::cin.get();
		if (character == 34)
		{
			file.push_back(character);
			if (inString)
				inString = false;
			else
				inString = true;
		}
		else if (!inString)
		{
			if (character != 32 && character != 13 && character != 10 && character != 9)
				file.push_back(character);
		}
		else
			file.push_back(character);
	}
	
	// reset output location
	for (int i = 0; i < file.size(); i++)  //input from the file in.txt
	{
		std::cout << file[i];
	}

	std::getchar();
	return 0;
}