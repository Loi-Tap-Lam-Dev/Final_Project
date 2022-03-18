@ -1,22 +1,40 @@
#include "lib.h"

//Read file
void readFileYear(Year* &yearHead) {
void readFileYear(Year* &year_Head) {

    //Open File Year_Sheet
    finp.open("Year_Sheet.csv", ios::in);
    
    //Read data from file
    while ( true )
    {
        //Declare and getline
        string s;
        getline(finp,s);
        if (s == "") break;
        //Declare and assign input with size of line being got before
        char* input = new char [s.size()];
        strcpy(input,s.c_str());
        
        //Set up denim to cut elements
        const char* denim = ",";
        yearHead -> nameYear = strtok(input,denim);
        
        //1st elements is represent for the year name
        Year* year_Cur = year_Head;
        year_Cur -> nameYear = strtok(input,denim);
        //Set up class being contain by year list
        Year::Class* class_Head = nullptr;
        Year::Class* class_Cur = class_Head;
        while (true)
        {
            //Check if the data of 1 line is over?
            char* temp_Class =  strtok(NULL,denim);
            if (temp_Class == NULL ) break;
            //If not every next elements come next to 1st ele is represent for class name
            class_Cur = new Year :: Class;
            class_Cur -> nameClass = temp_Class;

        }

        input = nullptr;
    }

