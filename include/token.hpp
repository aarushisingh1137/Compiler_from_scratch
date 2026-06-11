#pragma once

enum class TokenType
{
    Number,
    Plus,
    Minus,
    Star,
    Slash,
    End
};

struct Token
{
    TokenType type;
    std::string value;
};