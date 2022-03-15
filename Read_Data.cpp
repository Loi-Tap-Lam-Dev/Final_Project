#include "lib.h"

//Read file
void readFileYear(Year* &yearHead) {

    //Open File Year_Sheet
    finp.open("Year_Sheet.csv", ios::in);
    
    while ( true )
    {
        string s;
        getline(finp,s);
        if (s == "") break;
        char* input = new char [s.size()];
        strcpy(input,s.c_str());
        
        const char* denim = ",";
        yearHead -> nameYear = strtok(input,denim);
        
        input = nullptr;
    }

    finp.close();
    return;
}