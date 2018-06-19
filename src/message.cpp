#include "message.h"

message::message(string mess){//dodaje wiadomoœæ i dzieli j¹ na bloki
    cMessage=mess;
    int a=mess.length();
    number=a/8+1;
    for(int x=0; x<(a/8)+1; x++){

        Block b;
        cout<<"blok "<<x<<" :"<<endl;
        for (int i=0; i<8; i++){

            b.info[i]=mess[x*8+i];
            int d=128;
            int c=mess[x*8+i];
            for(int y=0; y<8; y++){

                b.bytes[y+i*8]=(c/d)%2;
                d=d/2;
            }

        }

        cout<<b.info<<endl;
        cBlock.push_back(b);

    }

};

string message::Show(){//zwraca wiadomosc

    return cMessage;

}

int message::givelength(){//podaej dlugosc

    return cMessage.length();

}

void message::tpozition(){//przeksztalca macierz wedlug schematy

    int bytes2[64];
    for (int x=0; x<getnumber(); x++){

        int y=57;
        for(int j=0; j<32; j++){

            bytes2[j]=cBlock[x].bytes[y];
            y=y-8;
            if(y<0) y+=66;

        }
        y=56;
        for(int j=32; j<64; j++){

            bytes2[j]=cBlock[x].bytes[y];
            y=y-8;
            if(y<0) y+=66;

        }

        for (int i=0; i<64; i++){

            cBlock[x].bytes[i]=bytes2[i];

        }

    }

}

void message::tpozition2(){//przeksztalca przez macierz odwrotna do pierwszej

    int bytes2[64];
    for (int x=0; x<getnumber(); x++){

        int k=39;
        for(int j=0; j<2; j++){

            for(int z=0; z<32; z++){

                bytes2[j+z*2]=cBlock[x].bytes[k];
                if(k>63) k-=25;
                else k+=8;
                if(k==64) k=7;

            }

        }
        for (int i=0; i<64; i++){

            cBlock[x].bytes[i]=bytes2[i];

        }

    }

}

int message::getnumber(){
    return number;
}

string message::decode(){

    int a=cMessage.length();
    for(int i=0; i<a/8+1; i++){

        for(int j=0; j<8; j++){

            cBlock[i].info[j]=cBlock[i].bytes[8*j]*128+cBlock[i].bytes[8*j+1]*64+cBlock[i].bytes[8*j+2]*32+cBlock[i].bytes[8*j+3]*16+cBlock[i].bytes[8*j+4]*8+cBlock[i].bytes[8*j+5]*4+cBlock[i].bytes[8*j+6]*2+cBlock[i].bytes[8*j+7];
            cMessage[i*8+j]=cBlock[i].info[j];

        }

    }
    return cMessage;
}
