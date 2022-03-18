#include "lib.h"

//Read file
void readFileYear(Year* &year_Head) {

    //Open File Year_Sheet
    finp.open("Year_Sheet.csv", ios::in);
    //Assign year_Cur 
    Year* year_Cur = year_Head;

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
        
        //1st elements is represent for the year name
        year_Cur -> nameYear = strtok(input,denim);
        //Set up class being contain by year list
        Year::Class* class_Head = new Year :: Class;
        Year::Class* class_Cur = class_Head;
        while (true)
        {
            //Check if the data of 1 line is over?
            char* temp_Class =  strtok(NULL,denim);
            if (temp_Class == NULL ) 
            {
                class_Cur = nullptr;
                break;
            }
            //If not every next elements come next to 1st ele is represent for class name
            class_Cur -> clNext = new Year :: Class;
            class_Cur -> nameClass = temp_Class;
            //in case not being assigned with class_cur
            if (class_Head == nullptr ) class_Head =  class_Cur;
            class_Cur = class_Cur -> clNext;
        }
        year_Cur -> yearCLassHead = class_Head;
        //Create a new node of next year
        year_Cur -> yNext = new Year;
        year_Cur = year_Cur -> yNext;
        input = nullptr;
    }

}