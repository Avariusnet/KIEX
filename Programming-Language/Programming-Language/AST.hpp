
#ifndef INCLUDE_KIEXASTPARSER_HPP
#define INCLUDE_KIEXASTPARSER_HPP

#include <iostream>
#include "Lexer.hpp"

namespace ASTParser {

	class Ast {
	public:

		std::vector<std::string> outputQueue;
		std::vector<std::string> operatorQueue;

		static void Generator(Lexer::Generator& Generator) {
			for (std::size_t i = 0; i < Generator.size(); ++i)
			{
			

				Lexer::token t = Generator[i];
				std::string type = t.to_str(t.type).c_str();

				
				printf("Token is %s and value is %s \n", t.to_str(t.type).c_str(), t.value.c_str());

				
			}
		}
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



}

#endif