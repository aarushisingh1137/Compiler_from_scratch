#include "ast_printer.hpp"
#include <iostream>

void printAST(Expr* expr)
{
    if (auto number =
        dynamic_cast<NumberExpr*>(expr))
    {
        std::cout << number->value;
        return;
    }

    if (auto binary =
        dynamic_cast<BinaryExpr*>(expr))
    {
        std::cout << "(";

        printAST(binary->left);

        if (binary->op == TokenType::Plus)
            std::cout << " + ";

        else if (binary->op == TokenType::Minus)
            std::cout << " - ";

        else if (binary->op == TokenType::Star)
            std::cout << " * ";

        else if (binary->op == TokenType::Slash)
            std::cout << " / ";

        printAST(binary->right);

        std::cout << ")";
    }
}