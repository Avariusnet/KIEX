#ifndef STATEMENTS
#define STATEMENTS

#include <string>
#include <vector>
#include <iostream>

class Statements
{
public:
	static std::vector<std::string> statementValues;
	static void                     findStatement(std::string key);
};

#endif