#include "lib.h"

void ReadData(School_Year*&year_Head)
{
    //Read year
    ifstream readYear;
    readYear.open("Year.csv",ios::in);
    School_Year*year_Head=new Year();
    School_Year*year_Cur=year_Head;
    string s;
    getline(readYear,s);
    while(!readYear.eof())
    {
        readYear>>year_Cur->nameYear;
        year_Cur=new School_Year();
        year_Cur=year_Cur->Next;
    }


    //Read year_class
    ifstream readYearClass;
    readYearClass.open("Year_Class.csv",ios::in);
    School_Year::Year_Class*year_Class_Head=new School_Year::Year_Class();
    School_Year::Year_Class*year_Class_Cur=year_Class_Head;
    School_Year::Year_Class::SV_List*year_Class_Sv_Head=new School_Year::Year_Class::SV_List();
    School_Year::Year_Class::SV_List*year_Class_Sv_Cur=year_Class_Sv_Head;
    getline(readYearClass,s);
    const char* denim=",";
    char* tmp=strtok(NULL,denim);
    char*stop="";
    while(!readYearClass.eof())
    {
        char*class_name=strtok(NULL,denim);
        year_Class_Cur->nameClass=class_name;
        year_Class_Cur->clNext=new School_Year::Year_Class();
        //year_Class_Cur=year_Class_Cur->clNext;
        while(stop!="Class")
        {
            char*No=strtok(NULL,denim);
            char*Student_ID=strtok(NULL,denim);
            char*SocialID=strtok(NULL,denim);
            char*FirstName=strtok(NULL,denim);
            char*LastName=strtok(NULL,denim);
            char*Gender=strtok(NULL,denim);
            char*Dateofbirth=strtok(NULL,denim);

            stop=strtok(NULL,denim);

            year_Class_Sv_Cur->no=atoi(No);
            year_Class_Sv_Cur->idStudent=atoi(Student_ID);
            year_Class_Sv_Cur->socialID=atoi(SocialID);
            year_Class_Sv_Cur->firstName=FirstName;
            year_Class_Sv_Cur->lastName=LastName;
            year_Class_Sv_Cur->gender=Gender;
            year_Class_Sv_Cur->dateOfBirth=Dateofbirth;

            year_Class_Sv_Cur=year_Class_Sv_Cur->svNext;
        }
        year_Class_Cur=year_Class_Cur->clNext;
    }

    //Read year_semester
    ifstream readYearSemester;
    readYearSemester.open("Year_Semester.csv",ios::in);
    getline(readYearSemester,s);
    School_Year::Semester*year_Semester_Head=new School_Year::Semester();
    School_Year::Semester*year_Semester_Cur=year_Semester_Head;
    School_Year::Semester::Student_listMark*year_Semester_Sv_Head=new School_Year::Semester::Student_listMark();
    School_Year::Semester::Student_listMark*year_Semester_Sv_Cur=year_Semester_Sv_Head;
    School_Year::Semester::Subject*year_Semester_Subject_Head=new School_Year::Semester::Subject();
    School_Year::Semester::Subject*year_Semester_Subject_Cur=year_Semester_Subject_Head;
    School_Year::Semester::Subject::Student_listMark*year_Semester_Subject_Student_Head=new School_Year::Semester::Subject::Student_listMark();
    School_Year::Semester::Subject::Student_listMark*year_Semester_Subject_Student_Cur=year_Semester_Subject_Student_Head;
    char*tmp=strtok(NULL,denim);
    stop="";
    while(!readYearSemester.eof())
    {
        char*year_semester=strtok(NULL,denim);
        year_Semester_Cur->Term=year_semester;
        char*start_date=strtok(NULL,denim);
        year_Semester_Cur->start_Date=start_date;
        char*end_date=strtok(NULL,denim);
        year_Semester_Cur->end_Date=end_date;
        char*discard=strtok(NULL,denim);
        discard=strtok(NULL,denim);
        discard=strtok(NULL,denim);
        discard=strtok(NULL,denim);
        discard=strtok(NULL,denim);
        discard=strtok(NULL,denim);
        while(stop!="Subject")
        {
        char*No=strtok(NULL,denim);
        char*Id=strtok(NULL,denim);
        char*Credit=strtok(NULL,denim);
        char*GPA=strtok(NULL,denim);
        char*AverageMark=strtok(NULL,denim);

        year_Semester_Sv_Cur->no=atoi(No);
        year_Semester_Sv_Cur->idStudent=atoi(Id);
        year_Semester_Sv_Cur->totalCredit=atoi(Credit);
        year_Semester_Sv_Cur->GPA=atoi(GPA);
        year_Semester_Sv_Cur->averageMark=atoi(AverageMark);
        year_Semester_Sv_Cur=year_Semester_Sv_Cur->Next;
        stop=strtok(NULL,denim);
        }
        discard=strtok(NULL,denim);
        discard=strtok(NULL,denim);
        discard=strtok(NULL,denim);
        discard=strtok(NULL,denim);
        discard=strtok(NULL,denim);
        discard=strtok(NULL,denim);
        discard=strtok(NULL,denim);
        discard=strtok(NULL,denim);
        discard=strtok(NULL,denim);

        while(stop!="Term")
        {
            char*name_sub=strtok(NULL,denim);
            char*id_sub=strtok(NULL,denim);
            char*startdate=strtok(NULL,denim);
            char*enddate=strtok(NULL,denim);
            char*teacher_name=strtok(NULL,denim);
            char*day_of_session_1=strtok(NULL,denim);
            char*day_of_session_2=strtok(NULL,denim);
            char*time_1=strtok(NULL,denim);
            char*time_2=strtok(NULL,denim);
            int*maxregister=strtok(NULL,denim);
            int*number_credit=strtko(NULL,denim);

            year_Semester_Subject_Cur->name_Subject=name_sub;
            year_Semester_Subject_Cur->id_Subject=id_sub;
            year_Semester_Subject_Cur->startDate=startdate;
            year_Semester_Subject_Cur->endDate=enddate;
            year_Semester_Subject_Cur->teacher_Name=teacher_name;
            year_Semester_Subject_Cur->day_Of_Session_1=day_of_session_1;
            year_Semester_Subject_Cur->day_Of_Session_2=day_of_session_2;
            year_Semester_Subject_Cur->at_Time_1=time_1;
            year_Semester_Subject_Cur->at_Time_2=time_2;
            year_Semester_Subject_Cur->maximumRegrister=maxregister;
            year_Semester_Subject_Cur->number_Of_Credit=number_credit;

            year_Semester_Subject_Cur=year_Semester_Subject_Cur->subNext;
            stop=strtok(NULL,denim);
        }
    }
// //------------------------------------------
//     //read year_semester_subject_class
//     ifstream readYearSemesterSubjectClass;
//     readYearSemesterSubjectClass.open("Year_Semester_Subject_Class",ios::in);
//     School_Year::Semester::Subject::Student_listMark*year_Semester_Subject_Class_Head=new School_Year::Semester::Subject::Student_listMark();
//     School_Year::Semester::Subject::Student_listMark*year_Semester_Subject_Class_Cur=year_Semester_Subject_Class_Head;
//     Year::Semester::Subject::Class::SV_List*year_Semester_Subject_Class_Sv_Head=new Year::Semester::Subject::Class::SV_List();
//     Year::Semester::Subject::Class::SV_List*year_Semester_Subject_Class_Sv_Cur=year_Semester_Subject_Class_Sv_Head;
//     char*discard=strtok(NULL,denim);
//     while(true)
//     {
//     char*class=strtok(NULL,denim);
//     year_Semester_Subject_Class_Cur->nameClass=class;
//     discard=strtok(NULL,denim);
//     discard=strtok(NULL,denim);
//     discard=strtok(NULL,denim);
//     discard=strtok(NULL,denim);
//     discard=strtok(NULL,denim);
//     stop="";
//     while(stop!="Class")
//     {
//         char*No=strtok(NULL,denim);
//         char*Id=strtok(NULL,denim);
//         char*Mid=strtok(NULL,denim);
//         char*Final=strtok(NULL,denim);
//         char*Other=strtok(NULL,denim);
        
//         year_Semester_Subject_Class_Sv_Cur->no=No;
//         year_Semester_Subject_Class_Sv_Cur->idStudent=Id;
//         year_Semester_Subject_Class_Sv_Cur->midTermMark=Mid;
//         year_Semester_Subject_Class_Sv_Cur->finalTermMark=Final;
//         year_Semester_Subject_Class_Sv_Cur->otherMark=Other;
//         stop=strtok(NULL,denim);
//     }
//     year_Semester_Subject_Class_Cur=year_Semester_Subject_Class_Cur->clNext;
//     }
// }