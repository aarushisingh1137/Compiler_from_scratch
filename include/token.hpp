#pragma once

enum class TokenType
{
    Number,
    Plus,
    End
};

struct Token
{
    TokenType type;
    std::string value;
};