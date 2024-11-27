/*
Write a program to build a lexical analyzer implementing the following regular expressions.
It takes a text as input from a file (e.g., input.txt) and display output in console mode:
__________________________________________________________________________________________
Float variable = (a-hA-HO-Z)(a-zA-Z0-9)*
Float Number   = 0.(0-9)(0-9) | (1-9)(0-9)*.(0-9)(0-9)
Double Number = 0.(0-9)(0-9)+ |(1-9)(0-9)*.(0-9)(0-9)+
Invalid Input or Undefined = Otherwise
*/

/*
a123
0.45
23.56
0.567
99.99
abc
z3
0.34
12.345
007
0..45
abc.def

Token: a123, Type: Float Variable
Token: 0.45, Type: Float Number
Token: 23.56, Type: Float Number
Token: 0.567, Type: Double Number
Token: 99.99, Type: Float Number
Token: abc, Type: Float Variable
Token: z3, Type: Float Variable
Token: 0.34, Type: Float Number
Token: 12.345, Type: Double Number
Token: 007, Type: Invalid Input or Undefined
Token: 0..45, Type: Invalid Input or Undefined
Token: abc.def, Type: Invalid Input or Undefined
*/

#include <bits/stdc++.h>
using namespace std;

bool is_variable(string str){
    if(str.size() == 0) return false;

    if(!((tolower(str[0]) >= 'a' && tolower(str[0]) <= 'h') or (str[0] >= 'O' && str[0] <= 'Z')))
        return false;
    
    for(int i = 1; i < str.size(); i++){
        if(isdigit(str[i]) or isalpha(str[i])) continue;
        else return false;
    }

    return true;
}

int floatOrDouble(string str){
    if(!isdigit(str[0])) return 0;
    
    int preDot = 0, postDot = 0;
    bool getDot = false;
    for(int i = 0; i < str.size(); i++){
        if(isdigit(str[i])){
            if(!getDot) preDot++;
            else postDot++;
        }else if(str[i] == '.' and !getDot){
            getDot = true;
        }else{
            return 0;
        }
    }
    if(preDot >= 2 and str[0] == '0') return 0;

    if(preDot >= 1 and postDot == 2) return 1;
    else if(preDot >= 1 and postDot > 2) return 2;
    else return 0;
}

void solve(string str){
    if(is_variable(str)){
        cout << "Token: " << str << " Type: Float Variable" << endl;
    }else{
        int type = floatOrDouble(str);
        if(type == 0){
            cout << "Token: " << str << " Type: Invalid Input or Undefined" << endl;
        }else if(type == 1){
            cout << "Token: " << str << " Type: Float Number" << endl;
        }else{
            cout << "Token: " << str << " Type: Double Number" << endl;
        }
    }
}

int main(){
    string str;
    while(cin >> str){
        solve(str);
    }
    return 0;
}

