#include "Scanner.hpp"
#include <iostream>

Scanner::Scanner(const std::string &source)
    : source(source), start(0), current(0), line(1) {}

std::vector<Token> Scanner::scan_tokens()
{
    while (!is_at_end())
    {
        start = current;
        scan_token();
    }

    tokens.emplace_back(TokenType::EOF_TOKEN, "", "", line);
    return tokens;
}

bool Scanner::is_at_end() { return current >= source.length(); }
void Scanner::scan_token()
{
    char c = advance();
    switch (c)
    {
    case '(':
        add_token(LEFT_PAREN);
        break;
    case ')':
        add_token(RIGHT_PAREN);
        break;
    case '{':
        add_token(LEFT_BRACE);
        break;
    case '}':
        add_token(RIGHT_BRACE);
        break;
    case ',':
        add_token(COMMA);
        break;
    case '.':
        add_token(DOT);
        break;
    case '-':
        add_token(MINUS);
        break;
    case '+':
        add_token(PLUS);
        break;
    case ';':
        add_token(SEMICOLON);
        break;
    case '*':
        add_token(STAR);
        break;
    case '!':
        add_token(match('=') ? BANG_EQUAL : BANG);
        break;
    case '=':
        add_token(match('=') ? EQUAL_EQUAL : EQUAL);
        break;
    case '<':
        add_token(match('=') ? LESS_EQUAL : LESS);
        break;
    case '>':
        add_token(match('=') ? GREATER_EQUAL : GREATER);
        break;
    default:
        std::cerr << "[line " << line << "] Error: Unexpected character." << std::endl;
        break;
    }
}

char Scanner::advance() { return source[current++]; }
void Scanner::add_token(TokenType type) { add_token(type, ""); }
void Scanner::add_token(TokenType type, const std::string &literal)
{
    std::string lexeme = source.substr(start, current - start);
    tokens.emplace_back(type, lexeme, literal, line);
}
bool Scanner::match(char expected)
{
    if (is_at_end() || source[current] != expected)
    {
        return false;
    }
    current++;
    return true;
}