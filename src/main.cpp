#include <iostream>
#include "lexer.hpp"
#include "parser.hpp"
#include "ast_printer.hpp"
#include "evaluator.hpp"
using namespace std;

int main()
{
  Lexer lexer("x = 5 + 3");
    cout << "AaruLang Compiler started" << endl;
    auto tokens = lexer.tokenize();

    for (const auto& token : tokens)
    {
        cout << token.value <<" and ";
        if (token.type == TokenType::Number)    std::cout << "Number"<<endl;
        else if (token.type == TokenType::Plus) std::cout << "Plus"<<endl;
        else if (token.type == TokenType::Minus) std::cout << "Minus"<<endl;
        else if (token.type == TokenType::Star) std::cout << "Star"<<endl;
        else if (token.type == TokenType::Slash) std::cout << "Slash"<<endl;
        else if (token.type == TokenType::LeftParen) std::cout << "LeftParen"<<endl;
        else if (token.type == TokenType::RightParen) std::cout << "RightParen"<<endl;
        else if (token.type == TokenType::Identifier) std::cout << "Idemtifier"<<endl;
        else if (token.type == TokenType::Assign) std::cout << "Assign"<<endl;
        else if (token.type == TokenType::Semicolon) std::cout << "Semicolon"<<endl;
        else if (token.type == TokenType::End)  std::cout << "End"<<endl;
    }

    Parser parser(tokens);
    Expr* expr = parser.parse();

    printAST(expr);
    cout << endl;

    unordered_map<string,int> symbols;
    int result = evaluate(expr,symbols);

    cout << "Result = "<< result<< endl;
    
    return 0;
}