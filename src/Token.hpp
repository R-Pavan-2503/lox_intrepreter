#pragma once

#include "TokenType.hpp"
#include <string>

class Token
{
public:
    TokenType type;
    std::string lexeme;
    std::string literal;
    int line;

    Token(TokenType type, const std::string &lexeme, const std::string &literal, int line);
};
