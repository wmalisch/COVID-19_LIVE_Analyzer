#include "../headers/Country.h"
#include <iostream>

using namespace std;

Country::Country()
{
    name = "Canada";
    code = "CN";
    ncc = 1;
    nd =2;
    nrc=3;
    tcc=4;
    td=5;
    trc=6;
}

Country::Country(string n, string c, int nc, int nde, int nr, int tc, int tde, int tr)
{
    name = n;
    code = c;
    ncc = nc;
    nd = nde;
    nrc = nr;
    tcc = tc;
    td = tde;
    trc = tr;

}

string Country::getName(){
    cout << name << endl;
    return name;
}

void Country::setName(string newName){
    name = newName;
}