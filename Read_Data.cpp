#include "lib.h"


void Read_Data_From_File(School_Year* &sYear_Head)
{
    
    ifstream year_Input;
    year_Input.open("./CSV_File/Year.csv");
    ifstream Class_Input;
    Class_Input.open("./CSV_File/Year_Class.csv");
    
    while (!year_Input.eof())
    {
            string Line;
            getline(year_Input,Line); //Skip one    
            getline(year_Input,Line);

            School_Year* sYear_Cur = sYear_Head;

            if (sYear_Head == nullptr)
            {
                sYear_Head = new School_Year;
                sYear_Head -> year = Line;
                sYear_Cur = sYear_Head;

                continue;
            }

            while (sYear_Cur -> Next != nullptr) sYear_Cur = sYear_Cur -> Next;
            sYear_Cur -> Next = new School_Year;
            sYear_Cur -> Next -> Prev = sYear_Cur;
            sYear_Cur = sYear_Cur -> Next;
            sYear_Cur -> year = Line;   
    }

    string Line = "";
    School_Year::Year_Class* Class_Head = nullptr;
    School_Year::Year_Class* Class_Cur = nullptr;
    School_Year::Year_Class::SV_List* Sv_Head = nullptr;
    School_Year::Year_Class::SV_List* Sv_Cur = nullptr;
    School_Year* sYear_Cur = nullptr;
    bool Check_To_Start_SvList = false;

    do
    {
        getline(Class_Input,Line);

        char* Input_Line = new char [Line.size()];
        const char* denim = ",";

        strcpy(Input_Line,Line.c_str());
        Input_Line = strtok(Input_Line,denim);
        string s_Line = Input_Line;
        if (Check_To_Start_SvList) strcpy(Input_Line,Line.c_str());

        if (s_Line == "Classes For Year")
        {
            sYear_Cur = find_School_Year(sYear_Head,strtok(NULL,denim));
            Class_Head = sYear_Cur -> yearCLassHead;
            Check_To_Start_SvList = false;
        }
        else if (s_Line == "Class")
                {
                    Class_Cur = Class_Head;
                    Check_To_Start_SvList = false;
                    if (Class_Head == nullptr)
                        {
                            Class_Head = new School_Year::Year_Class;
                            Class_Head -> nameClass = strtok(NULL,denim);
                            sYear_Cur -> yearCLassHead = Class_Head;
                            Class_Cur = Class_Head;
                            continue;
                        }
                    
                    while (Class_Cur -> Next != nullptr) Class_Cur = Class_Cur -> Next;
                    Class_Cur -> Next = new School_Year::Year_Class;
                    Class_Cur -> Next -> Prev = Class_Cur;
                    Class_Cur = Class_Cur -> Next;
                    Class_Cur -> nameClass = strtok(NULL,denim);
                }
        else if (Check_To_Start_SvList == false)
        {
            Check_To_Start_SvList = true;
            Sv_Head = Class_Cur -> yearClassSV_ListHead;

        }
        else 
            {
                Sv_Cur = Sv_Head;
                if (Sv_Head == nullptr)
                    {
                        Sv_Head = new School_Year::Year_Class::SV_List;
                        Sv_Head -> no = atoi(strtok(Input_Line,denim)) ;
                        Sv_Head -> no = 1;
                        Sv_Head -> idStudent = atoi (strtok(NULL,denim));
                        Sv_Head -> socialID = atoi (strtok(NULL,denim));
                        Sv_Head -> firstName = strtok(NULL,denim);
                        Sv_Head -> lastName = strtok(NULL,denim);
                        Sv_Head -> gender = strtok(NULL,denim);
                        Sv_Head -> dateOfBirth = strtok(NULL,denim);

                        Class_Cur -> yearClassSV_ListHead = Sv_Head;
                        Sv_Cur = Sv_Head;
                        continue;
                    }
                
                while (Sv_Cur -> Next != nullptr) Sv_Cur = Sv_Cur -> Next;
                Sv_Cur -> Next = new School_Year::Year_Class::SV_List;
                Sv_Cur -> Next -> Prev = Sv_Cur;
                Sv_Cur = Sv_Cur -> Next;

                Sv_Cur -> no = atoi(strtok(Input_Line,denim)) ;
                Sv_Cur -> no = Sv_Cur -> Prev -> no + 1;
                Sv_Cur -> idStudent = atoi (strtok(NULL,denim));
                Sv_Cur -> socialID = atoi (strtok(NULL,denim));
                Sv_Cur -> firstName = strtok(NULL,denim);
                Sv_Cur -> lastName = strtok(NULL,denim);
                Sv_Cur -> gender = strtok(NULL,denim);
                Sv_Cur -> dateOfBirth = strtok(NULL,denim);
            }


    } while (!Class_Input.eof());
    
    return ;
}