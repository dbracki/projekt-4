#include "Cmachine.h"
#include "message.h"

Cmachine::Cmachine(){

};

void Cmachine::code(int d1, int d2, int d3){

    cout<<"Add a message(no spaces)"<<endl;
    string mess;
    cin>>mess;
    message msg(mess);//dodaje wiadomoœæ
    int x=mess.length();
    Cipher(d1, d3, x);//dodaje kluzc do kodowania
    msg.tpozition();//permutacja macierzy bloków
    codemessage(msg, d2);
    msg.tpozition2();//odwrotna permuatcja macierzy bloków
    cout<<"Your message after coding"<<msg.decode()<<endl;
    cout<<"Safe coded message to file?\n1. Yes\n2. No"<<endl;
    int decision;
    cin>>decision;
    if(decision==1) save(msg.Show());

}

void Cmachine::save(string msg){

    fstream File;
    string filename;
    cout<<"Name of file: "<<endl;
    cin>>filename;
    File.open(filename.c_str(), ios::out);
    File<<msg;

}

string Cmachine::codemessage(message mess, int d2){//kodowanie wiadomoœci
    int x=(mess.givelength())/8+1;
    for (int i=0; i<x; i++){//koodwanie pojedynczego bloku (ze wszystkimi przekszta³ceniami)

        int L[32], P[32];
        for(int j=0; j<64; j++){//podzia³ bitów bloku na 2 po³owy

            if(j<32) L[j]=mess.cBlock[x].bytes[j];
            else P[j]=mess.cBlock[x].bytes[j];

        }
        int key[56];
        int a=56;
        int b=57;
        int c;
        for (int k=0; k<56; k++){//generowanie pierwszego podklucza 64->55
            if(a<=0) a+=b;
            if(a==36) {

                a=62;
                b=62;

            }
            if(a==-4) a=28;
            c=cKeyword[i].getbyte(a);
            key[k]=c;
            a-=8;

        }
        for (int j=0; j<16; j++){//kodowanie bloku

                codeblock(L, key);//kodowanie lewej po³ówki bloku
                XOR32(L, P);
                swaphalfs(L, P);//zamienia po³ówek

            }

            for(int j=0; j<64; j++){//³¹czenie po³ów w zakodowany blok

            if(j<32) mess.cBlock[i].bytes[j]=L[j];
            else mess.cBlock[i].bytes[j]=P[j];

            }
            if(d2==1 && i!=0){

                for(int j=0; j<64; j++){

                    if((mess.cBlock[i].bytes[j]+mess.cBlock[i-1].bytes[j]%2)==0) mess.cBlock[i].bytes[j]=0;
                    else mess.cBlock[i].bytes[j]=1;
                }

            }

        }
    return mess.Show();

}

void Cmachine::codeblock(int h[], int key[]){//kodowanie jednej z po³ówek bloku

    int E[48];
    int a=4;
    int b=0;
    for (int i=0; i<48; i++){//przekszta³cenie przez macierz E

        if(i==0) E[i]=h[31];
        else if(i==47) E[i]=h[0];
        else{

            if(i%6==0) {

                E[i]=h[a];
                a+=4;

            }
            else if(i%6==5) {

                E[i]=h[a+5];

            }
            else{

                E[i]=h[b];
                b++;

            }

        }

    }
    keymove(key);// generowanie podklucza Ki i={1,2,3,...,16}
    int pkey[48];//dodajemy aby nie straciæ klucza
    keypermute(key, pkey);//permutacja podklucza Ki 56->48
    XOR48(E, pkey);//kodowanie po³owy bloku z podkluczem
    int s[64];//dodaejmy i uzupe³niamy dodatkow¹ macierz, która zamienia ma³e czêœci bloku E[48] na blok h[32]
    for(int i=0; i<4; i++){
        for (int j=0; j<16; j++){
            s[4*i+j]=(i+5*j/2)%16;
        }
    }
    blockpermute(s, E, h);//zamiana E[48] na wyjœciowy blok h[32]

}

void Cmachine::keymove(int key[]){//generowanie podklucza

    int pkey[56];
    pkey[27]==key[0];
    pkey[55]==key[28];
    for (int i=0; i<56; i++){
        if (i!=27 && i!=56) pkey[i]=key[i-1];
    }
    for(int i=0; i<56; i++){
        key[i]=pkey[i];
    }
}

void Cmachine::keypermute(int key[], int pkey[]){//permutowanie podklucza 56->48

    int a=0;
    for (int i=0; i<48; i++){
        pkey[i]=key[i+a];
        if (i%7==6) a++;
    }
}

void Cmachine::XOR48(int E[], int pkey[]){//kodowanie po³owy bloku z podkluczem

    for(int i=0; i<48; i++){
        if((E[i]+pkey[i])%2==1) E[i]=1;
        else E[i]=0;
    }
}

void Cmachine::blockpermute(int s[], int E[], int h[]){//zamiana E[48] na wyjœciowy blok h[32]

    int a,b;
    for(int i=0; i<8; i++){


        b=(E[6*i]*2+E[6*i+5])*16+(E[6*i+1]*8+E[6*i+2]*4+E[6*i+3]*2+E[6*i+4]);
        a=s[b];
        int d=8;
        for(int j=0; j<4; j++){

            h[8*i+j]=(a/d)%2;
            d=d/2;

        }

    }

}

void XOR32(int h1[], int h2[]){//kodowanie po³owy bloku na podstawie drugiej

    for(int i=0; i<48; i++){

        if((h1[i]+h2[i])%2==1) h1[i]=1;
        else h1[i]=0;

    }

}

void Cmachine::swaphalfs(int L[], int P[]){//zamienia miejscami po³owy bloku

    int bufor[32];
    for(int i=0; i<32; i++){

        bufor[i]=P[i];
        P[i]=L[i];
        L[i]=bufor[i];

    }

}

void Cmachine::XOR32(int L[], int P[]){//kodowanie po³owy bloku z podkluczem

    for(int i=0; i<32; i++){

        if((L[i]+P[i])%2==1) L[i]=1;
        else P[i]=0;

    }

}

void Cmachine::Cipher(int d1, int d3, int x){//dodawanie s³ów kluczy i przesuniêcia

    string kword;
    int y=0;
    if(d1==2){

        for (int i=0; i<x/8+1; i++){

            cout<<"Add Key "<<x<<" (8 characters): ";
            cin>>kword;
            if(d3==1){

                cout<<"Rotate by number: ";
                cin>>y;

            }
            Keyword k(kword,y);
            for (int i=0; i<64; i++){
                cout<<k.getbyte(x);
            }

            cKeyword.push_back(k);

        }

    }
    else{

        cout<<"Add a Key (8 characters): ";
        cin>>kword;
        if(d3==1){

            cout<<"Rotate by number: ";
            cin>>y;

        }
        for (int i=0; i<x/8+1; i++){

            Keyword k(kword, y);
            cKeyword.push_back(k);

        }

    }

}
