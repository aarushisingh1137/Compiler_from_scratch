#include "ast_printer.hpp"
#include <iostream>

void printAST(Expr* expr)
{
    if (auto program =
    dynamic_cast<Program*>(expr))
    {
    for (Expr* statement : program->statements)
    {
        printAST(statement);
        std::cout << std::endl;
    }
    return;
    }

    if (auto number =
        dynamic_cast<NumberExpr*>(expr))
    {
        std::cout << number->value;
        return;
    }

    if (auto assignment = dynamic_cast<AssignmentExpr*>(expr))
    {
        std::cout << "("
                << assignment->name
                << " = ";

        printAST(assignment->value);

        std::cout << ")";

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

     if (auto variable =
        dynamic_cast<VariableExpr*>(expr))
    {
        std::cout << variable->name;
        return;
    }
}