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