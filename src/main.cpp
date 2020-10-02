#include <iostream>
#include <string>
#include "../headers/Country.h"

using namespace std;

int main(){
    Country c1;
    Country c2("Chile", "CH", 5,6,7,8,9,0);
    
    cout << c1.getName() << endl;
    c1.setName("USA");
    cout << c1.getName() << endl;
    cout << c1.getCode() << endl;
    c1.setCode("US");
    cout << c1.getCode() << endl;
    cout << c1.getNCC() <<endl <<c1.getND()<<endl<<c1.getNRC()<<endl<<c1.getTCC()<<endl<<c1.getTD()<<endl<<c1.getTRC()<<endl;
    c1.setNCC(41);
    c1.setND(42);
    c1.setNRC(43);
    c1.setTCC(44);
    c1.setTD(45);
    c1.setTRC(46);
    cout << c1.getNCC() <<endl <<c1.getND()<<endl<<c1.getNRC()<<endl<<c1.getTCC()<<endl<<c1.getTD()<<endl<<c1.getTRC()<<endl;

    cout << c2.getName() <<endl;
    cout << c2.getCode() << endl;
    cout << c2.getNCC() <<endl <<
        c2.getND()<<endl<<c2.getNRC()<<endl<<
        c2.getTCC()<<endl<<c2.getTD()<<endl<<c2.getTRC()<<endl;
    c2.setNCC(41);
    c2.setND(42);
    c2.setNRC(43);
    c2.setTCC(44);
    c2.setTD(45);
    c2.setTRC(46);
    cout << c2.getNCC() <<endl <<
        c2.getND()<<endl<<c2.getNRC()<<endl<<
        c2.getTCC()<<endl<<c2.getTD()<<endl<<c2.getTRC()<<endl;
    return 0;
}