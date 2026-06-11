#include "lexer.hpp"
using namespace std;

Lexer::Lexer(const string& source)
{
    m_source = source;
}

vector<Token> Lexer::tokenize()
{
  vector<Token> tokens;

  tokens.push_back({
        TokenType::Number,
        "5"
    });

    tokens.push_back({
        TokenType::End,
        ""
    });

    return tokens;
}