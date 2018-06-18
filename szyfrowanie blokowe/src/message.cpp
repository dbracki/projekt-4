#include "message.h"

message::message(string message){
    int a=message.length();
    number=a/8+1;
    for(int x=0; x<(a/8)+1; x++){
        Block b;
        cout<<"blok "<<x<<" :"<<endl;
        for (int i=0; i<8; i++){
            b.info[i]=message[x*8+i];
            int d=128;
            int c=message[x*8+i];
            for(int y=0; y<8; y++){
                b.bytes[y+x*8]=(c/d)%2;
                d=d/2;
            }
        }
        cout<<b.info<<endl;
        cBlock.push_back(b);
    }
};


void message::codeCharacter(int x, char c){
cMessage[x]=c;
}

string message::Show(){
return cMessage;
}

void message::tpozition(){

int bytes2[64];
for (int x=0; x<getnumber(); x++){
    for(int j=0; j<64; j++){
        int y=52;
        bytes2[j]=Block[x].bytes[y];
        y=y-8;
        if(y<0) y+=64;
        if(y==0) y=57;
    }
    Block[x].bytes=bytes2;
}
}

int message::getnumber(){
return number;
}
