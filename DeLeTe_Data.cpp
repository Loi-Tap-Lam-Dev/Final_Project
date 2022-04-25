#include "lib.h"


//Delete List of student mark
void Delete_Element_Of_Student_listMark(School_Year::Semester::Student_listMark* &semStudent_Cur, int type)
{
    while (semStudent_Cur != nullptr)
    {
        School_Year::Semester::Student_listMark* Student_temp = semStudent_Cur;

        semStudent_Cur = semStudent_Cur -> Next;

        delete Student_temp;
    }
}

//Delete Element of Subject_Student_Mark
void Delete_Element_Of_StudentList(School_Year::Semester::Subject::Student_listMark* &ClassStudent_Cur, int type)
{
    while (ClassStudent_Cur != nullptr)
    {
        School_Year::Semester::Subject::Student_listMark* ClassStudent_Temp = ClassStudent_Cur;

            ClassStudent_Cur = ClassStudent_Cur -> Next;

        delete ClassStudent_Temp;
    }
    return;
}

//Delete Element of subject
void Delete_Element_Of_Subject(School_Year::Semester::Subject* &semSubject_Cur, int type)
{
    if (type == 1)
    {
        while (semSubject_Cur != nullptr)
        {
            School_Year::Semester::Subject::Student_listMark* StudentCur = semSubject_Cur -> yearSemesterSubStudent_ListHead;

                if (StudentCur != nullptr) Delete_Element_Of_StudentList(StudentCur,1);

                semSubject_Cur -> yearSemesterSubStudent_ListHead = nullptr;

            School_Year::Semester::Subject* Subject_Temp = semSubject_Cur;

                semSubject_Cur = semSubject_Cur -> Next;

                delete Subject_Temp;
        }

        return;
    }

    School_Year::Semester::Subject::Student_listMark* StudentCur = semSubject_Cur -> yearSemesterSubStudent_ListHead;

                if (StudentCur != nullptr) Delete_Element_Of_StudentList(StudentCur,1);

                semSubject_Cur -> yearSemesterSubStudent_ListHead = nullptr;

    return;
}

//Delete Element of Semester
void Delete_Element_Of_Semester(School_Year::Semester* &ySemester_Cur, int type)
{
    if (type == 1)
    {
        while (ySemester_Cur != nullptr)
        {
            School_Year::Semester::Student_listMark* Student_List_Cur = ySemester_Cur -> yearSemesterStudent_listMarkHead;

                if (Student_List_Cur != nullptr) Delete_Element_Of_Student_listMark(Student_List_Cur,1);

                ySemester_Cur -> yearSemesterStudent_listMarkHead = nullptr;

            School_Year::Semester::Subject* Subject_Cur = ySemester_Cur -> yearSemesterSubjectHead;

                if (Subject_Cur != nullptr) Delete_Element_Of_Subject(Subject_Cur,1);
                
                ySemester_Cur -> yearSemesterSubjectHead = nullptr;

            //Delete Every Semester
            School_Year::Semester* ySemester_Temp = ySemester_Cur;

                ySemester_Cur  = ySemester_Cur -> Next;

            delete ySemester_Temp;

        }

        return;
    }

    School_Year::Semester::Student_listMark* Student_List_Cur = ySemester_Cur -> yearSemesterStudent_listMarkHead;

        if (Student_List_Cur != nullptr) Delete_Element_Of_Student_listMark(Student_List_Cur,1);

        ySemester_Cur -> yearSemesterStudent_listMarkHead = nullptr;

    School_Year::Semester::Subject* Subject_Cur = ySemester_Cur -> yearSemesterSubjectHead;

        if (Subject_Cur != nullptr) Delete_Element_Of_Subject(Subject_Cur,1);
        
        ySemester_Cur -> yearSemesterSubjectHead = nullptr;

    return;
}

//Delete Sv_List
void Delete_Element_Of_Sv_List(School_Year::Year_Class::SV_List* &Sv_Cur, int type)
{
    while (Sv_Cur != nullptr)
    {
        School_Year::Year_Class::SV_List* Sv_Temp = Sv_Cur;

        Sv_Cur = Sv_Cur -> Next;

        delete Sv_Temp;
    }
}

//Delete element of year_Class
void Delete_Element_Of_YearClass(School_Year::Year_Class* &yClass_Cur, int type)
{
    if (type == 1)
    {
        while (yClass_Cur != nullptr)
        {
            School_Year::Year_Class::SV_List* Student_Cur = yClass_Cur -> yearClassSV_ListHead;

                if (Student_Cur != nullptr)  Delete_Element_Of_Sv_List(Student_Cur,1);

                yClass_Cur -> yearClassSV_ListHead = nullptr;

            School_Year::Year_Class* yClass_Temp = yClass_Cur;

                yClass_Cur = yClass_Cur -> Next;

                delete  yClass_Temp;

        }
    }
    cout<<"Delete Success";
    return ;
}


//Delete element of year
void Delete_Element_Of_Year(School_Year* &sYear_Cur)
{
    School_Year::Year_Class* Class_Cur = sYear_Cur -> yearCLassHead;

    if (Class_Cur != nullptr) Delete_Element_Of_YearClass(Class_Cur,1);

    sYear_Cur -> yearCLassHead = nullptr;

    School_Year::Semester* Semester_Cur = sYear_Cur -> yearSemesterHead;

    if (Semester_Cur != nullptr) Delete_Element_Of_Semester(Semester_Cur,1);

    sYear_Cur -> yearSemesterHead = nullptr;

    return;
}

void Delete_School_Year(School_Year* &sYear_Head)
{
    while (sYear_Head != nullptr)
    {
        School_Year* temp = sYear_Head ;

        //Delete year Class
        School_Year::Year_Class* Classes_Head = temp -> yearCLassHead;

            while (Classes_Head != nullptr)
            {
                School_Year::Year_Class* temp_Classes = Classes_Head;

                School_Year::Year_Class::SV_List* SV_Head = temp_Classes -> yearClassSV_ListHead;

                    while (SV_Head != nullptr)
                    {
                        School_Year::Year_Class::SV_List* temp_SV = SV_Head;

                        SV_Head = SV_Head -> Next;

                        delete temp_SV;
                    }

                Classes_Head = Classes_Head -> Next;

                delete temp_Classes;
            }

        //Delete year Semester
        School_Year::Semester* Semester_Head = temp -> yearSemesterHead;

            while ( Semester_Head != nullptr)
            {
                School_Year::Semester* Temp_Semester = Semester_Head;

                School_Year::Semester::Subject* Subject_Head = Temp_Semester -> yearSemesterSubjectHead;

                    while ( Subject_Head != nullptr)
                    {
                        School_Year::Semester::Subject* Temp_Sub = Subject_Head;

                        //Delete_Element_Of_StudentList(Temp_Sub -> yearSemesterSubStudent_ListHead,2);

                        Subject_Head = Subject_Head -> Next;

                        delete Temp_Sub;
                    }

                Semester_Head = Semester_Head -> Next;

                delete Temp_Semester;
            }    

        sYear_Head = sYear_Head -> Next;

        delete temp;
    }
}