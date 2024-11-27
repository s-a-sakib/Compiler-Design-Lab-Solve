/*
Write a program to build a lexical analyzer implementing the following regular expressions.
It takes a text as input from a file (e.g., input.txt) and display output in console mode:
__________________________________________________________________________________________
Integer variable = (i-nI-N)(a-zA-Z0-9)*
ShortInt Number = (1 - 9)|(1 - 9) (0 - 9)| (1 - 9) (0 - 9) (0 - 9) | (1 - 9) (0 - 9) (0 - 9) (0 - 9) 
LongInt Number = (1 - 9) (0 - 9) (0 - 9) (0 - 9) (0 - 9) + 
Invalid Input or Undefined = Otherwise
*/

#include <bits/stdc++.h>
using namespace std;

void solve(string str){
    if(str[0] >= '1' && str[0] <= '9'){
        int c = 0;
        for(int i = 1; i < str.length(); i++){
            if(str[i] >= '0' && str[i] <= '9'){
                c = i;
            }else{
                cout << "Invalid Input or Undefined : " << str << endl;
                return;
            }
        }
        if(c <= 3){
            cout << "ShortInt Number : " << str << endl;
        }else{
            cout << "LongInt Number : " << str << endl;
        }
    }else if(toupper(str[0]) >= 'I' && toupper(str[0]) <= 'N'){
        
        for(int i = 1; i < str.length(); i++){
            if((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){
                continue;
            }else{
                cout << "Invalid Input or Undefined : " << str << endl;
                return;
            }
        }
        cout << "Integer variable : " << str << endl;
    }else{
        cout << "Invalid Input or Undefined : " << str << endl;
    }
}

int main(){
    string str;
    while(cin >> str){
        solve(str);
    }
    return 0;
}