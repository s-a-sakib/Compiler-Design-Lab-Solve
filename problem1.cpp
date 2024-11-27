#include <bits/stdc++.h>
using namespace std;

void subtaskA(string str){
    cout << "Tasks : a)" << endl;
    cout <<"_______________________ " << endl;
    int words = 0;
    int letters = 0;
    int digits = 0;
    int otherChar = 0;

    int lineLength = str.length();
    bool CharOrDigits = false;
    for(int i = 0; i < lineLength; i++){
        if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')){
            letters += 1;
        }
        if((str[i] >= '0' && str[i] <= '9')){
            digits += 1;
        }
        if(!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) and !((str[i] >= '0' && str[i] <= '9')) and str[i] != ' '){
            otherChar += 1;
        }

        if((str[i] >= 'A' and str[i] <= 'Z') or (str[i] >= 'a' && str[i] <= 'z') or (str[i] >= '0' && str[i] <= '9')){
            CharOrDigits = true;
            if(i == lineLength - 1){
                words += 1;
            }
        }else{
            if(CharOrDigits){
                if(str[i] == ' ' or str[i] == '!' or str[i] == ',' or str[i] == '!' or str[i] == '?' or str[i] == '.'){
                    CharOrDigits = false;
                    words += 1;
                }
            }
        }
    }
    cout << "Letters: " << letters << endl;
    cout << "Digits: " << digits << endl;
    cout << "Other characters: " << otherChar << endl;
    cout << "Words: " << words << endl;
    cout << endl;
    cout << endl;
}


void subtaskB(string str){
    cout << "Tasks : b)" << endl;
    cout <<"_______________________ " << endl;
    set < char > letters;
    set < char > digits;
    set < char > otherChar;

    for(int i = 0; i < str.length(); i++){
        if(str[i] >= '0' && str[i] <= '9') digits.insert(str[i]);
        else if((str[i] >= 'a' && str[i] <= 'z') or (str[i] >= 'A' && str[i] <= 'Z')){
            letters.insert(str[i]);
        }else{
            if(str[i] != ' ') otherChar.insert(str[i]);
        }
    }

    cout << "Separated letters: " << letters.size() << endl;
    cout << "Separated digits: " << digits.size() << endl;
    cout << "Separated characters: " << otherChar.size() << endl;
}

int32_t main()
{
    string str;
    getline(std::cin, str);
    cout << str << endl;
    cout << endl;
    subtaskA(str);
    subtaskB(str);

    return 0;
}
