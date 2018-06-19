#include "Keyword.h"

Keyword::Keyword(string kword, int x){

    word=kword;
    number=x;
    for (int i=0; i<8; i++){

        int d=128;
        int a=word[i];
        for (int j=0; j<8; j++){

            bytes[j+8*i]=(a/d)%2;
            d=d/2;

        }

    }

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

 int Keyword::getbyte(int x){

    return bytes[x];

 }

int Keyword::getnumber(){

    return number;

}

