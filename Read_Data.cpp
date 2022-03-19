#include "lib.h"

double numbering_Char(string x)
{
    if (x == "School_Year") return 1;
    else if (x == "Year") return 1.1;
    else if (x == "Class_room") return 2;
    else if (x == "Class") return 2.1;
    else if (x == "SV_list") return 3;
    else if (x == "SV") return 3.1;
    return -1;
}

void remove_All_BlanketSpace(string &s)
{
    int i = 0;
    while (s[i] == ' ') 
    {
        s.erase(s.begin() + i);
    }
}

//Read file
void readFileYear(Year* &year_Head) {

    //Open File Year_Sheet
    finp.open("Year_Sheet.csv", ios::in);

    //Declare list area
        Year* year_Cur = nullptr; // Year
        //Year::Class
        Year::Class* year_Class_Head = nullptr;
        Year::Class* year_Class_Cur =  nullptr;
        //Year::Class::SV_List
        Year::Class::SV_List* year_Class_Sv_Head = nullptr;
        Year::Class::SV_List* year_Class_Sv_Cur = nullptr;

    //Read data from file
    while ( true )
    {
        //Declare and getline
        string s;
        getline(finp,s);
        remove_All_BlanketSpace(s);
        if (s == "") break;

        //Declare and assign input with size of line being got before
        char* input = new char [s.size()];
        strcpy(input,s.c_str());
        
        //Set up denim to cut elements
        const char* denim = ",";
        
        //Using switch of to choose cases
        char* token = strtok(input,denim);
    
        //Switch
        int x = (int) ( numbering_Char(token) * 10 );
        switch ( (int) ( numbering_Char(token) * 10 ) )
        {
            //Case: initate year list
            case 10:
            {
                year_Head = new Year;
                year_Cur = year_Head;

                break;
            }

            //Case: initate classroom list
            case 20:
            {
                year_Class_Head = new Year::Class;
                year_Class_Cur = year_Class_Head;

                //Save the head of class list
                year_Cur -> yearCLassHead = year_Class_Head;

                break;
            }

            //Case: initate Sv_list
            case 30:
            {
                year_Class_Sv_Head = new Year::Class::SV_List;
                year_Class_Sv_Cur = year_Class_Sv_Head;

                //Save the head of sv list
                year_Class_Cur -> yearClassSV_ListHead = year_Class_Sv_Head;

                break;
            }

            //Year name
            case 11:
            {
                if (year_Cur -> yNext != nullptr)
                {
                    //Move next
                    year_Cur = year_Cur -> yNext;
                }

                char* year_Name = strtok(NULL,denim);
                year_Cur -> nameYear = year_Name;

                year_Cur -> yNext = new Year;

                break;
            }

            //Class name
            case 21:
            {
                if ( year_Class_Cur -> clNext != nullptr )
                {
                    //Move Next
                    year_Class_Cur = year_Class_Cur -> clNext;
                }

                char* class_Name = strtok(NULL,denim);
                year_Class_Cur -> nameClass = class_Name;

                year_Class_Cur -> clNext = new Year::Class;

                break;
            }

            //Sv
            case 31:
            {
                if ( year_Class_Sv_Cur -> svNext != nullptr)
                {
                    //Move next
                    year_Class_Sv_Cur = year_Class_Sv_Cur -> svNext;
                }

                //To convert -> int
                char* No = strtok(NULL,denim);
                char* student_ID = strtok(NULL,denim);
                char* social_ID = strtok(NULL,denim);

                // Remain char*
                char* last_Name = strtok(NULL,denim);
                char* first_Name = strtok(NULL,denim);
                char* gender = strtok(NULL,denim);
                char* birth_date = strtok(NULL,denim);

                //Assigned
                year_Class_Sv_Cur -> no = atoi(No);
                year_Class_Sv_Cur -> idStudent = atoi(student_ID);
                year_Class_Sv_Cur -> socialID = atoi(social_ID);
                year_Class_Sv_Cur -> lastName = last_Name;
                year_Class_Sv_Cur -> firstName = first_Name;
                year_Class_Sv_Cur -> gender = gender;
                year_Class_Sv_Cur -> dateOfBirth = birth_date;

                //Declare new SV_List nOde
                year_Class_Sv_Cur -> svNext = new Year::Class::SV_List;
                
                break;
            }

        default:

            return;

            break;
        }

    }

}