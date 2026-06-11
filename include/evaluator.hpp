#pragma once

#include "ast.hpp"
#include <unordered_map>

int evaluate(Expr* expr, std::unordered_map<std::string,int>&symbols);