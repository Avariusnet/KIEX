#include <iostream>
#include <fstream>
#include <sstream>
#include "Lexer.hpp"
#include "Ast.hpp"

int main()
{
	std::streambuf* instream = std::cin.rdbuf();
	std::ifstream in("D:/Projekte/ProgramingLanguage/Example.kiex");
	std::cin.rdbuf(in.rdbuf());

	std::string file;

	while(!std::cin.eof())
		file.push_back(std::cin.get());

	Lexer::Generator gen;
	gen.process(file);
	ASTParser::Ast::Generator(gen);
	Lexer::helper::dump(gen);

	/*
	// reset output location
	for (int i = 0; i < file.size(); i++)  //input from the file in.txt
	{
		std::cout << file[i];
	}
	*/
	std::getchar();
	return 0;
}