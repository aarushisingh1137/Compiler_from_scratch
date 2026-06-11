#pragma once

#include <vector>

#include "token.hpp"
#include "ast.hpp"

class Parser
{
public:
    Parser(const std::vector<Token>& tokens);

    Expr* parse();

private:
    std::vector<Token> m_tokens;
    size_t m_current;
    Token current();
    void advance();
    Expr* factor();
    Expr* term();
    Expr* expression();
};