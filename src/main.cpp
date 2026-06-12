#include <iostream>
#include "lexer.hpp"
#include "parser.hpp"
#include "ast_printer.hpp"
#include "evaluator.hpp"
#include "codegen.hpp"
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char* argv[])
{
  if (argc != 2)
    {
    cout
        << "Usage: ./compiler <file.aaru>"
        << endl;

    return 1;
    }

  ifstream file(argv[1]);

  if (!file)
  {
    cout
        << "Could not open file."
        << endl;

    return 1;
  }
  stringstream buffer;
  buffer << file.rdbuf();
  string source = buffer.str();

/* Lexer lexer(
    "x=5;"
    "x+2;"
); */
  cout << "SOURCE START\n";
cout << source << endl;
cout << "SOURCE END\n";
  Lexer lexer(source);
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

    /* std::unordered_map<std::string, int> codegenSymbols;
    int nextOffset = -8;
    cout
    << generateCode(
        expr,
        codegenSymbols,
        nextOffset)
    << endl; */
    
    //cout<< generateProgram(expr)<< endl;

    std::ofstream out("output.s");
    out << generateProgram(expr);
    out.close();

    int buildResult = system("g++ -no-pie output.s -o program");
    if (buildResult != 0)
    {
      cout<< "Assembly compilation failed."<< endl;
      return 1;
    }
    cout<< "Executable generated successfully."<< endl;

    return 0;
}