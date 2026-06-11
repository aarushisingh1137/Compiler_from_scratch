#include "evaluator.hpp"

int evaluate(Expr* expr)
{
    if (auto number =
        dynamic_cast<NumberExpr*>(expr))
    {
        return number->value;
    }

    if (auto binary =
        dynamic_cast<BinaryExpr*>(expr))
    {
        int left =
            evaluate(binary->left);

        int right =
            evaluate(binary->right);

        if (binary->op == TokenType::Plus)
            return left + right;

        if (binary->op == TokenType::Minus)
            return left - right;

        if (binary->op == TokenType::Star)
            return left * right;

        if (binary->op == TokenType::Slash)
            return left / right;
    }

    return 0;
}