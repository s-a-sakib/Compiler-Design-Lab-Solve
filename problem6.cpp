/*
    Write a program to build a lexical analyzer implementing the
    following regular expressions. It takes a text as input from
    a file (e.g. input.txt) and display output in console mode:

    Character variable = ch_(a-zA-Z0-9)(a-zA-Z0-9)*
    Binary variable = bn_(a-zA-Z0-9)(a-zA-Z0-9)*
    Binary Number = 0(0|1)(0|1)*
    Invalid Input or Undefined = Otherwise
*/

#include <bits/stdc++.h>
using namespace std;

// checking (a-zA-Z0-9)(a-zA-Z0-9)* part
bool count_check(string str){
    bool valid = true;
    int count = 0;
    for(int i = 3; i < str.size(); i++){
        if((str[i] >= '0' && str[i] <= '9') or (toupper(str[i]) >= 'A' && toupper(str[i]) <= 'Z'))
            count++;
        else{
            valid = false;
        }
    }
    if(count and valid) return true;
    else return false;
}

// checking Character variable
bool is_Character_variable(string str){
    if(str.size() < 4 or str[1] != 'h' or str[2] != '_') return false;
    return count_check(str);
}

// checking Binary variable
bool is_Binary_Variable(string str){
    if(str.size() < 4 or str[1] != 'n' or str[2] != '_') return false;
    return count_check(str);
}

// checking Binary Number
bool Binary_Number(string str){
    if(str.size() < 2) return false;

    
    for(int i = 0; i < str.size(); i++){
        if(!(str[i] == '0' or str[i] == '1')){
            return false;
        }
    }

    return true;
}

int32_t main(){
    int t;
    cin >> t;
    string str;
    while(t--){
        cin >> str;
        if(str[0] == 'c'){
            if(is_Character_variable(str))
                cout << "Character variable  :  " << str << endl;
            else 
                cout << "Invalid Input or Undefined  :  " << str << endl;
        }else if(str[0] == 'b'){
            if(is_Binary_Variable(str))
                cout << "Binary variable  :  " << str << endl;
            else 
                cout << "Invalid Input or Undefined  :  " << str << endl;
        }else if(str[0] == '0'){
            if(Binary_Number(str))
                cout << "Binary Number  :  " << str << endl;
            else 
                cout << "Invalid Input or Undefined  :  " << str << endl;
        }else{
                cout << "Invalid Input or Undefined  :  " << str << endl;
        }
    }
    return 0;
}