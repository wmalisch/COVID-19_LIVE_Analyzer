#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "../headers/Country.h"

using namespace std;

// Function declarations
void sortWriteCountries(vector<Country>&, int, int);
void readCountries(vector<Country>&);

int main(){
    int stat = 0;
    int sort = 0;

    // Start of program
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
    sortWriteCountries(data, stat, sort);
    return 0;
}

// Sort and write the countries. I did this in one function cause I was short on time and had troubles splitting it up
void sortWriteCountries(vector<Country>& vector, int sta, int sor){

    // Depending on what statistic the user wanted to view, switch the the code that asses that statistic
    switch(sta){
        int val;
        // New confirmed cases
        case 1:

            // Top 10
            if(sor==1){
                sort(vector.begin(), vector.end(),[](const Country& lhs, const Country& rhs){ return rhs.getNCC() < lhs.getNCC(); });
                val = vector[0].getNCC();
                val = val /70;
                for(int i=0;i< 10 ;i++){
                    cout << vector[i].getCode() << "  |  " << string((vector[i].getNCC() / val), '#') << endl;
                };
                cout << string(76,'_') << endl;
                cout << "New Confirmed Cases; Each # is approx. "<< val << " cases" << endl;

            // Bottom 10
            }else if(sor == 2){
                sort(vector.begin(), vector.end(),[](const Country& rhs, const Country& lhs){ return rhs.getNCC() < lhs.getNCC(); });
                val = vector[9].getNCC();
                
                // If the largest value of the selected 10 is less than 70, set each # to 1 case
                if(val<70){
                    for(int i=0;i< 10 ;i++){
                        cout << vector[i].getCode() << "  |  " << string(vector[i].getNCC(), '#') << endl;
                    };
                    cout << string(76,'_') << endl;
                    cout << "New Confirmed Cases; Each # is approx. "<< 1 << " case" << endl;
                }else{
                    val = val / 70;
                    for(int i=0;i< 10 ;i++){
                        cout << vector[i].getCode() << "  |  " << string((vector[i].getNCC() / val), '#') << endl;
                    };
                    cout << string(76,'_') << endl;
                    cout << "New Confirmed Cases; Each # is approx. "<< val << " cases" << endl;
                }
                
            }else{
                cout << "There was an error" << endl;
            }
            break;
        
        // New deaths
        case 2:

            // Top 10
            if(sor == 1){
                sort(vector.begin(), vector.end(),[](const Country& rhs, const Country& lhs){ return lhs.getND() < rhs.getND(); });
                val = vector[0].getND();

                // If the largest value of the selected 10 is less than 70, set each # to 1 case
                if(val<70){
                    for(int i=0;i< 10 ;i++){
                        cout << vector[i].getCode() << "  |  " << string(vector[i].getND(), '#') << endl;
                    };
                    cout << string(76,'_') << endl;
                    cout << "New Deaths; Each # is approx. "<< 1 << " death" << endl;
                }else{
                    val = val / 70;
                    for(int i=0;i< 10 ;i++){
                        cout << vector[i].getCode() << "  |  " << string((vector[i].getND() / val), '#') << endl;
                    };
                    cout << string(76,'_') << endl;
                    cout << "New Deaths; Each # is approx. "<< val << " deaths" << endl;
                }
            
            // Bottom 10
            }else if(sor == 2){
                sort(vector.begin(), vector.end(),[](const Country& lhs, const Country& rhs){ return lhs.getND() < rhs.getND(); });
                val = vector[0].getND();

                // If the largest value of the selected 10 is less than 70, set each # to 1 case
                if(val<70){
                    for(int i=0;i< 10 ;i++){
                        cout << vector[i].getCode() << "  |  " << string(vector[i].getND(), '#') << endl;
                    };
                    cout << string(76,'_') << endl;
                    cout << "New Deaths; Each # is approx. "<< 1 << " death" << endl;
                }else{
                    val = val / 70;
                    for(int i=0;i< 10 ;i++){
                        cout << vector[i].getCode() << "  |  " << string((vector[i].getND() / val), '#') << endl;
                    };
                    cout << string(76,'_') << endl;
                    cout << "New Deaths; Each # is approx. "<< val << " deaths" << endl;
                }
            }else{
                cout << "There was an error" << endl;
            }
            break;

        // New recovered cases
        case 3:

            // Top 10
            if(sor == 1){
                sort(vector.begin(), vector.end(),[](const Country& rhs, const Country& lhs){ return lhs.getNRC() < rhs.getNRC(); });
                val = vector[0].getNRC();

                // If the largest value of the selected 10 is less than 70, set each # to 1 case
                if(val<70){
                    for(int i=0;i< 10 ;i++){
                        cout << vector[i].getCode() << "  |  " << string(vector[i].getNRC(), '#') << endl;
                    };
                    cout << string(76,'_') << endl;
                    cout << "New Recovered Cases; Each # is approx. "<< 1 << " recovered case" << endl;
                }else{
                    val = val / 70;
                    for(int i=0;i< 10 ;i++){
                        cout << vector[i].getCode() << "  |  " << string((vector[i].getNRC() / val), '#') << endl;
                    };
                    cout << string(76,'_') << endl;
                    cout << "New Recovered Cases; Each # is approx. "<< val << " recovered cases" << endl;
                }
            
            // Bottom 10
            }else if(sor == 2){
                sort(vector.begin(), vector.end(),[](const Country& lhs, const Country& rhs){ return lhs.getNRC() < rhs.getNRC(); });
                val = vector[0].getNRC();

                // If the largest value of the selected 10 is less than 70, set each # to 1 case
                if(val<70){
                    for(int i=0;i< 10 ;i++){
                        cout << vector[i].getCode() << "  |  " << string(vector[i].getNRC(), '#') << endl;
                    };
                    cout << string(76,'_') << endl;
                    cout << "New Recovered Cases; Each # is approx. "<< 1 << " recovered case" << endl;
                }else{
                    val = val / 70;
                    for(int i=0;i< 10 ;i++){
                        cout << vector[i].getCode() << "  |  " << string((vector[i].getNRC() / val), '#') << endl;
                    };
                    cout << string(76,'_') << endl;
                    cout << "New Recovered Cases; Each # is approx. "<< val << " recovered cases" << endl;
                }
            }else{
                cout << "There was an error" << endl;
            }
            break;

        // Total confirmed cases
        case 4:

            // Top 10
            if(sor==1){
                sort(vector.begin(), vector.end(),[](const Country& lhs, const Country& rhs){ return rhs.getTCC() < lhs.getTCC(); });
                val = vector[0].getTCC();
                val = val /70;
                for(int i=0;i< 10 ;i++){
                    cout << vector[i].getCode() << "  |  " << string((vector[i].getTCC() / val), '#') << endl;
                };
                cout << string(76,'_') << endl;
                cout << "Total Confirmed Cases; Each # is approx. "<< val << " cases" << endl;
            
            // Bottom 10
            }else if(sor == 2){
                sort(vector.begin(), vector.end(),[](const Country& rhs, const Country& lhs){ return rhs.getTCC() < lhs.getTCC(); });
                val = vector[9].getTCC();

                // If the largest value of the selected 10 is less than 70, set each # to 1 case
                if(val<70){
                    for(int i=0;i< 10 ;i++){
                        cout << vector[i].getCode() << "  |  " << string(vector[i].getTCC(), '#') << endl;
                    };
                    cout << string(76,'_') << endl;
                    cout << "Total Confirmed Cases; Each # is approx. "<< 1 << " case" << endl;
                }else{
                    val = val / 70;
                    for(int i=0;i< 10 ;i++){
                        cout << vector[i].getCode() << "  |  " << string((vector[i].getTCC() / val), '#') << endl;
                    };
                    cout << string(76,'_') << endl;
                    cout << "Total Confirmed Cases; Each # is approx. "<< val << " cases" << endl;
                }
            }else{
                cout << "There was an error" << endl;
            }
            break;
        
        // Total deaths
        case 5:
            
            // Top 10
            if(sor == 1){
                sort(vector.begin(), vector.end(),[](const Country& rhs, const Country& lhs){ return lhs.getTD() < rhs.getTD(); });
                val = vector[0].getTD();

                // If the largest value of the selected 10 is less than 70, set each # to 1 case
                if(val<70){
                    for(int i=0;i< 10 ;i++){
                        cout << vector[i].getCode() << "  |  " << string(vector[i].getTD(), '#') << endl;
                    };
                    cout << string(76,'_') << endl;
                    cout << "Total Deaths; Each # is approx. "<< 1 << " death" << endl;
                }else{
                    val = val / 70;
                    for(int i=0;i< 10 ;i++){
                        cout << vector[i].getCode() << "  |  " << string((vector[i].getTD() / val), '#') << endl;
                    };
                    cout << string(76,'_') << endl;
                    cout << "Total Deaths; Each # is approx. "<< val << " deaths" << endl;
                }

            // Bottom 10
            }else if(sor == 2){
                sort(vector.begin(), vector.end(),[](const Country& lhs, const Country& rhs){ return lhs.getTD() < rhs.getTD(); });
                val = vector[0].getTD();

                // If the largest value of the selected 10 is less than 70, set each # to 1 case
                if(val<70){
                    for(int i=0;i< 10 ;i++){
                        cout << vector[i].getCode() << "  |  " << string(vector[i].getTD(), '#') << endl;
                    };
                    cout << string(76,'_') << endl;
                    cout << "Total Deaths; Each # is approx. "<< 1 << " death" << endl;
                }else{
                    val = val / 70;
                    for(int i=0;i< 10 ;i++){
                        cout << vector[i].getCode() << "  |  " << string((vector[i].getTD() / val), '#') << endl;
                    };
                    cout << string(76,'_') << endl;
                    cout << "Total Deaths; Each # is approx. "<< val << " deaths" << endl;
                }
            }else{
                cout << "There was an error" << endl;
            }
            break;
        
        // Total recovered cases
        case 6:

            // Top 10
            if(sor == 1){
                sort(vector.begin(), vector.end(),[](const Country& rhs, const Country& lhs){ return lhs.getTRC() < rhs.getTRC(); });
                val = vector[0].getTRC();

                // If the largest value of the selected 10 is less than 70, set each # to 1 case
                if(val<70){
                    for(int i=0;i< 10 ;i++){
                        cout << vector[i].getCode() << "  |  " << string(vector[i].getTRC(), '#') << endl;
                    };
                    cout << string(76,'_') << endl;
                    cout << "Total Recovered Cases; Each # is approx. "<< 1 << " recovered case" << endl;
                }else{
                    val = val / 70;
                    for(int i=0;i< 10 ;i++){
                        cout << vector[i].getCode() << "  |  " << string((vector[i].getTRC() / val), '#') << endl;
                    };
                    cout << string(76,'_') << endl;
                    cout << "Total Recovered Cases; Each # is approx. "<< val << " recovered cases" << endl;
                }

            // Bottom 10
            }else if(sor == 2){
                sort(vector.begin(), vector.end(),[](const Country& lhs, const Country& rhs){ return lhs.getTRC() < rhs.getTRC(); });
                val = vector[0].getTRC();

                // If the largest value of the selected 10 is less than 70, set each # to 1 case
                if(val<70){
                    for(int i=0;i< 10 ;i++){
                        cout << vector[i].getCode() << "  |  " << string(vector[i].getTRC(), '#') << endl;
                    };
                    cout << string(76,'_') << endl;
                    cout << "Total Recovered Cases; Each # is approx. "<< 1 << " recovered case" << endl;
                }else{
                    val = val / 70;
                    for(int i=0;i< 10 ;i++){
                        cout << vector[i].getCode() << "  |  " << string((vector[i].getTRC() / val), '#') << endl;
                    };
                    cout << string(76,'_') << endl;
                    cout << "Total Recovered Cases; Each # is approx. "<< val << " recovered cases" << endl;
                }
            }else{
                cout << "There was an error" << endl;
            }
            break;
    }
}

// Parse the csv and add all the data into a vector
void readCountries(vector<Country>& vector){    

    // First read the file in. Exit on error
    ifstream file;
    file.open("summary.csv");
    if(file.fail()){
        cerr << "Could NOT find the file" << endl;
        exit(1);
    }

    // While file is not empty, go through each line, and add the items to the vector
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
        vector.push_back(*(new Country(country,code,NCC,ND,NRC,TCC,TD,TRC))); // Add items to 
    }
}