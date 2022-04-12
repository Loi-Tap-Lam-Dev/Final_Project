#include "lib.h"

void outInfor(School_Year* yearHead)
{
    ofstream OutData;

    //Year
    OutData.open("Year.csv",ios::out);
    OutData<<"Year"<<endl;
    for(School_Year*yearCur=yearHead;yearCur->Next!=nullptr;yearCur=yearCur->Next)
    {
        OutData<<yearCur->year<<endl;
    }
    OutData.close();

    //Class
    OutData.open("Year_Class.csv",ios::out);
    OutData<<"Class infor "<<endl;
    for(School_Year::Year_Class*year_Class_Cur=yearHead->yearCLassHead;year_Class_Cur->Next!=nullptr;year_Class_Cur=year_Class_Cur->Next)
    {
        OutData<<"Class "+""","""<<year_Class_Cur->nameClass<<endl;
        string tmp=""",""";
        OutData<<"No"+tmp+"Student_ID"+tmp+"SocialID"+tmp+"FirstName"+tmp+"LastName"+tmp+"Gender"+tmp+"Dateofbirth"<<endl;
        for(School_Year::Year_Class::SV_List*year_Class_Sv_Cur=year_Class_Cur->yearClassSV_ListHead;year_Class_Sv_Cur->Next!=nullptr;year_Class_Sv_Cur=year_Class_Sv_Cur->Next)
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
    for(School_Year::Semester*year_Semester_Cur=yearHead->yearSemesterHead;year_Semester_Cur->Next!=nullptr;year_Semester_Cur=year_Semester_Cur->Next)
    {
        string tmp=""",""";
        OutData<<"Term "+tmp+"Start Date"+tmp+"End Date"<<endl;
        OutData<<to_string(year_Semester_Cur->Term)+tmp+year_Semester_Cur->start_Date+tmp+year_Semester_Cur->end_Date<<endl;
        OutData<<"Sv Semester Mark "<<endl;
        OutData<<"No "+tmp+"Id "+tmp+"Credit "+tmp+"GPA "+tmp+"Average Mark "<<endl;
        tmp=""",""";
        for (School_Year::Semester::Student_listMark* year_Semester_SvListCur = year_Semester_Cur->yearSemesterStudent_listMarkHead; year_Semester_SvListCur -> Next != nullptr;year_Semester_SvListCur = year_Semester_SvListCur->Next )
        {
            OutData<<to_string(year_Semester_SvListCur->no)+tmp+to_string(year_Semester_SvListCur->idStudent)+tmp+to_string(year_Semester_SvListCur->GPA)+tmp+to_string(year_Semester_SvListCur->averageMark)<<endl;
        }
        OutData<<endl;
        OutData<<"Subject "<<endl;
        OutData<<"NameSubject"+tmp+"IDSubject"+tmp+"StartDate"+tmp+"EndDate"+tmp+"TeacherName"+tmp+"Day_of_session_1"+tmp+"Day_of_session_2"+tmp+"Time_1"+tmp+"Time_2"+tmp+"MaxRegister"+tmp+"Number_Credit"<<endl;
        for (School_Year::Semester::Subject* year_Semester_Subject_Cur = year_Semester_Cur -> yearSemesterSubjectHead;year_Semester_Subject_Cur -> Next != nullptr; year_Semester_Subject_Cur = year_Semester_Subject_Cur -> Next)
        {
            OutData<<year_Semester_Subject_Cur->name_Subject+tmp+year_Semester_Subject_Cur->id_Subject+tmp+year_Semester_Subject_Cur->startDate+tmp+year_Semester_Subject_Cur->endDate+tmp+year_Semester_Subject_Cur->teacher_Name+tmp+year_Semester_Subject_Cur->day_Of_Session_1+tmp+year_Semester_Subject_Cur->day_Of_Session_2+tmp+year_Semester_Subject_Cur->at_Time_1+tmp+year_Semester_Subject_Cur->at_Time_2+tmp+to_string(year_Semester_Subject_Cur->maximumRegrister)+tmp+to_string(year_Semester_Subject_Cur->number_Of_Credit)<<endl;
        }
    }
    OutData<<endl;
    OutData.close();
    system("pause");
}

//     //Semester Subject
//     OutData.open("Year_Semester_Subject_Class.csv",ios::out);
//     for (Year::Semester* year_Semester_Cur = yearHead -> yearSemesterHead; year_Semester_Cur -> sNext != nullptr; year_Semester_Cur = year_Semester_Cur -> sNext)
//         for (Year::Semester::SV_List* year_Semester_SvListCur = year_Semester_Cur -> yearSemesterSv_ListHead; year_Semester_SvListCur -> svNext != nullptr;year_Semester_SvListCur = year_Semester_SvListCur -> svNext )
//             for (Year::Semester::Subject* year_Semester_Subject_Cur = year_Semester_Cur -> yearSemesterSubjectHead;year_Semester_Subject_Cur -> subNext != nullptr; year_Semester_Subject_Cur = year_Semester_Subject_Cur -> subNext)    
//                 for (Year::Semester::Subject::Class* semester_Class = year_Semester_Subject_Cur -> yearSemesterSubjectClassHead; semester_Class -> clNext != nullptr; semester_Class = semester_Class -> clNext)
//                 {
//                     OutData<<"Class "<<semester_Class->nameClass<<endl;
//                     string tmp=""",""";
//                     OutData<<"No"+tmp+"ID"+tmp+"Mid"+tmp+"Final"+tmp+"Other"<<endl;
//                     for (Year::Semester::Subject::Class::SV_List* Class_Sv_Cur = semester_Class -> yearSemesterSubjectClassSV_ListHead;Class_Sv_Cur -> svNext != nullptr; Class_Sv_Cur = Class_Sv_Cur -> svNext)
//                     {
//                         OutData<<to_string(Class_Sv_Cur->no)+tmp+to_string(Class_Sv_Cur->idStudent)+tmp+to_string(Class_Sv_Cur->midTermMark)+tmp+to_string(Class_Sv_Cur->finalTermMark)+tmp+to_string(Class_Sv_Cur->otherMark)<<endl;
//                     }
//                 }
//     OutData.close();
//     system("pause");
// }

