#include "Cmachine.h"
#include "message.h"
#include "Cipher.h"

Cmachine::Cmachine(){
};

void Cmachine::code(int d1, int d2, int d3){
    cout<<"Add a message"<<endl;
    string mess;
    cin>>mess;
    message msg(mess);
    int x=mess.length();
    Cipher code(d1, x);
    msg.tpozition();
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
