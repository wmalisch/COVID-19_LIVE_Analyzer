#include <string>
#include <iostream>

using namespace std;

#ifndef COUNTRY_H
#define COUNTRY_H

class Country
{
    public:
        Country();

        Country(string, string, int , int , int, int, int, int);

        void setName(string name);
        // void setCode(string str);
        // void setNCC(int ncc);
        // void setND(int nd);
        // void setNRC(int nrc);
        // void setTCC(int tcc);
        // void setTD(int td);
        // void setTRC(int trc);
        string getName();
        // string getCode();
        // int getNCC();
        // int getND();
        // int getNRC();
        // int getTCC();
        // int getTD();
        // int getTRC();
    protected:
    private:
        string name;
        string code;
        int ncc;
        int nd;
        int nrc;
        int tcc;
        int td;
        int trc;
};

#endif