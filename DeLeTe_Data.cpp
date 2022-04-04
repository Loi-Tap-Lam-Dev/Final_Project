#include "lib.h"

void Delete_Data(Year* &yearHead)
{
    //Delete Year
    Year* year_Cur = yearHead;
        while (year_Cur  != nullptr)
        {
            Year* year_Temp = year_Cur;

            //Delete Year_CLass_Info
            Year::Class* year_Class_Cur = year_Cur -> yearCLassHead;
                while (year_Class_Cur != nullptr)
                {
                    Year::Class* Class_Temmp = year_Class_Cur;

                    //Delete Year_Class_SV_Info
                    Year::Class::SV_List* year_Class_SV_Cur = year_Class_Cur -> yearClassSV_ListHead;
                        while (year_Class_SV_Cur  != nullptr)
                        {
                            Year::Class::SV_List* SV_Temp = year_Class_SV_Cur;

                            year_Class_SV_Cur = year_Class_SV_Cur -> svNext;

                            delete SV_Temp;
                        }

                    year_Class_Cur = year_Class_Cur -> clNext;

                    delete Class_Temmp;
                }

            //Delete Year_Semester
            Year::Semester* Semester_Cur = year_Cur -> yearSemesterHead;
                while(Semester_Cur != nullptr)
                {
                    Year::Semester* Semester_Temp = Semester_Cur;

                    //Sv_Whole_Semester MArk
                    Year::Semester::SV_List* Semester_SV = Semester_Cur -> yearSemesterSv_ListHead;
                        while (Semester_SV != nullptr)
                        {
                            Year::Semester::SV_List* SV_Temp = Semester_SV;

                            Semester_SV = Semester_SV -> svNext;

                            delete SV_Temp;
                        }

                    //Subject
                    Year::Semester::Subject* Semester_Subject_Cur = Semester_Cur -> yearSemesterSubjectHead;
                        while (Semester_Subject_Cur != nullptr)
                        {
                            Year::Semester::Subject* Subject_Temp = Semester_Subject_Cur;

                            //Subject_Class
                            Year::Semester::Subject::Class* Sub_Class = Semester_Subject_Cur -> yearSemesterSubjectClassHead;
                                while (Sub_Class != nullptr)
                                {
                                    Year::Semester::Subject::Class* Class_Temp = Sub_Class;

                                    //Class_Sv_Mark
                                    Year::Semester::Subject::Class::SV_List* Class_Sv = Sub_Class -> yearSemesterSubjectClassSV_ListHead;
                                    while (Class_Sv != nullptr)
                                    {
                                        Year::Semester::Subject::Class::SV_List* SV_Temp = Class_Sv;

                                        Class_Sv = Class_Sv -> svNext;

                                        delete SV_Temp;
                                    }

                                    Sub_Class = Sub_Class -> clNext;
                                    delete Class_Temp;
                                }

                            Semester_Subject_Cur = Semester_Subject_Cur -> subNext;

                            delete Subject_Temp;

                        }

                    Semester_Cur = Semester_Cur -> sNext;

                    delete Semester_Temp;
                }


            year_Cur = year_Cur -> yNext;
            
            delete year_Temp;

        }
    
    cout<<"Delete Success";
    return ;
}

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

//Delete Element of Subject_Class_Student_Mark
void Delete_Element_Of_Sub_StudentList(School_Year::Semester::Subject::Subject_Class::Sub_Student_listMark* &ClassStudent_Cur, int type)
{
    while (ClassStudent_Cur != nullptr)
    {
        School_Year::Semester::Subject::Subject_Class::Sub_Student_listMark* ClassStudent_Temp = ClassStudent_Cur;

            ClassStudent_Cur = ClassStudent_Cur -> Next;

        delete ClassStudent_Temp;
    }
    return;
}

//Delete Element of Subject_Class
void Delete_Element_Of_Subject_Class(School_Year::Semester::Subject::Subject_Class* &SubjectClass_Cur, int type)
{
    if (type == 1)
    {
        while (SubjectClass_Cur != nullptr)
        {
            School_Year::Semester::Subject::Subject_Class::Sub_Student_listMark* Sub_Student_Cur = SubjectClass_Cur -> yearSemesterSubjectClassSub_Student_listMarkHead;

                if (Sub_Student_Cur != nullptr) Delete_Element_Of_Sub_StudentList(Sub_Student_Cur,1);
            
                SubjectClass_Cur -> yearSemesterSubjectClassSub_Student_listMarkHead = nullptr;

            School_Year::Semester::Subject::Subject_Class* Subclass_temp = SubjectClass_Cur;

                SubjectClass_Cur = SubjectClass_Cur -> Next;

            delete Subclass_temp;
        }

        return;
    }

    School_Year::Semester::Subject::Subject_Class::Sub_Student_listMark* Sub_Student_Cur = SubjectClass_Cur -> yearSemesterSubjectClassSub_Student_listMarkHead;

            if (Sub_Student_Cur != nullptr) Delete_Element_Of_Sub_StudentList(Sub_Student_Cur,1);
            
            SubjectClass_Cur -> yearSemesterSubjectClassSub_Student_listMarkHead = nullptr;

    return;
}

//Delete Element of subject
void Delete_Element_Of_Subject(School_Year::Semester::Subject* &semSubject_Cur, int type)
{
    if (type == 1)
    {
        while (semSubject_Cur != nullptr)
        {
            School_Year::Semester::Subject::Subject_Class* subClass_Cur = semSubject_Cur -> yearSemesterSubjectClassHead;

                if (subClass_Cur != nullptr) Delete_Element_Of_Subject_Class(subClass_Cur,1);

                semSubject_Cur -> yearSemesterSubjectClassHead = nullptr;

            School_Year::Semester::Subject* Subject_Temp = semSubject_Cur;

                semSubject_Cur = semSubject_Cur -> Next;

            delete Subject_Temp;
        }

        return;
    }

    School_Year::Semester::Subject::Subject_Class* subClass_Cur = semSubject_Cur -> yearSemesterSubjectClassHead;

        if (subClass_Cur != nullptr) Delete_Element_Of_Subject_Class(subClass_Cur,1);

        semSubject_Cur -> yearSemesterSubjectClassHead = nullptr;

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

        return;
    }

    School_Year::Year_Class::SV_List* Student_Cur = yClass_Cur -> yearClassSV_ListHead;

        if (Student_Cur != nullptr)  Delete_Element_Of_Sv_List(Student_Cur,1);

        yClass_Cur -> yearClassSV_ListHead = nullptr;

    return;
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