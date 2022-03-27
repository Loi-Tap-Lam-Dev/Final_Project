#include "lib.h"

//I dunno how to name it:V
double numbering_Char(string x)
{
    if (x == "School_Year") return 1;
    else if (x == "Year") return 1.1;

    else if (x == "Class_list_info") return 2;
    else if (x == "Class_info") return 2.1;

    else if (x == "SV_list_info") return 3;
    else if (x == "SV_info") return 3.1;

    else if (x == "Semester" ) return 4;
    else if (x == "Term") return 4.1;

    else if (x == "SV_list_semester_mark") return 5;
    else if (x == "SV_sem_mark") return 5.1;

    else if (x == "Subject") return 6;
    else if (x == "Sub") return 6.1;

    else if (x == "Class_subject_info") return 7;
    else if (x == "Class_sub_info") return 7.1;

    else if (x == "SV_list_subject_mark") return 8;
    else if (x == "SV_sub_mark") return 8.1;

    return -1;
}

//Remove Blanket Space
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
        //Year::Semester
        Year::Semester* year_Semester_Head = nullptr;
        Year::Semester* year_Semester_Cur = nullptr;
        //Year::Semester::SV_list (Semester)
        Year::Semester::SV_List* year_Semester_Sv_ListHead = nullptr;
        Year::Semester::SV_List* year_Semester_Sv_ListCur = nullptr;
        //Year::Semester::Subject
        Year::Semester::Subject* year_Semester_SubjectHead = nullptr;
        Year::Semester::Subject* year_Semester_SubjectCur = nullptr;    
        //Year::Semester::Subject::Class
        Year::Semester::Subject::Class* year_Semester_Subject_ClassHead = nullptr;
        Year::Semester::Subject::Class* year_Semester_Subject_ClassCur  = nullptr;
        //Year::Semester::Subject::Class:Sv_List (Subject)
        Year::Semester::Subject::Class::SV_List* year_Semester_Subject_Class_Sv_ListHead = nullptr;
        Year::Semester::Subject::Class::SV_List* year_Semester_Subject_Class_Sv_ListCur = nullptr;


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

            //Case: initate Semester
            case 40:
            {
                year_Semester_Head = new Year::Semester;
                year_Semester_Cur = year_Semester_Head;

                //Save the head of the semester in year list
                year_Cur -> yearSemesterHead = year_Semester_Head;

                break;
            }

            //Case: initate Sv_List (Semester)
            case 50:
            {
                year_Semester_Sv_ListHead = new Year::Semester::SV_List;
                year_Semester_Sv_ListCur = year_Semester_Sv_ListHead;

                //Save the head of the SV_Semester_mark in semester list
                year_Semester_Cur -> yearSemesterSv_ListHead = year_Semester_Sv_ListHead;

                break;
            }

            //Case: initate Subject
            case 60:
            {
                year_Semester_SubjectHead = new Year::Semester::Subject;
                year_Semester_SubjectCur = year_Semester_SubjectHead;

                //Save the head of subject list in semester
                year_Semester_Cur -> yearSemesterSubjectHead = year_Semester_SubjectHead;
                
                break;
            }

            //Class_Subject_info
            case 70:
            {
                year_Semester_Subject_ClassHead = new Year::Semester::Subject::Class;
                year_Semester_Subject_ClassCur = year_Semester_Subject_ClassHead;

                //Save the head of class in the subject
                year_Semester_SubjectCur -> yearSemesterSubjectClassHead = year_Semester_Subject_ClassHead;
                
                break;
            }

            //Sv_Subject_Mark
            case 80:
            {
                year_Semester_Subject_Class_Sv_ListHead = new Year::Semester::Subject::Class::SV_List;
                year_Semester_Subject_Class_Sv_ListCur = year_Semester_Subject_Class_Sv_ListHead;

                //save the head of SV_list in the class (Subject)
                year_Semester_Subject_ClassCur -> yearSemesterSubjectClassSV_ListHead = year_Semester_Subject_Class_Sv_ListHead;

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
            //Semester name
            case 41:
            {
                if (year_Semester_Cur -> sNext != nullptr)
                {
                    //Move Next
                    year_Semester_Cur = year_Semester_Cur -> sNext;
                }
            
                char* semester_Name = strtok(NULL,denim);
                year_Semester_Cur -> Term = atoi(semester_Name);

                year_Semester_Cur -> sNext = new Year::Semester;

                break;
            }

            //SV_semester_mark
            case 51:
            {
                if (year_Semester_Sv_ListCur -> svNext != nullptr)
                {
                    year_Semester_Sv_ListCur = year_Semester_Sv_ListCur -> svNext;
                }

                //Get value such as: no, mssv,..
                char* No = strtok(NULL,denim);
                char* Student_ID = strtok(NULL,denim);
                char* GPA = strtok(NULL,denim);
                char* Average = strtok(NULL,denim);

                //Assigned
                year_Semester_Sv_ListCur -> no = atoi(No);
                year_Semester_Sv_ListCur -> idStudent = atoi(Student_ID);
                year_Semester_Sv_ListCur -> GPA = atoi(GPA);
                year_Semester_Sv_ListCur -> averageMark = atoi(Average);

                //Create new next NOde
                year_Semester_Sv_ListCur -> svNext = new Year::Semester::SV_List;

                break;
            }

            //Semester_Subject
            case 61:
            {
                if (year_Semester_SubjectCur -> subNext != nullptr)
                {
                    year_Semester_SubjectCur = year_Semester_SubjectCur -> subNext;
                }       

                //Assigned
                year_Semester_SubjectCur -> id_Subject = strtok(NULL,denim);
                year_Semester_SubjectCur -> name_Subject = strtok(NULL,denim);
                year_Semester_SubjectCur -> startDate = strtok(NULL,denim);
                year_Semester_SubjectCur -> endDate = strtok(NULL,denim);
                year_Semester_SubjectCur -> maximumRegrister = atoi(strtok(NULL,denim));

                //Create new next NOde
                year_Semester_SubjectCur -> subNext = new Year::Semester::Subject;

                break;
            }

            //Class_Semester_info
            case 71:
            {
                if (year_Semester_Subject_ClassCur -> clNext != nullptr)
                {
                    year_Semester_Subject_ClassCur = year_Semester_Subject_ClassCur -> clNext;
                }

                //Assigned
                year_Semester_Subject_ClassCur -> nameClass = strtok(NULL,denim);

                //Create new next NOde
                year_Semester_Subject_ClassCur -> clNext = new Year::Semester::Subject::Class;
            
                break;
            }

            //SV_list_Subject_mark
            case 81:
            {
                if (year_Semester_Subject_Class_Sv_ListCur -> svNext != nullptr)
                {
                    year_Semester_Subject_Class_Sv_ListCur = year_Semester_Subject_Class_Sv_ListCur -> svNext;
                }

                //Get value 
                char* No = strtok(NULL,denim);
                char* Student_ID = strtok(NULL,denim);
                char* Total_Mark = strtok(NULL,denim);
                char* Mid_Term_Mark = strtok(NULL,denim);
                char* Final_Term_Mark = strtok(NULL,denim);
                char* Other_Mark = strtok(NULL,denim);

                //Assigned
                year_Semester_Subject_Class_Sv_ListCur -> no = atoi(No);
                year_Semester_Subject_Class_Sv_ListCur -> idStudent = atoi(Student_ID);
                year_Semester_Subject_Class_Sv_ListCur -> totalMark = atoi(Total_Mark);
                year_Semester_Subject_Class_Sv_ListCur -> midTermMark = atoi(Mid_Term_Mark);
                year_Semester_Subject_Class_Sv_ListCur -> finalTermMark = atoi(Final_Term_Mark );
                year_Semester_Subject_Class_Sv_ListCur -> otherMark = atoi(Other_Mark);

                year_Semester_Subject_Class_Sv_ListCur -> svNext = new Year::Semester::Subject::Class::SV_List;
                
                break;
            }

            //Sv_info
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

            year_Cur -> yNext = nullptr;

            //Year::Class
            year_Class_Cur -> clNext =  nullptr;

            //Year::Class::SV_List
             year_Class_Sv_Cur -> svNext = nullptr;

            //Year::Semester
             year_Semester_Cur -> sNext = nullptr;

            //Year::Semester::SV_list (Semester)
             year_Semester_Sv_ListCur -> svNext = nullptr;

            //Year::Semester::Subject
             year_Semester_SubjectCur -> subNext = nullptr;    

            //Year::Semester::Subject::Class
            year_Semester_Subject_ClassCur -> clNext = nullptr;

            //Year::Semester::Subject::Class:Sv_List (Subject)
             year_Semester_Subject_Class_Sv_ListCur -> svNext = nullptr;



            break;
        }

    }

}
