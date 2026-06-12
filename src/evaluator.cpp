#include "evaluator.hpp"
using namespace std;

int evaluate(Expr* expr, unordered_map<string,int>&symbols)
{
    if (auto program =
    dynamic_cast<Program*>(expr))
    {
        int result = 0;

        for (Expr* statement :
         program->statements)
        {
            result =
            evaluate(
                statement,
                symbols);
        }

        return result;
    }
    if (auto number =
        dynamic_cast<NumberExpr*>(expr))
    {
        return number->value;
    }

    if (auto variable =
        dynamic_cast<VariableExpr*>(expr))
    {
        return symbols[variable->name];
    }

    if (auto binary =
        dynamic_cast<BinaryExpr*>(expr))
    {
        int left =
            evaluate(binary->left,symbols);

        int right =
            evaluate(binary->right,symbols);

        if (binary->op == TokenType::Plus)
            return left + right;

        if (binary->op == TokenType::Minus)
            return left - right;

        if (binary->op == TokenType::Star)
            return left * right;

        if (binary->op == TokenType::Slash)
            return left / right;
    }

    if (auto assignment =
    dynamic_cast<AssignmentExpr*>(expr))
    {
        int value =
        evaluate(
            assignment->value,
            symbols);

        symbols[assignment->name]
        = value;

        return value;
    }

    return 0;
}