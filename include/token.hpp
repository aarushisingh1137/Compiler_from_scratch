#include <string>
#pragma once

enum class TokenType
{
    Number,
    Plus,
    Minus,
    Star,
    Slash,
    LeftParen,
    RightParen,
    Identifier,
    Assign,
    Semicolon,
    End
};

struct Token
{
    TokenType type;
    std::string value;
};