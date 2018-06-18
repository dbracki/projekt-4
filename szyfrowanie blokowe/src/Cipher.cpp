#include "Cipher.h"


Cipher::Cipher(int d1, int x){
    string kword;
    if(x==2){
        for (int i=0; i<x/8; i++){
            cout<<"Add Keyword "<<x<<": ";
            cin>>kword;
            Keyword k(kword);
        }
    }
    else{
        cout<<"Add a Keyword: ";
        cin>>kword;
        for (int i=0; i<x/8; i++){
        Keyword k(kword);
        cKeyword.push_back(k);
        }
    }
}



