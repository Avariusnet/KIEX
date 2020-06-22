
#ifndef INCLUDE_KIEXASTPARSER_H
#define INCLUDE_KIEXASTPARSER_H

#include <iostream>
#include "Lexer.hpp"


	class ASTParser {
	public:
		static ASTParser* instance();
		
		void Generator(Lexer::Generator& Generator);

	private:
		std::vector<std::string> m_outputQueue;
		std::vector<std::string> m_operatorQueue;

	};


	

		
	class Node {


	public: 
	

	};


	class BinOP : Node {

	public:
		Node left;
		std::string token;
		Node right;
		// Deconstructor
		~BinOP() { };

		// Constructor
		BinOP(Node Left ,std::string Token, Node Right)
		{
			left = Left;
			token = Token;
			right = Right;
		}
	};

	class Integer : Node {
	public:

		std::string token;
		int value;

		// Constructor 
		Integer(std::string Token, int Value) {
			token = Token;
			value = Value;
		};

		// Deconstructor
		~Integer() { };
	};



#define sASTParser ASTParser::instance()
#endif