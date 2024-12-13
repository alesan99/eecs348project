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
                // Check for invalid parentheses combinations
                if (!tokens.empty() && tokens.back().type == Token::Paren) {
                    if (c == ')' && tokens.back().value == "(") {
                        throw std::runtime_error("Empty parentheses are invalid");
                    }
                    if (c == '(' && tokens.back().value == ")") {
                        throw std::runtime_error("Invalid parentheses order");
                    }
                }
                tokens.emplace_back(Token::Paren, std::string(1, c));
            }
        }
    }
   
    if(!current.empty()) {
        tokens.emplace_back(Token::Number, current);
    }

    // Validate balanced parentheses
    int parenCount = 0;
    for (const auto& token : tokens) {
        if (token.type == Token::Paren) {
            if (token.value == "(") parenCount++;
            else parenCount--;
            
            if (parenCount < 0) {
                throw std::runtime_error("Unmatched closing parenthesis");
            }
        }
    }
    if (parenCount > 0) {
        throw std::runtime_error("Unmatched opening parenthesis");
    }
   
    return tokens;
}

Parser::Node* Parser::parseTokens(const std::vector<Token>& tokens) {
    std::stack<Node*> output;
    std::stack<Token> operators;
   
    for(const Token& token : tokens) {
        switch(token.type) {
            case Token::Number:
                output.push(new Node(token.value));
                break;
               
            case Token::Op: {
                while(!operators.empty() &&
                      operators.top().type == Token::Op &&
                      precedence.at(operators.top().value) >= precedence.at(token.value)) {
                    Token op = operators.top();
                    operators.pop();
                   
                    Node* right = output.top(); output.pop();
                    Node* left = output.top(); output.pop();
                   
                    Node* newNode = new Node(op.value);
                    newNode->left = left;
                    newNode->right = right;
                    output.push(newNode);
                }
                operators.push(token);
                break;
            }
               
            case Token::Paren:
                if(token.value == "(") {
                    operators.push(token);
                } else { // ")"
                    while(!operators.empty() && operators.top().value != "(") {
                        Token op = operators.top();
                        operators.pop();
                       
                        Node* right = output.top(); output.pop();
                        Node* left = output.top(); output.pop();
                       
                        Node* newNode = new Node(op.value);
                        newNode->left = left;
                        newNode->right = right;
                        output.push(newNode);
                    }
                    if(!operators.empty()) operators.pop(); // pop "("
                }
                break;
        }
    }
   
    while(!operators.empty()) {
        Token op = operators.top();
        operators.pop();
       
        Node* right = output.top(); output.pop();
        Node* left = output.top(); output.pop();
       
        Node* newNode = new Node(op.value);
        newNode->left = left;
        newNode->right = right;
        output.push(newNode);
    }
   
    return output.empty() ? nullptr : output.top();
}