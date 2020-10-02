#include <string>
#include <iostream>

using namespace std;

#ifndef COUNTRY_H
#define COUNTRY_H

class Country
{
    public:
        // Basic contructor
        Country();

        // Detailed constructor
        Country(string, string, int , int , int, int, int, int);

        // Destructor
        ~Country();

        // Mutator functions
        void setName(string name);
        void setCode(string str);
        void setNCC(int ncc);
        void setND(int nd);
        void setNRC(int nrc);
        void setTCC(int tcc);
        void setTD(int td);
        void setTRC(int trc);

        // Accessor functions
        string getName() const;
        string getCode() const;
        int getNCC() const;
        int getND() const;
        int getNRC() const;
        int getTCC() const;
        int getTD() const;
        int getTRC() const;
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