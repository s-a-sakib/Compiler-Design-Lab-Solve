/*
Write a program which converts a word of C++ program to 
its equivalent token.
RESULTS:
    Input: 646.45
    Output: Float
    Input: do
    Output: Keyword
    Input: 554
    Output: Integer
    Input: abc
    Output: Identifier
    Input: +
    Output: Arithmetic Operator
*/

#include <iostream>
#include <string>
#include <cctype>
#include <unordered_set>

using namespace std;

// Function to check if the string is a keyword
bool isKeyword(const string& word) {
    unordered_set<string> keywords = {
        "int", "float", "double", "char", "if", "else", "while", "for", "do", "return", "break", "continue", "switch", "case", "default"
        // Add more keywords as needed
    };
    return keywords.find(word) != keywords.end();
}

// Function to check if the string is a float
bool isFloat(const string& word) {
    bool hasDecimal = false;
    for (char c : word) {
        if (!isdigit(c)) {
            if (c == '.' && !hasDecimal) {
                hasDecimal = true;
            } else {
                return false;
            }
        }
    }
    return hasDecimal; // Must have at least one decimal point
}

// Function to check if the string is an integer
bool isInteger(const string& word) {
    for (char c : word) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

// Function to check if the string is an arithmetic operator
bool isArithmeticOperator(const string& word) {
    string operators = "+-*/%";
    if(word.size() > 1) return false;
    for(char c : operators){
        if(c == word[0]){
            return true;
        }
    }
    return false;
}

// Function to determine the type of the input
string getTokenType(const string& word) {
    if (isKeyword(word)) {
        return "Keyword";
    } else if (isFloat(word)) {
        return "Float";
    } else if (isInteger(word)) {
        return "Integer";
    } else if (isArithmeticOperator(word)) {
        return "Arithmetic Operator";
    } else {
        return "Identifier"; // Anything else is treated as an identifier
    }
}

int main() {
    int t;
    cin >> t;
    while(t--){
        string input;  
        // Taking input from user
        cout << "Enter a word: ";
        cin >> input;
        // Getting the token type and printing the result
        string tokenType = getTokenType(input);
        cout << input << "  Output: " << tokenType << endl;
    } 
    return 0;
}
