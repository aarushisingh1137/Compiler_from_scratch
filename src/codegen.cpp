#include "codegen.hpp"
#include "lexer.hpp"
#include "parser.hpp"
#include "ast_printer.hpp"
#include "evaluator.hpp"

std::string generateCode(
    Expr* expr,
    std::unordered_map<std::string, int>& symbols,
    int& nextOffset)
{
  if (auto program =
    dynamic_cast<Program*>(expr))
  {
    std::string code;

    for (Expr* statement :
         program->statements)
    {
        code += generateCode(statement,symbols,nextOffset);
    }

    return code;
  }
    if (auto number =
        dynamic_cast<NumberExpr*>(expr))
    {
        return
            "mov rax, " +
            std::to_string(
                number->value) +
            "\n";
    }

    if (auto binary =
    dynamic_cast<BinaryExpr*>(expr))
  {
    std::string code;

    code += generateCode(binary->left,symbols,nextOffset);

    code += "push rax\n";

    code += generateCode(binary->right,symbols,nextOffset);

    code += "pop rbx\n";

    if (binary->op == TokenType::Plus)
    {
        code += "add rax, rbx\n";
    }

    if (binary->op == TokenType::Minus)
    {
    code += "sub rbx, rax\n";
    code += "mov rax, rbx\n";
    }

   if (binary->op == TokenType::Star)
    {
    code += "imul rax, rbx\n";
    }

    return code;
  }

  if (auto assignment =
    dynamic_cast<AssignmentExpr*>(expr))
  {
    if (
        symbols.find(
            assignment->name)
        == symbols.end())
    {
        symbols[
            assignment->name]
            = nextOffset;

        nextOffset -= 8;
    }

    std::string code;

    code += generateCode(
        assignment->value,
        symbols,
        nextOffset);

    int offset =
        symbols[
            assignment->name];

    code +=
        "mov [rbp"
        + std::to_string(offset)
        + "], rax\n";

    return code;
  }

  if (auto variable =
    dynamic_cast<VariableExpr*>(expr))
{
    int offset =
        symbols[
            variable->name];

    return
        "mov rax, [rbp"
        + std::to_string(offset)
        + "]\n";
}

    return "codegen reached";
}

std::string generateProgram(Expr* expr)
{
    std::unordered_map<
        std::string,
        int> symbols;

    int nextOffset = -8;

    std::string body =
        generateCode(
            expr,
            symbols,
            nextOffset);

    std::string program;

    program +=
        ".intel_syntax noprefix\n";

    program +=
        ".global main\n\n";

    program +=
        "main:\n";

    program +=
        "    push rbp\n";

    program +=
        "    mov rbp, rsp\n";

    program +=
        "    sub rsp, 32\n\n";

    program += body;

    program += "\n";

    program +=
        "    mov rsp, rbp\n";

    program +=
        "    pop rbp\n";

    program +=
        "    ret\n";

    program +=
    "\n.section .note.GNU-stack,\"\",@progbits\n";

    return program;
}