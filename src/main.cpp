#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "../headers/Country.h"

using namespace std;

void readCountries(vector<Country>&);

void writeCountries(const vector<Country>&);

int main(){
    int stat = 0;
    
    cout << "WELCOME TO THE COVID ANALYZER" << endl 
        << endl 
        << "You have started using the covid assessment tool. If you have not seen an error, then the covid stats have been taken.\n" << endl;
        
        while(stat <= 0 || stat > 6){
            cout << "\nPlease see the output options below. Enter the corresponding number in square brackets to see the statistic you want." << endl
            << "[1] New Confirmed Cases" << endl
            << "[2] New Deaths" << endl
            << "[3] New Recovered Cases" << endl
            << "[4] Total Confirmed Cases" << endl
            << "[5] Total Deaths" << endl
            << "[6] Total Recovered Cases" << endl
            << "Enter number here: ";
            while(!(cin>>stat)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "That didn't work. Please try a whole number from 1-6.";
            }
        }

    vector<Country> world;
    readCountries(world);

    

    cout << "\n\n";
    switch(stat){
        case 1:
            sort(world.begin(), world.end(),[](const Country& lhs, const Country& rhs){ return lhs.getNCC() < rhs.getNCC(); });
        case 2:
            sort(world.begin(), world.end(),[](const Country& lhs, const Country& rhs){ return lhs.getND() < rhs.getND(); });
        case 3:
            sort(world.begin(), world.end(),[](const Country& lhs, const Country& rhs){ return lhs.getNRC() < rhs.getNRC(); });
        case 4:
            sort(world.begin(), world.end(),[](const Country& lhs, const Country& rhs){ return lhs.getTCC() < rhs.getTCC(); });
        case 5:
            sort(world.begin(), world.end(),[](const Country& lhs, const Country& rhs){ return lhs.getTD() < rhs.getTD(); });
        case 6:
            sort(world.begin(), world.end(),[](const Country& lhs, const Country& rhs){ return lhs.getTRC() < rhs.getTRC(); });

    }
    
    //writeCountries(world);
    return 0;
}


void readCountries(vector<Country>& vector){    
    ifstream file;
    file.open("summary.csv");
    if(file.fail()){
        cerr << "Could NOT find the file" << endl;
        exit(1);
    }
    string line;
    stringstream stream;
    getline(file,line);
    getline(file,line);
    stream << line;
    char x = stream.get();
    char y = stream.get();
    char z = stream.get();
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
    




    // vector.push_back(*(new Country("chile","CH", 99,88,77,66,55,44)));
}

void writeCountries(const vector<Country>& world){

    for(int i=0;i<4;i++){
        cout<<world[i].getName()<<world[i].getND()<<endl;
    };
}
