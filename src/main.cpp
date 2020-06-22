#include <filesystem>
#include "KIEXConfig.h"
#include "Lexer.hpp"
#include "Ast.hpp"

int main(int argc, char* argv[])
{
	printf_s("KIEX Program file parser.\nVersion: %i %i %i %i\nCompiled: %s %s\n\n",
		KIEX_VERSION_MAJOR, KIEX_VERSION_MINOR, KIEX_VERSION_PATCH, KIEX_VERSION_BUILD,
		KIEX_COMPILE_DATE, KIEX_COMPILE_TIME);
	if (argc <= 1)
	{
		printf_s("To use this tool a KIEX program file needs to be passed in.\n");
		std::getchar();
		return EXIT_FAILURE;
	}

	for (int i = 1; i < argc; i++)
	{
		// Open our file, make sure there is no errors.
		FILE* fileStream;
		if (fopen_s(&fileStream, argv[i], "r") != NULL)
		{
			printf_s("Unable to open file %s, ensure it exists.\n", argv[i]);
			std::getchar();
			return EXIT_FAILURE;
		}

		// Get the length of the file.
		fseek(fileStream, 0, SEEK_END);
		long fileLen = ftell(fileStream);
		fseek(fileStream, 0, SEEK_SET);

		// Copy file bytes into buffer
		char* buffer = (char*)malloc(fileLen);
		fread(buffer, sizeof(char), fileLen, fileStream);

		fclose(fileStream);

		Lexer::Generator gen;
		gen.process(buffer);
		ASTParser::Ast::Generator(gen);
		Lexer::helper::dump(gen);

		/*
		// reset output location
		for (int i = 0; i < file.size(); i++)  //input from the file in.txt
		{
			std::cout << file[i];
		}
		*/
	}
	std::getchar();
	return EXIT_SUCCESS;
}