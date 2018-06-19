#ifndef CMACHINE_H
#define CMACHINE_H

#include <fstream>

#include "message.h"
#include "Keyword.h"


using namespace std;
class Cmachine
{
    public:

        Cmachine();
        vector <Keyword> cKeyword;
        void Cipher(int d1, int d3, int x);
        void code(int d1, int d2, int d3);
        void save(string msg);
        void codeblock(int s[], int key[]);
        void keymove(int key[]);
        void keypermute(int key[], int pkey[]);
        void XOR48(int E[], int pkey[]);
        void XOR32(int h1[], int h2[]);
        void blockpermute(int s[], int E[], int h[]);
        void swaphalfs(int L[], int R[]);
        string codemessage(message mess, int d2);

    private:

};

#endif // CMACHINE_H
