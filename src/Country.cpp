#include "../headers/Country.h"
#include <iostream>

using namespace std;

Country::Country(){
    name="";
    code="";
    ncc = 0;
    nd =0;
    nrc=0;
    tcc=0;
    td=0;
    trc=0;
}

Country::Country(string n, string c, int nc, int nde, int nr, int tc, int tde, int tr){
    name = n;
    code = c;
    ncc = nc;
    nd = nde;
    nrc = nr;
    tcc = tc;
    td = tde;
    trc = tr;
}

Country::~Country(){} 
 
string Country::getName() const{
    return name; 
}

string Country::getCode() const{
    return code; 
}

int Country::getNCC() const{
    return ncc;
}

int Country::getND() const{
    return nd;
}

int Country::getNRC() const{
    return nrc;
}

int Country::getTCC() const{
    return tcc;
}

int Country::getTD() const{
    return td;
}

int Country::getTRC() const{
    return trc;
}

void Country::setName(string newName){
    name = newName;
}

void Country::setCode(string newCode){
    code = newCode;
}

void Country::setNCC(int x){
    ncc = x;
}

void Country::setND(int x){
    nd = x;
}

void Country::setNRC(int x){
    nrc = x;
}

void Country::setTCC(int x){
    tcc = x;
}

void Country::setTD(int x){
    td = x;
}

void Country::setTRC(int x){
    trc = x;
}