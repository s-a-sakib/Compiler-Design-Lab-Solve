#include <bits/stdc++.h>
using namespace std;

struct rule {
    string left;
    string right;
};

void shiftReducingParser(vector<rule> rules, string inputStream) {
    // Append `$` to the input stream
    inputStream.push_back('$');

    stack<char> s; // Stack to manage the symbols
    s.push('$');

    // Finding the start symbol
    string startSymbol = rules[0].left;
    char startS = startSymbol[0];

    // Variables for stack string, shift, and reduce tokens
    string stk = "$", sft = "Shift", ruds = "Reduced by ";
    cout << "-----Stack----------Input----------Output-----" << endl;

    int index = 0; // Input stream index
    while (index < inputStream.size()) {
        string subStr = inputStream.substr(index);
        cout << stk << string(21 - stk.size() - subStr.size(), ' ') << subStr << "      ";

        if (stk.size() == 2 && stk[1] == startS && subStr == "$") { // Stack contains only start symbol
            cout << "Accept" << endl;
            break;
        } else {
            bool notAGrammar = true;
            string check = "";

            // Reduction: Check stack contents for matching grammar rules
            stack<char> tempStack = s; // Create a temporary copy of the stack
            while (notAGrammar && tempStack.top() != '$') {
                check = tempStack.top() + check; // Extend check string from top of the stack
                tempStack.pop();

                for (const auto& rule : rules) {
                    if (check == rule.right) {
                        // Reduction happens
                        notAGrammar = false;

                        // Synchronize the actual stack with the reduction
                        for (size_t i = 0; i < rule.right.size(); ++i) {
                            s.pop(); // Remove RHS from stack
                        }
                        s.push(rule.left[0]); // Push LHS onto stack
                        stk = stk.substr(0, stk.size() - rule.right.size()) + rule.left;
                        cout << ruds << rule.left << " -> " << rule.right << endl;
                        break;
                    }
                }
            }

            if (notAGrammar) {
                // If no reduction was possible, perform a shift operation
                char shiftChar = inputStream[index++];
                s.push(shiftChar); // Push the next input symbol onto the stack
                stk += shiftChar; // Update stack string
                cout << sft << endl;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<rule> rules(n);

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        int pos = str.find("-");
        string lt = str.substr(0, 1);
        string rt = str.substr(pos + 2);
        rules[i].left = lt;
        rules[i].right = rt;
    }

    string inputStream;
    cin >> inputStream;

    shiftReducingParser(rules, inputStream);
    return 0;
}
