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
        string Show();
        int givelength();
        int getnumber();
        void tpozition();
        void tpozition2();
        string decode();

    private:

        int number;
        string cMessage;

};

#endif // MESSAGE_H
