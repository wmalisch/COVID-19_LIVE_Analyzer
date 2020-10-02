#include <iostream>
#include <string>
#include "../headers/Country.h"

using namespace std;

int main(){
    Country c1;
    c1.getName();
    c1.setName("USA");
    c1.getName();
    return 0;
}