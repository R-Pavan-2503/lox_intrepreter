#include "TokenHelper.hpp"
#include "TokenType.hpp"

void TokenHelper::print_token(const Token &token)
{
    std::cout << TokenTypeHelper::to_string(token.type)
              << " " << token.lexeme
              << " " << (token.literal.empty() ? "null" : token.literal)
              << std::endl;
}
