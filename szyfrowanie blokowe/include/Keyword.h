#ifndef KEYWORD_H
#define KEYWORD_H

#include <string>
#include <iostream>


using namespace std;
class Keyword
{
    public:
        Keyword(string kword);
        char isChar(int x);
        int isDigit();
        int length();

    private:
        int number;
        string word;
};

#endif // KEYWORD_H
