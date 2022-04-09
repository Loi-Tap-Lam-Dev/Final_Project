#include "lib.h"

void ReadData(Year*&year_Head)
{
    //Read year
    ifstream readYear;
    readYear.open("Year.csv",ios::in);
    Year*year_Head=new Year();
    Year*year_Cur=year_Head;
    string s;
    getline(readYear,s);
    while(!readYear.eof())
    {
        readYear>>year_Cur->nameYear;
        year_Cur=new Year();
        year_Cur=year_Cur->yNext;
    }


    //Read year_class
    ifstream readYearClass;
    readYearClass.open("Year_Class.csv",ios::in);
    Year::Class*year_Class_Head=new Year::Class();
    Year::Class*year_Class_Cur=year_Class_Head;
    Year::Class::SV_List*year_Class_Sv_Head=new Year::Class::SV_List();
    Year::Class::SV_List*year_Class_Sv_Cur=year_Class_Sv_Head;
    getline(readYearClass,s);
    const char* denim=",";
    char* tmp=strtok(NULL,denim);
    char*stop="";
    while(true)
    {
        char*class_name=strtok(NULL,denim);
        year_Class_Cur->nameClass=class_name;
        year_Class_Cur->clNext=new Year::Class();
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
    getline(readYearClass,s);
    Year::Semester*year_Semester_Head=new Year::Semester();
    Year::Semester*year_Semester_Cur=year_Semester_Head;
    Year::Semester::SV_List*year_Semester_Sv_Head=new Year::Semester::SV_List();
    Year::Semester::SV_List*year_Semester_Sv_Cur=year_Semester_Sv_Head;
    Year::Semester::Subject*year_Semester_Subject_Head=new Year::Semester::Subject();
    Year::Semester::Subject*year_Semester_Subject_Cur=year_Semester_Subject_Head;
    char*tmp=strtok(NULL,denim);
    stop="";
    while(true)
    {
        char*year_semester=strtok(NULL,denim);
        year_Semester_Cur->Term=year_semester;
        char*discard=strtok(NULL,denim);
        discard=strtok(NULL,denim);
        discard=strtok(NULL,denim);
        discard=strtok(NULL,denim);
        discard=strtok(NULL,denim);
        while(stop!="Subject")
        {
        char*No=strtok(NULL,denim);
        char*Id=strtok(NULL,denim);
        char*GPA=strtok(NULL,denim);
        char*AverageMark=strtok(NULL,denim);

        year_Semester_Sv_Cur->no=atoi(No);
        year_Semester_Sv_Cur->idStudent=atoi(Id);
        year_Semester_Sv_Cur->GPA=atoi(GPA);
        year_Semester_Sv_Cur->averageMark=atoi(AverageMark);
        year_Semester_Sv_Cur=year_Semester_Sv_Cur->svNext;
        stop=strtok(NULL,denim);
        }
        discard=strtok(NULL,denim);
        discard=strtok(NULL,denim);
        discard=strtok(NULL,denim);
        discard=strtok(NULL,denim);

        while(stop!="Term")
        {
            char*name_sub=strtok(NULL,denim);
            char*startdate=strtok(NULL,denim);
            char*enddate=strtok(NULL,denim);
            char*maxregister=strtok(NULL,denim);

            year_Semester_Subject_Cur->name_Subject=name_sub;
            year_Semester_Subject_Cur->startDate=startdate;
            year_Semester_Subject_Cur->endDate=enddate;
            year_Semester_Subject_Cur->maximumRegrister=maxregister;

            year_Semester_Subject_Cur=year_Semester_Subject_Cur->subNext;
            stop=strtok(NULL,denim);
        }
    }

    //read year_semester_subject_class
    ifstream readYearSemesterSubjectClass;
    readYearSemesterSubjectClass.open("Year_Semester_Subject_Class",ios::in);
    Year::Semester::Subject::Class*year_Semester_Subject_Class_Head=new Year::Semester::Subject::Class();
    Year::Semester::Subject::Class*year_Semester_Subject_Class_Cur=year_Semester_Subject_Class_Head;
    Year::Semester::Subject::Class::SV_List*year_Semester_Subject_Class_Sv_Head=new Year::Semester::Subject::Class::SV_List();
    Year::Semester::Subject::Class::SV_List*year_Semester_Subject_Class_Sv_Cur=year_Semester_Subject_Class_Sv_Head;
    char*discard=strtok(NULL,denim);
    while(true)
    {
    char*class=strtok(NULL,denim);
    year_Semester_Subject_Class_Cur->nameClass=class;
    discard=strtok(NULL,denim);
    discard=strtok(NULL,denim);
    discard=strtok(NULL,denim);
    discard=strtok(NULL,denim);
    discard=strtok(NULL,denim);
    stop="";
    while(stop!="Class")
    {
        char*No=strtok(NULL,denim);
        char*Id=strtok(NULL,denim);
        char*Mid=strtok(NULL,denim);
        char*Final=strtok(NULL,denim);
        char*Other=strtok(NULL,denim);
        
        year_Semester_Subject_Class_Sv_Cur->no=No;
        year_Semester_Subject_Class_Sv_Cur->idStudent=Id;
        year_Semester_Subject_Class_Sv_Cur->midTermMark=Mid;
        year_Semester_Subject_Class_Sv_Cur->finalTermMark=Final;
        year_Semester_Subject_Class_Sv_Cur->otherMark=Other;
        stop=strtok(NULL,denim);
    }
    year_Semester_Subject_Class_Cur=year_Semester_Subject_Class_Cur->clNext;
    }
}