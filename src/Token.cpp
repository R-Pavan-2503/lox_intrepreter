#include "Token.hpp"

Token::Token(TokenType type, const std::string &lexeme, const std::string &literal, int line)
    : type(type), lexeme(lexeme), literal(literal), line(line) {}
