#ifndef CIPHER_H
#define CIPHER_H

#include <vector>

#include "Keyword.h"

using namespace std;

class Cipher
{
    public:
        vector <Keyword> cKeyword;
        Cipher(int d1, int x);

    private:
};

#endif // CIPHER_H
