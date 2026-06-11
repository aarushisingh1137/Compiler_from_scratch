// src/parser.cpp
#include "parser.hpp"

Parser::Parser(const std::vector<Token>& tokens)
{
    m_tokens = tokens;
    m_current = 0;
}

Expr* Parser::parse()
{
  /* Token token = m_tokens[m_current];

    if (token.type == TokenType::Number)
    {
        int value = std::stoi(token.value);

        return new NumberExpr(value);
    } */
    return assignment();
}

Token Parser::current()
{
    return m_tokens[m_current];
}

void Parser::advance()
{
    m_current++;
}

Token Parser::peek()
{
    return m_tokens[m_current + 1];
}

Expr* Parser::factor()
{
    Token token = current();

    if (token.type == TokenType::Number)
    {
        int value = std::stoi(token.value);

        advance();

        return new NumberExpr(value);
    }

    if (token.type == TokenType::LeftParen)
    {
        advance(); // consume ( -> basically ignore parenthesis and build the expression between it

        Expr* expr = expression();

        if (current().type == TokenType::RightParen)
        {
            advance(); // consume )
        }

        return expr;
    }

    if (token.type == TokenType::Identifier)
    {
        advance();
        return new VariableExpr(token.value);
    }

    return nullptr;
}

Expr* Parser::term()
{
    Expr* left = factor();

    while (
        current().type == TokenType::Star ||
        current().type == TokenType::Slash)
    {
        TokenType op = current().type;

        advance();

        Expr* right = factor();

        left = new BinaryExpr(
            left,
            op,
            right
        );
    }

    return left;
}
Expr* Parser::expression()
{
    Expr* left = term();

    while (
        current().type == TokenType::Plus ||
        current().type == TokenType::Minus)
    {
        TokenType op = current().type;

        advance();

        Expr* right = term();

        left = new BinaryExpr(
            left,
            op,
            right);
    }

    return left;
}

Expr* Parser::assignment()
{
    if (
        current().type == TokenType::Identifier &&
        peek().type == TokenType::Assign)
    {
        std::string variableName =
            current().value;

        advance(); // consume identifier

        advance(); // consume '='

        Expr* value =
            expression();

        return new AssignmentExpr(
            variableName,
            value);
    }

    return expression();
}