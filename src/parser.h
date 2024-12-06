#pragma once
#include <string>
#include <vector>

class Parser {
public:

    //Data structure which represents single character or operator
    struct Token {
        enum Type { Number, Op, Paren } type;
        std::string value;
        Token(Type t, std::string v) : type(t), value(v) {}
    };

    struct Node {
        std::string value;
        Node* left;
        Node* right;
        Node(std::string v) : value(v), left(nullptr), right(nullptr) {}
        ~Node() {
            delete left;
            delete right;
        }
    };
    //return array of tokens
    std::vector<Token> tokenize(const std::string& input);
    //return pointer to the Node
    Node* parseTokens(const std::vector<Token>& tokens);
};