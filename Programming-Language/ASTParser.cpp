#include "ASTParser.h"


ASTParser* ASTParser::instance()
{
	static ASTParser instance;
	return &instance;
}

void ASTParser::Generator(Lexer::Generator& Generator) {
	for (std::size_t i = 0; i < Generator.size(); ++i)
	{


		Lexer::token t = Generator[i];
		std::string type = t.to_str(t.type).c_str();
		if (t.type == e_number)
			sASTParser->m_operatorQueue.push_back(t.value);

		printf("Token is %s and value is %s \n", t.to_str(t.type).c_str(), t.value.c_str());


	}
}