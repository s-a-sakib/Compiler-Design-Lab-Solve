/*
    Write a program in C++  to recognize C++
        1. Keyword
        2. Identifier
        3. Operator
        4. Constant 
*/ 

#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// List of C++ keywords
unordered_set<string> keywords = {
    "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", 
    "enum", "extern", "float", "for", "goto", "if", "inline", "int", "long", "register", 
    "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", 
    "unsigned", "void", "volatile", "while", "class", "public", "private", "protected", 
    "virtual", "friend", "this", "namespace", "using", "new", "delete", "try", "catch", 
    "throw", "template", "typename", "typeid", "true", "false"
};

// List of C++ operators
unordered_set<string> operators = {
    "+", "-", "*", "/", "=", "==", "!=", "<", ">", "<=", ">=", "&&", "||", "!", "++", "--",
    "&", "|", "^", "~", "<<", ">>", "%", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=",
    "<<=", ">>=", "->", ".", "->*", ".*", "::", "?", ":"
};

// Function to check if the string is a keyword
bool isKeyword(const string& token) {
    return keywords.find(token) != keywords.end();
}

// Function to check if the string is an operator
bool isOperator(const string& token) {
    return operators.find(token) != operators.end();
}

// Function to check if the string is an identifier
bool isIdentifier(const string& token) {
    if (isKeyword(token) || isdigit(token[0])) {
        return false;
    }
    // Identifiers must start with an alphabet or underscore
    if (isalpha(token[0]) || token[0] == '_') {
        for (size_t i = 1; i < token.size(); ++i) {
            if (!isalnum(token[i]) && token[i] != '_') {
                return false;
            }
        }
        return true;
    }
    return false;
}

// Function to check if the string is a constant (integer or floating-point)
bool isConstant(const string& token) {
    bool hasDecimal = false;
    for (size_t i = 0; i < token.size(); ++i) {
        if (token[i] == '.') {
            if (hasDecimal) return false; // More than one decimal point
            hasDecimal = true;
        } else if (!isdigit(token[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    string input;
    cout << "Enter a token: ";
    cin >> input;
    
    if (isKeyword(input)) {
        cout << "'" << input << "' is a Keyword.\n";
    } else if (isOperator(input)) {
        cout << "'" << input << "' is an Operator.\n";
    } else if (isConstant(input)) {
        cout << "'" << input << "' is a Constant.\n";
    } else if (isIdentifier(input)) {
        cout << "'" << input << "' is an Identifier.\n";
    } else {
        cout << "'" << input << "' is not recognized.\n";
    }
    
    return 0;
}
