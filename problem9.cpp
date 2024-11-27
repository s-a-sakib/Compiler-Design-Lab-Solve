/*
    Write a program that will check an English sentence given
    in persent indefinite from to jusitfy whether it is syntactically
    valid or invalid according to the following Chomsky Normal Form:
        S -> SUB PRED
        SUB -> PN | P
        PRED -> V | V N
        PN -> Sagor | Selim | Salma | Nipu
        P -> he | she | I | we | you | they
        N -> book | cow | dog | home | grass | rice | mango
        V -> read | eat | take | run | write 
*/

#include <bits/stdc++.h>
using namespace std;

string PN[] = {"Sagor", "Selim", "Salma", "Nipu"};
string P[]  = {"he" , "she" , "I" , "we" , "you" , "they"};
string N[]  = {"book" ,"cow" ,"dog","home" ,"grass" ,"rice" ,"mango"};
string V[]  = {"read" , "eat" , "take" , "run" , "write"};

bool existsInArray(string arr[], int size, string target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return true;
        }
    }
    return false;
}

bool check_grammar(vector<string> tokens) {
    bool w1 = false, w2 = false, w3 = false;

    if (existsInArray(PN, sizeof(PN) / sizeof(PN[0]), tokens[0]) || 
        existsInArray(P, sizeof(P) / sizeof(P[0]), tokens[0])) {
        w1 = true;
    }

    if (existsInArray(V, sizeof(V) / sizeof(V[0]), tokens[1])) {
        w2 = true;
    }

    if (tokens.size() == 3 && existsInArray(N, sizeof(N) / sizeof(N[0]), tokens[2])) {
        w3 = true;
    }

    if(tokens.size() == 2 && w1 && w2) return true;
    else if(tokens.size() == 3 && w1 && w2 && w3) return true;
    else return false;
}

vector<string> create_token(string sentence) {
    vector <string> tokens;
    int len = sentence.length();
    sentence += " X";
    string word = "";
    for(int i = 0; i <= len; i++) {
        if(sentence[i] != ' '){
            word.push_back(sentence[i]);
        }else{
            tokens.push_back(word);
            word = "";
        }
    }
    return tokens;
}

int main(){
    int t;
    cin >> t;
    cin.ignore();
    string sentence;
    while (t--) {
        cout << "Enter a sentence: ";
        getline(cin, sentence);
        cout << "You entered: " << sentence << endl;
        vector <string> tokens = create_token(sentence);
        bool valid = check_grammar(tokens);
        if(valid) cout << sentence << " ->is Valid Chomsky Normal Form sentence" << endl;
        else cout << sentence << " -> is NOT Valid Chomsky Normal Form sentence" << endl;
    }
    return 0;
}
