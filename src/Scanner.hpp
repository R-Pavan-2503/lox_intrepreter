#pragma once

#include "Token.hpp"
#include "TokenType.hpp"
#include <string>
#include <vector>

class Scanner
{
public:
    explicit Scanner(const std::string &source);
    std::vector<Token> scan_tokens();

private:
    std::string source;
    std::vector<Token> tokens;
    int start;
    int current;
    int line;

    bool is_at_end();
    void scan_token();
    char advance();
    void add_token(TokenType type);
    void add_token(TokenType type, const std::string &literal);
    bool match(char expected);
};
