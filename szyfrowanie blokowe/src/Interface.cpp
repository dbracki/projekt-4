#include "Interface.h"


Interface::Interface(){
};


bool Interface::run(){
    int d1,d2,d3;
    cout<<"Program your coding algorithm"<<endl;
    cout<<"Keyword"<<endl;
    cout<<"1. Always the same"<<endl;
    cout<<"2. Different for every block"<<endl;
    cin>>d1;
    cout<<"Use previous block to program next?"<<endl;
    cout<<"1. Yes"<<endl;
    cout<<"2. No"<<endl;
    cin>>d2;
    cout<<"Add bonus amount?"<<endl;
    cout<<"1. Yes"<<endl;
    cout<<"2. No"<<endl;
    cin>>d3;
    Cmachine cm;
    cm.code(d1, d2, d3);
    return false;

}
