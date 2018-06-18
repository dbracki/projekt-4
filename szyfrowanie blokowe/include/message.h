#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <iostream>
#include <vector>
#include <math.h>

#include "Block.h"


using namespace std;

class message
{
    public:

        vector <Block> cBlock;
        message(string message);
        void codeCharacter(int x, char c);
        void tpozition();
        string Show();
        int getnumber();


    private:
        int number;
        string cMessage;

};

#endif // MESSAGE_H
