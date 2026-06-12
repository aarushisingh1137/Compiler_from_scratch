#pragma once

#include "ast.hpp"
#include <string>

#include <unordered_map>

std::string generateCode(
    Expr* expr,
    std::unordered_map<std::string, int>& symbols,
    int& nextOffset);

    std::string generateProgram(Expr* expr);