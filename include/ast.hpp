#pragma once
#include "token.hpp"
#include <string>
#include <vector>

struct Expr
{
    virtual ~Expr() = default;
};

struct NumberExpr : Expr
{
    int value;

    NumberExpr(int v)
        : value(v)
    {
    }
};

struct BinaryExpr : Expr
{
    Expr* left;
    Expr* right;
    TokenType op;

    BinaryExpr(
        Expr* lhs,
        TokenType operation,
        Expr* rhs)
        : left(lhs),
          right(rhs),
          op(operation)
    {
    }
};

struct VariableExpr : Expr
{
    std::string name;

    VariableExpr(const std::string& variableName)
        : name(variableName)
    {
    }
};

struct AssignmentExpr : Expr
{
    std::string name;
    Expr* value;

    AssignmentExpr(
        const std::string& variableName,
        Expr* expression)
        : name(variableName),
          value(expression)
    {
    }
};

struct Program : Expr
{
    std::vector<Expr*> statements;
};