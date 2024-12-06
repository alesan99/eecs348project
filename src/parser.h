#pragma once
#include <string>
#include <vector>
#include <map>

class Parser {
public:
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

    std::vector<Token> tokenize(const std::string& input);
    Node* parseTokens(const std::vector<Token>& tokens);

private:
    const std::map<std::string, int> precedence = {
        {"+", 1}, {"-", 1},
        {"*", 2}, {"/", 2}
    };
};