#pragma once
#include "token.hpp"

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