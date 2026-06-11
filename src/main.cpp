#include <iostream>
#include "lexer.hpp"
using namespace std;

int main()
{
  Lexer lexer("5 + 3");
    cout << "AaruLang Compiler started" << endl;
    auto tokens = lexer.tokenize();

    for (const auto& token : tokens)
    {
        cout << token.value << endl;
    }
    return 0;
}