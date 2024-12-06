#include "parser.h"
#include <stack>

std::vector<Parser::Token> Parser::tokenize(const std::string& input) {
    std::vector<Token> tokens;
    std::string current;
    
    for(size_t i = 0; i < input.length(); i++) {
        char c = input[i];
        
        if(isspace(c)) continue;
        
        if(isdigit(c) || c == '.') {
            current += c;
        } else {
            if(!current.empty()) {
                tokens.emplace_back(Token::Number, current);
                current.clear();
            }
            
            if(c == '+' || c == '-' || c == '*' || c == '/') {
                tokens.emplace_back(Token::Op, std::string(1, c));
            } else if(c == '(' || c == ')') {
                tokens.emplace_back(Token::Paren, std::string(1, c));
            }
        }
    }
    
    if(!current.empty()) {
        tokens.emplace_back(Token::Number, current);
    }
    
    return tokens;
}