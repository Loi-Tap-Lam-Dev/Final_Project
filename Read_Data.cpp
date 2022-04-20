#include "lib.h"

void Read_Year(School_Year* &sYear_Head)
{
    ifstream year_Input;
    year_Input.open("./CSV_File/Year.csv");
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

    year_Input.close();
}

void Read_Class(School_Year* &sYear_Head)
{
    ifstream Class_Input;
    Class_Input.open("./CSV_File/Year_Class.csv");

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
                            delete [] Input_Line;
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
                        delete [] Input_Line;
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

        delete [] Input_Line;
    } while (!Class_Input.eof());

    Class_Input.close();
}

void Read_Semester(School_Year* &sYear_Head)
{
    ifstream Semseter_Input;
    Semseter_Input.open("./CSV_File/Year_Semester.csv");

    //Declare
    string Line = "";
    School_Year* sYear_Cur = nullptr;
    School_Year::Semester* Semseter_Head = nullptr;
    School_Year::Semester* Semseter_Cur = nullptr;
    School_Year::Semester::Student_listMark* Term_Mark_Head = nullptr;
    School_Year::Semester::Student_listMark* Term_Mark_Cur = nullptr;
    School_Year::Semester::Subject* Subject_Head = nullptr;
    School_Year::Semester::Subject* Subject_Cur = nullptr;
    School_Year::Semester::Subject::Student_listMark* Subject_Mark_Head = nullptr;
    School_Year::Semester::Subject::Student_listMark* Subject_Mark_Cur = nullptr;
    

    bool Check_Term_info = false;
    bool Check_Term_Mark = false;
    bool Check_Subject = false;
    bool Check_Subjet_Mark = false;
    do
    {
        getline(Semseter_Input,Line);

        if (Line == "") break;

        char* Input_Line = new char [Line.size()];
        const char* denim = ",";

        strcpy(Input_Line,Line.c_str());
        Input_Line = strtok(Input_Line,denim);
        string s_Line = Input_Line;
        if (Check_Term_info || Check_Term_Mark || Check_Subject || Check_Subjet_Mark) strcpy(Input_Line,Line.c_str());

        if (s_Line == "Semester For Year")
        {
            sYear_Cur = find_School_Year(sYear_Head,strtok(NULL,denim));

            Check_Term_info = false;
            Check_Term_Mark = false;
            Check_Subject = false;
            Check_Subjet_Mark = false;
            
            delete [] Input_Line;
            continue;

        }
        else if (s_Line == "Semester info")
                {
                    Semseter_Head = sYear_Cur -> yearSemesterHead;
                    //Semseter_Cur = Semseter_Head;

                    Check_Term_info = true;
                    Check_Term_Mark = false;
                    Check_Subject = false;
                    Check_Subjet_Mark = false;
                    delete [] Input_Line;
                    continue;

                }
        else  if (s_Line == "Sv_Semester_Mark")
                {
                    Term_Mark_Head = Semseter_Cur -> yearSemesterStudent_listMarkHead;
                    //Term_Mark_Cur = Term_Mark_Head;

                    Check_Term_info = false;
                    Check_Term_Mark = true;
                    Check_Subject = false;
                    Check_Subjet_Mark = false;
                    delete [] Input_Line;
                    continue;
                }

        else  if (s_Line == "Subject")
                {
                    Subject_Head = Semseter_Cur -> yearSemesterSubjectHead;
                    //Subject_Cur = Subject_Head;

                    Check_Term_info = false;
                    Check_Term_Mark = false;
                    Check_Subject = true;
                    Check_Subjet_Mark = false;
                    delete [] Input_Line;
                    continue;
                }
        else  if (s_Line == "Subject_Mark")
                {
                    Subject_Mark_Head = Subject_Cur -> yearSemesterSubStudent_ListHead;
                    //Subject_Mark_Cur = Subject_Mark_Head;

                    Check_Term_info = false;
                    Check_Term_Mark = false;
                    Check_Subject = false;
                    Check_Subjet_Mark = true;
                    delete [] Input_Line;
                    continue;
                }
        else if (Check_Term_info)
                {
                    Semseter_Cur = Semseter_Head;
                    if (Semseter_Head == nullptr)
                    {
                        Semseter_Head = new School_Year::Semester;

                        Semseter_Head -> Term = atoi (strtok(Input_Line,denim));
                        Semseter_Head -> start_Date = strtok(NULL,denim);
                        Semseter_Head -> end_Date = strtok(NULL,denim);

                        sYear_Cur -> yearSemesterHead = Semseter_Head;
                        delete [] Input_Line;
                        continue;
                    }

                    while (Semseter_Cur -> Next != nullptr) Semseter_Cur = Semseter_Cur -> Next;
                    Semseter_Cur -> Next = new School_Year::Semester;
                    Semseter_Cur -> Next -> Prev = Semseter_Cur;
                    Semseter_Cur = Semseter_Cur -> Next;

                    Semseter_Cur -> Term = atoi (strtok(Input_Line,denim));
                    Semseter_Cur -> start_Date = strtok(NULL,denim);
                    Semseter_Cur -> end_Date = strtok(NULL,denim);
                    
                    delete [] Input_Line;
                    continue;
                }
        else if (Check_Term_Mark)
                {
                    Term_Mark_Cur = Term_Mark_Head;
                    if (Term_Mark_Head == nullptr)
                    {
                        Term_Mark_Head = new School_Year::Semester::Student_listMark;
                        
                        Term_Mark_Head -> no = atoi (strtok(Input_Line,denim));
                        Term_Mark_Head -> no = 1;
                        Term_Mark_Head -> idStudent = atoi (strtok(NULL,denim));
                        Term_Mark_Head -> fullName = strtok(NULL,denim);
                        Term_Mark_Head -> totalCredit = atoi (strtok(NULL,denim));
                        Term_Mark_Head -> GPA = atof(strtok(NULL,denim));
                        Term_Mark_Head -> averageMark = atof(strtok(NULL,denim));
                    
                        Semseter_Cur -> yearSemesterStudent_listMarkHead = Term_Mark_Head;

                        delete [] Input_Line;
                        continue;
                    }

                    while (Term_Mark_Cur -> Next != nullptr) Term_Mark_Cur = Term_Mark_Cur -> Next;
                    Term_Mark_Cur -> Next = new School_Year::Semester::Student_listMark;
                    Term_Mark_Cur -> Next -> Prev = Term_Mark_Cur;
                    Term_Mark_Cur = Term_Mark_Cur -> Next;

                    Term_Mark_Cur -> no = atoi (strtok(Input_Line,denim));
                    Term_Mark_Cur -> no = Term_Mark_Cur -> Prev -> no + 1;
                    Term_Mark_Cur -> idStudent = atoi (strtok(NULL,denim));
                    Term_Mark_Cur -> fullName = strtok(NULL,denim);
                    Term_Mark_Cur -> totalCredit = atoi (strtok(NULL,denim));
                    Term_Mark_Cur -> GPA = atof(strtok(NULL,denim));
                    Term_Mark_Cur -> averageMark = atof(strtok(NULL,denim));

                    delete [] Input_Line;
                    continue;
                }
        else if (Check_Subject)
                {
                    Subject_Cur = Subject_Head;
                    if (Subject_Head == nullptr)
                    {
                        Subject_Head = new School_Year::Semester::Subject;
                        
                        Subject_Head -> name_Subject = strtok(Input_Line,denim);
                        Subject_Head -> id_Subject = strtok(NULL,denim);
                        Subject_Head -> startDate = strtok(NULL,denim);
                        Subject_Head -> endDate = strtok(NULL,denim);
                        Subject_Head -> teacher_Name = strtok(NULL,denim);
                        Subject_Head -> day_Of_Session_1 = strtok(NULL,denim);
                        Subject_Head -> at_Time_1 = strtok(NULL,denim);
                        Subject_Head -> day_Of_Session_2 = strtok(NULL,denim);
                        Subject_Head -> at_Time_2 = strtok(NULL,denim);
                        Subject_Head -> number_Of_Credit = atoi (strtok(NULL,denim));
                        Subject_Head -> maximumRegrister = atoi (strtok(NULL,denim));
                    
                        Semseter_Cur -> yearSemesterSubjectHead = Subject_Head;
                        

                        delete [] Input_Line;
                        continue;
                    }

                    while (Subject_Cur -> Next != nullptr) Subject_Cur = Subject_Cur -> Next;
                    Subject_Cur -> Next = new School_Year::Semester::Subject;
                    Subject_Cur -> Next -> Prev = Subject_Cur;
                    Subject_Cur = Subject_Cur -> Next;

                    Subject_Cur -> name_Subject = strtok(Input_Line,denim);
                    Subject_Cur -> id_Subject = strtok(NULL,denim);
                    Subject_Cur -> startDate = strtok(NULL,denim);
                    Subject_Cur -> endDate = strtok(NULL,denim);
                    Subject_Cur -> teacher_Name = strtok(NULL,denim);
                    Subject_Cur -> day_Of_Session_1 = strtok(NULL,denim);
                    Subject_Cur -> at_Time_1 = strtok(NULL,denim);
                    Subject_Cur -> day_Of_Session_2 = strtok(NULL,denim);
                    Subject_Cur -> at_Time_2 = strtok(NULL,denim);
                    Subject_Cur -> number_Of_Credit = atoi (strtok(NULL,denim));
                    Subject_Cur -> maximumRegrister = atoi (strtok(NULL,denim));
                    
                    delete [] Input_Line;
                    continue;
                }
        else if (Check_Subjet_Mark)
                {
                    Subject_Mark_Cur = Subject_Mark_Head;
                    if (Subject_Mark_Head == nullptr)
                    {
                        Subject_Mark_Head = new School_Year::Semester::Subject::Student_listMark;
                        
                        Subject_Mark_Head -> no = atoi(strtok(Input_Line,denim));
                        Subject_Mark_Head -> no = 1;
                        Subject_Mark_Head -> idStudent = atoi( strtok(NULL,denim));
                        Subject_Mark_Head -> FullName = strtok(NULL,denim);
                        Subject_Mark_Head -> midTermMark = atof (strtok(NULL,denim));
                        Subject_Mark_Head -> finalTermMark = atof (strtok(NULL,denim));
                        Subject_Mark_Head -> otherMark = atof (strtok(NULL,denim));
                        Subject_Mark_Head -> totalMark = atof (strtok(NULL,denim));
                    
                        Subject_Cur -> yearSemesterSubStudent_ListHead = Subject_Mark_Head;
                        
                        delete [] Input_Line;
                        continue;
                    }

                    while (Subject_Mark_Cur -> Next != nullptr) Subject_Mark_Cur = Subject_Mark_Cur -> Next;
                    Subject_Mark_Cur -> Next = new School_Year::Semester::Subject::Student_listMark;
                    Subject_Mark_Cur -> Next -> Prev = Subject_Mark_Cur;
                    Subject_Mark_Cur = Subject_Mark_Cur -> Next;

                    Subject_Mark_Cur -> no = atoi(strtok(Input_Line,denim));
                    Subject_Mark_Cur -> no = Subject_Mark_Cur -> Prev -> no + 1;
                    Subject_Mark_Cur -> idStudent = atoi( strtok(NULL,denim));
                    Subject_Mark_Cur -> FullName = strtok(NULL,denim);
                    Subject_Mark_Cur -> midTermMark = atof (strtok(NULL,denim));
                    Subject_Mark_Cur -> finalTermMark = atof (strtok(NULL,denim));
                    Subject_Mark_Cur -> otherMark = atof (strtok(NULL,denim));
                    Subject_Mark_Cur -> totalMark = atof (strtok(NULL,denim));

                    delete [] Input_Line;
                    continue;
                }

    } while (!Semseter_Input.eof());
    
    Semseter_Input.close();
}

void Read_Data_From_File(School_Year* &sYear_Head)
{
    
    Read_Year(sYear_Head);

    Read_Class(sYear_Head);

    Read_Semester(sYear_Head);

    return ;
}