#include <experimental/filesystem>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Lexer.hpp"
#include "Ast.hpp"

int main(int argc, char* argv[])
{
	std::streambuf* instream = std::cin.rdbuf();
	std::ifstream in;
	if(argv[1] != nullptr)
		in.open(argv[1]);
	else
	{
		std::string temp = std::experimental::filesystem::current_path().string();
		temp.resize(temp.length() - 21);
		temp += "\\Debug\\Example.Kiex";
		in.open(temp);
	}
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