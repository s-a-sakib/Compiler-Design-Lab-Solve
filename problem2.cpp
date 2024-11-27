/*
    2. Write a program that read the following string:
        "Munmun is the student of Computer Science & Engineering"
       a) Count how many vowels and Consonants are there?
       b) Find out which vowels and Consonants are existed in the above string?
       c) Divide the given string into two separate strings, where one string only contains
            the words started with vowel, and another contains the words the words started
            with consonant. 
*/ 

#include <bits/stdc++.h>
using namespace std;

void subProblemOne(string str){
    int vowel = 0, consonant = 0;
    for(auto it : str){
        char c = toupper(it);
        if(c >= 'A' && c <= 'Z'){
            if(c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U'){
                vowel += 1;
            }else{
                consonant += 1;
            }
        }
    }
    cout << "Number of vowel: " << vowel << endl;
    cout << "Number of consonant: " << consonant << endl;
}

void subProblemTwo(string str){
    set < char > vowel;
    set < char > consonant;

    for(auto it : str){
        char c = toupper(it);
        if(c >= 'A' && c <= 'Z'){
            if(c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U'){
                vowel.insert(c);
            }else{
                consonant.insert(c);
            }
        }
    }
    cout << "Vowel : "; for(auto it : vowel) cout << it <<", "; cout << endl;
    cout << "Consonant : "; for(auto it : consonant) cout << it <<", "; cout << endl;
}

void subProblemThree(string str){
    vector < string > vowel , consonant;

    string s = "";
    bool newString = true , goTo;
    for(int i = 0; i < str.size(); i++){
        char c = toupper(str[i]);
        if(i == 0 or str[i - 1] == ' ' and (c >= 'A' and c <= 'Z')){
            newString = false;
            if(c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U'){
                goTo = true;
            }else goTo = false;
        }else if(str [i] == ' ' || i == str.size() - 1){
            newString = true;
        }

        if(!newString) s.push_back(str[i]);

        else{
            s.push_back(' ');
            if(goTo) vowel.push_back(s);
            else consonant.push_back(s);
            s = "";
        }
    }

    cout << "The words started with vowel : ";
    for(auto it : vowel) cout << it;
    cout << endl;

    cout << "The words started with consonant: ";
    for(auto it : consonant) cout << it;
    cout << endl;
}

int main(){

    // Taking input from the user
    string str;
    getline(cin, str);

    // Solution of problem a)
    subProblemOne(str);
    cout << "________________________________________________________" <<endl;

    // Solution of problem b)
    subProblemTwo(str);
    cout << "________________________________________________________" <<endl;

    // Solution of problem c)
    subProblemThree(str);

    return 0;
}