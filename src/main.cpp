#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "../headers/Country.h"

using namespace std;


void sortCountries(vector<Country>&, int, int);
void readCountries(vector<Country>&);

int main(){
    int stat = 0;
    int sort = 0;

    cout << "\n\n#########  WELCOME TO THE COVID ANALYZER  ###########" << endl 
        << endl 
        << "You have started using the covid assessment tool.\nIf you have not seen an error, then the covid stats have been taken.\n" << endl;
    
    // Error control for entering stat
    while(stat <= 0 || stat > 6){
        cout << "Please see the output options below. Enter the corresponding number in square brackets to see the statistic you want.\n" << endl
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
            cout << "That didn't work. Please try a whole number from 1-6." << endl;
        }
        cout << "\n";
    }

    // Error control for entering sort direction
    while(sort <=0 || sort > 2){
        cout << "You will also need a sort type.\nDo you want the top or bottom results?\nEnter the corresponding number in square brackets to the order you want.\n" << endl
                << "[1] Top 10" << endl 
                << "[2] Bottom 10" << endl
                << "Enter number here: ";
        while(!(cin>>sort)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "That didn't work. Please try a whole number from 1-2" << endl;
        }
        cout << "\n";
    }

    vector<Country> data;
    readCountries(data);
    sortCountries(data, stat, sort);
    // writeCountries(data, sort);
    return 0;
}

void sortWriteCountries(vector<Country>& vector, int sta, int sor){
    Country c;
    Country x;
    int val;
    switch(sta){
        case 1:
            if(sor==1){
                sort(vector.begin(), vector.end(),[](const Country& lhs, const Country& rhs){ return rhs.getNCC() < lhs.getNCC(); });
                val = vector[0].getNCC();
                val = val /70;
                for(int i=0;i< 10 ;i++){
                    cout << vector[i].getCode() << "  |  " << string((vector[i].getNCC() / val), '#') << endl;
                };
                cout << string(76,'_') << endl;
                cout << "New Confirmed Cases; Each # is approx. "<< val << " cases" << endl;
            }else if(sor == 2){
                sort(vector.begin(), vector.end(),[](const Country& rhs, const Country& lhs){ return rhs.getNCC() < lhs.getNCC(); });
                for(int i=0;i< 10 ;i++){
                    cout<<vector[i].getName()<<" New Cases: "<<vector[i].getNCC()<<endl;
                };
            }else{
                cout << "There was an error" << endl;
            }
            
            
        case 2:
            sort(vector.begin(), vector.end(),[](const Country& lhs, const Country& rhs){ return lhs.getND() < rhs.getND(); });
            val =70;
            val = val/9;
            cout << val;

        case 3:
            sort(vector.begin(), vector.end(),[](const Country& lhs, const Country& rhs){ return lhs.getNRC() < rhs.getNRC(); });
        case 4:
            sort(vector.begin(), vector.end(),[](const Country& lhs, const Country& rhs){ return lhs.getTCC() < rhs.getTCC(); });
        case 5:
            sort(vector.begin(), vector.end(),[](const Country& lhs, const Country& rhs){ return lhs.getTD() < rhs.getTD(); });
        case 6:
            sort(vector.begin(), vector.end(),[](const Country& lhs, const Country& rhs){ return lhs.getTRC() < rhs.getTRC(); });
    }


}


void readCountries(vector<Country>& vector){    
    ifstream file;
    file.open("summary.csv");
    if(file.fail()){
        cerr << "Could NOT find the file" << endl;
        exit(1);
    }
    string line;
    getline(file,line);
    while(!(file.eof())){
        string country;
        string code;
        string buff;
        stringstream converter;
        stringstream stream;
        int NCC;int ND;int NRC;int TCC;int TD;int TRC;

        getline(file,line); // Retrieve a record of country data
        stream << line; // Put the record into a stringstream object
        
        stream.get(); // Get qoutation mark
        getline(stream,country,'"');
        stream.get(); // Get quotation mark
        stream.get(); // Get comma
        getline(stream,code,'"');
        stream.get(); // Get comma
        getline(stream,buff,','); // Get time stamp
        getline(stream,buff,','); // Get NCC
        converter << buff;
        converter >> NCC;
        getline(stream,buff,','); // Get ND
        converter.clear();
        converter << buff;
        converter >> ND;
        getline(stream,buff,','); // Get NRC
        converter.clear();
        converter << buff;
        converter >> NRC;
        getline(stream,buff,',');
        stream.get(); // Get qoutation mark
        getline(stream,buff,'"'); // Get lower case country
        stream.get(); // Get comma
        getline(stream,buff,','); // Get TCC
        converter.clear();
        converter << buff;
        converter >> TCC;
        getline(stream,buff,','); // Get TD
        converter.clear();
        converter << buff;
        converter >> TD;
        getline(stream,buff,','); // Get TRC
        converter.clear();
        converter << buff;
        converter >> TRC;
        vector.push_back(*(new Country(country,code,NCC,ND,NRC,TCC,TD,TRC)));
    }
    

}