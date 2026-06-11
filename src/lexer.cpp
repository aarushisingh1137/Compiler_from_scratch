#include <iostream>
#include "lexer.hpp"
using namespace std;

Lexer::Lexer(const string& source)
{
    m_source = source;
}

vector<Token> Lexer::tokenize()
{
  vector<Token> tokens;

  int i=0;
    while (i < m_source.length())
  {
    char c = m_source[i];

    if (isdigit(c))
    {
        std::string number = "";

        while (i < m_source.length() && isdigit(m_source[i]))
        {
            number += m_source[i];
            i++;
        }
        tokens.push_back({
        TokenType::Number,
        number
      });
      continue;
    }

    if (c == '+')
    {
      tokens.push_back({
          TokenType::Plus,
          "+"
      });

      i++;
      continue;
    }

    if (c == '-')
    {
      tokens.push_back({
          TokenType::Minus,
          "-"
      });

      i++;
      continue;
    }

    if (c == '*')
    {
      tokens.push_back({
          TokenType::Star,
          "*"
      });

      i++;
      continue;
    }

    if (c == '/')
    {
      tokens.push_back({
          TokenType::Slash,
          "/"
      });

      i++;
      continue;
    }

    if(c==' ')
    {
      i++;
      continue;
    }

  }

    tokens.push_back({
        TokenType::End,
        ""
    });

    return tokens;
}