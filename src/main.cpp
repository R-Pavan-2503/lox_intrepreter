#include "Scanner.hpp"
#include "TokenHelper.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

std::string read_file_contents(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error reading file: " << filename << std::endl;
        exit(1);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    return buffer.str();
}

int main(int argc, char *argv[])
{
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;

    if (argc < 3)
    {
        std::cerr << "Usage: ./your_program tokenize <filename>" << std::endl;
        return 1;
    }

    std::string command = argv[1];
    if (command == "tokenize")
    {
        std::string source = read_file_contents(argv[2]);
        Scanner scanner(source);
        std::vector<Token> tokens = scanner.scan_tokens();

        for (const Token &token : tokens)
        {
            TokenHelper::print_token(token);
        }
    }
    else
    {
        std::cerr << "Unknown command: " << command << std::endl;
        return 1;
    }

    return 0;
}
