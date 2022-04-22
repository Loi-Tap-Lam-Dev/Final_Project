#include "lib.h"

void PrintData(School_Year*yearHead)
{
    ofstream PrintYear,PrintYearClass,PrintYearSemester;
    string tmp=""",""";

    //-----------------
    PrintYear.open("Year.csv",ios::out);
    PrintYear<<"Year"<<endl;
    for(School_Year*year_cur=yearHead;year_cur!=nullptr;year_cur=year_cur->Next)
    {
        if(year_cur->Next==nullptr)
        PrintYear<<year_cur->year;
        else
        PrintYear<<year_cur->year<<endl;
    }
    PrintYear.close();

    //-----------------
    PrintYearClass.open("Year_Class.csv",ios::out);
    for(School_Year*year_cur=yearHead;year_cur!=nullptr;year_cur=year_cur->Next)
    {
        PrintYearClass<<"Classes For Year"+tmp+year_cur->year<<endl;
        for(School_Year::Year_Class*year_class_cur=yearHead->yearCLassHead;year_class_cur!=nullptr;year_class_cur=year_class_cur->Next)
        {
            PrintYearClass<<"Class"+tmp+year_class_cur->nameClass<<endl;
            PrintYearClass<<"No"+tmp+" Student_ID"+tmp+" SocialID"+tmp+" FirstName"+tmp+" LastName"+tmp+" Gender"+tmp+" Dateofbirth"<<endl;
            for(School_Year::Year_Class::SV_List*year_class_sv_cur=year_class_cur->yearClassSV_ListHead;year_class_sv_cur!=nullptr;year_class_sv_cur=year_class_sv_cur->Next)
            {
                if(year_class_sv_cur->Next==nullptr)
                PrintYearClass<<to_string(year_class_sv_cur->no)+tmp+to_string(year_class_sv_cur->idStudent)+tmp+to_string(year_class_sv_cur->socialID)+tmp+year_class_sv_cur->firstName+tmp+year_class_sv_cur->lastName+tmp+year_class_sv_cur->gender+tmp+year_class_sv_cur->dateOfBirth;
                else
                PrintYearClass<<to_string(year_class_sv_cur->no)+tmp+to_string(year_class_sv_cur->idStudent)+tmp+to_string(year_class_sv_cur->socialID)+tmp+year_class_sv_cur->firstName+tmp+year_class_sv_cur->lastName+tmp+year_class_sv_cur->gender+tmp+year_class_sv_cur->dateOfBirth<<endl;
            }
        }
    }
    PrintYearClass.close();
    
    //-----------------
    PrintYearSemester.open("Year_Semester.csv",ios::out);
    for(School_Year*year_cur=yearHead;year_cur!=nullptr;year_cur=year_cur->Next)
    {
        PrintYearSemester<<"Semester For Year"+tmp+year_cur->year+tmp<<endl;
        for(School_Year::Semester*year_semester_cur=yearHead->yearSemesterHead;year_semester_cur!=nullptr;year_semester_cur=year_semester_cur->Next)
        {
            PrintYearSemester<<"Semester info"+tmp+"Term"+tmp+" Start Date"+tmp+" End Date"+tmp<<endl;
            PrintYearSemester<<to_string(year_semester_cur->Term)+tmp+year_semester_cur->start_Date+tmp+year_semester_cur->end_Date+tmp<<endl;
            PrintYearSemester<<"Sv_Semester_Mark"+tmp+"No"+tmp+"Id"+tmp+"Fullname"+tmp+"Total Credit"+tmp+"GPA"+tmp+"Average Mark"+tmp<<endl;
            for(School_Year::Semester::Student_listMark*year_semester_stu_cur=year_semester_cur->yearSemesterStudent_listMarkHead;year_semester_stu_cur!=nullptr;year_semester_stu_cur=year_semester_stu_cur->Next)
            {
                PrintYearSemester<<to_string(year_semester_stu_cur->no)+tmp+to_string(year_semester_stu_cur->idStudent)+tmp+year_semester_stu_cur->fullName+tmp+to_string(year_semester_stu_cur->totalCredit)+tmp+to_string(year_semester_stu_cur->GPA)+tmp+to_string(year_semester_stu_cur->averageMark)+tmp<<endl;
            }
            PrintYearSemester<<"Subject"+tmp+"NameSubject"+tmp+" IDSubject"+tmp+" StartDate"+tmp+" EndDate"+tmp+" TeacherName"+tmp+" Day_of_session_1"+tmp+" Time_Day_1"+tmp+" Day_of_session_2"+tmp+" Time_Day_2"+tmp+" Number_Credit"+tmp+"MaxRegister"+tmp<<endl;
            for(School_Year::Semester::Subject*year_semester_sub_cur=year_semester_cur->yearSemesterSubjectHead;year_semester_sub_cur!=nullptr;year_semester_sub_cur=year_semester_sub_cur->Next)
            {
                PrintYearSemester<<year_semester_sub_cur->name_Subject+tmp+year_semester_sub_cur->id_Subject+tmp+year_semester_sub_cur->startDate+tmp+year_semester_sub_cur->endDate+tmp+year_semester_sub_cur->teacher_Name+tmp+year_semester_sub_cur->day_Of_Session_1+tmp+year_semester_sub_cur->at_Time_1+tmp+year_semester_sub_cur->day_Of_Session_2+tmp+year_semester_sub_cur->at_Time_2+tmp+to_string(year_semester_sub_cur->number_Of_Credit)+tmp+to_string(year_semester_sub_cur->maximumRegrister)+tmp<<endl;
                PrintYearSemester<<"Subject_Mark"+tmp+"no"+tmp+"idStudent"+tmp+"Fullname"+tmp+"midTerm"+tmp+"finalTerm"+tmp+"other"+tmp+"total"+tmp<<endl;
                for(School_Year::Semester::Subject::Student_listMark*year_semester_sub_stu_cur=year_semester_sub_cur->yearSemesterSubStudent_ListHead;year_semester_sub_stu_cur!=nullptr;year_semester_sub_stu_cur=year_semester_sub_stu_cur->Next)
                {
                    if(year_cur->Next==nullptr)
                    PrintYearSemester<<to_string(year_semester_sub_stu_cur->no)+tmp+to_string(year_semester_sub_stu_cur->idStudent)+tmp+year_semester_sub_stu_cur->FullName+tmp+to_string(year_semester_sub_stu_cur->midTermMark)+tmp+to_string(year_semester_sub_stu_cur->finalTermMark)+tmp+to_string(year_semester_sub_stu_cur->otherMark)+tmp+to_string(year_semester_sub_stu_cur->totalMark)+tmp;
                    else
                    PrintYearSemester<<to_string(year_semester_sub_stu_cur->no)+tmp+to_string(year_semester_sub_stu_cur->idStudent)+tmp+year_semester_sub_stu_cur->FullName+tmp+to_string(year_semester_sub_stu_cur->midTermMark)+tmp+to_string(year_semester_sub_stu_cur->finalTermMark)+tmp+to_string(year_semester_sub_stu_cur->otherMark)+tmp+to_string(year_semester_sub_stu_cur->totalMark)+tmp<<endl;
                }
            }
        }
    }
    PrintYearSemester.close();
    system("pause");
}