#include <iostream>
#include "lexer.hpp"
using namespace std;

int main()
{
  Lexer lexer("123 +45*6-7/8");
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
        else if (token.type == TokenType::End)  std::cout << "End"<<endl;
    }
    
    return 0;
}