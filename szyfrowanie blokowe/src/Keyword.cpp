#include "Keyword.h"

Keyword::Keyword(string kword){
        int x;
        cout<<"Add code number: ";
        cin>>x;
        word=kword;
        number=x;
}

 char Keyword::isChar(int x){
    return word[x];
 }

 int Keyword::isDigit(){
    return number;
 }

 int Keyword::length(){
    return word.length();
 }


