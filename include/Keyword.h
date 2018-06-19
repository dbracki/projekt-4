#ifndef KEYWORD_H
#define KEYWORD_H

#include <string>
#include <iostream>


using namespace std;
class Keyword
{
    public:

        Keyword(string kword, int x);
        char isChar(int x);
        int getnumber();
        int isDigit();
        int length();
        int getbyte(int x);

    private:
        int bytes[64];
        int number;
        string word;
};

#endif // KEYWORD_H
