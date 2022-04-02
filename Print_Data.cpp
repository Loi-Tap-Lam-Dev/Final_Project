#include "lib.h"

void outInfor(Year* yearHead)
{
    ofstream OutData;

    //Year
    OutData.open("Year.csv",ios::out);
    OutData<<"Year"<<endl;
    for(Year*yearCur=yearHead;yearCur->yNext!=nullptr;yearCur=yearCur->yNext)
    {
        OutData<<yearCur->nameYear<<endl;
    }
    OutData.close();

    //Class
    OutData.open("Year_Class.csv",ios::out);
    OutData<<"Class infor "<<endl;
    for(Year::Class*year_Class_Cur=yearHead->yearCLassHead;year_Class_Cur->clNext!=nullptr;year_Class_Cur=year_Class_Cur->clNext)
    {
        OutData<<"Class "<<year_Class_Cur->nameClass<<endl;
        string tmp=""",""";
        for(Year::Class::SV_List*year_Class_Sv_Cur=year_Class_Cur->yearClassSV_ListHead;year_Class_Sv_Cur->svNext!=nullptr;year_Class_Sv_Cur=year_Class_Sv_Cur->svNext)
        {
            OutData<<to_string(year_Class_Sv_Cur->no)+tmp+to_string(year_Class_Sv_Cur->idStudent)+tmp+to_string(year_Class_Sv_Cur->socialID)+tmp+(year_Class_Sv_Cur->firstName)+tmp+year_Class_Sv_Cur->lastName+tmp+year_Class_Sv_Cur->gender+tmp+year_Class_Sv_Cur->dateOfBirth<<endl;
        }
        OutData<<endl;
    }
    OutData.close();

    //Semester
    OutData<<endl<<endl;
    OutData.open("Year_Semester.csv",ios::out);
    OutData<<"Semester info"<<endl;
    for(Year::Semester*year_Semester_Cur=yearHead->yearSemesterHead;year_Semester_Cur->sNext!=nullptr;year_Semester_Cur=year_Semester_Cur->sNext)
    {
        OutData<<"Term "<<year_Semester_Cur->Term<<endl;
        OutData<<"Sv Semester Mark "<<endl;
        string tmp=""",""";
        for (Year::Semester::SV_List* year_Semester_SvListCur = year_Semester_Cur -> yearSemesterSv_ListHead; year_Semester_SvListCur -> svNext != nullptr;year_Semester_SvListCur = year_Semester_SvListCur -> svNext )
        {
            OutData<<to_string(year_Semester_SvListCur->no)+tmp+to_string(year_Semester_SvListCur->idStudent)+tmp+to_string(year_Semester_SvListCur->GPA)+tmp+to_string(year_Semester_SvListCur->averageMark)<<endl;
        }
        OutData<<endl;
        OutData<<"Subject "<<endl;
        OutData<<"NameSubject"<<tmp<<"Start date"<<tmp<<"End date"<<tmp<<"Maximum"<<endl;
        for (Year::Semester::Subject* year_Semester_Subject_Cur = year_Semester_Cur -> yearSemesterSubjectHead;year_Semester_Subject_Cur -> subNext != nullptr; year_Semester_Subject_Cur = year_Semester_Subject_Cur -> subNext)
        {
            OutData<<year_Semester_Subject_Cur->name_Subject+tmp+year_Semester_Subject_Cur->startDate+tmp+year_Semester_Subject_Cur->endDate+tmp+to_string(year_Semester_Subject_Cur->maximumRegrister)<<endl;
        }
    }
    OutData<<endl;
    OutData.close();

    //Semester Subject
    OutData.open("Year_Semester_Subject_Class.csv",ios::out);
    for (Year::Semester* year_Semester_Cur = yearHead -> yearSemesterHead; year_Semester_Cur -> sNext != nullptr; year_Semester_Cur = year_Semester_Cur -> sNext)
        for (Year::Semester::SV_List* year_Semester_SvListCur = year_Semester_Cur -> yearSemesterSv_ListHead; year_Semester_SvListCur -> svNext != nullptr;year_Semester_SvListCur = year_Semester_SvListCur -> svNext )
            for (Year::Semester::Subject* year_Semester_Subject_Cur = year_Semester_Cur -> yearSemesterSubjectHead;year_Semester_Subject_Cur -> subNext != nullptr; year_Semester_Subject_Cur = year_Semester_Subject_Cur -> subNext)    
                for (Year::Semester::Subject::Class* semester_Class = year_Semester_Subject_Cur -> yearSemesterSubjectClassHead; semester_Class -> clNext != nullptr; semester_Class = semester_Class -> clNext)
                {
                    OutData<<"Class "<<semester_Class->nameClass<<endl;
                    string tmp=""",""";
                    OutData<<"No"+tmp+"ID"+tmp+"Mid"+tmp+"Final"+tmp+"Other"<<endl;
                    for (Year::Semester::Subject::Class::SV_List* Class_Sv_Cur = semester_Class -> yearSemesterSubjectClassSV_ListHead;Class_Sv_Cur -> svNext != nullptr; Class_Sv_Cur = Class_Sv_Cur -> svNext)
                    {
                        OutData<<to_string(Class_Sv_Cur->no)+tmp+to_string(Class_Sv_Cur->idStudent)+tmp+to_string(Class_Sv_Cur->midTermMark)+tmp+to_string(Class_Sv_Cur->finalTermMark)+tmp+to_string(Class_Sv_Cur->otherMark)<<endl;
                    }
                }
    OutData.close();
    system("pause");
}
