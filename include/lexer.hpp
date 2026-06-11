#pragma once

#include <string>
#include <vector>

#include "token.hpp"

class Lexer
{
public:
    Lexer(const std::string& source);

    std::vector<Token> tokenize();

private:
    std::string m_source;
};