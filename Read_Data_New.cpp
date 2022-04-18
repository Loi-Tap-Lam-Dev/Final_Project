#include "lib.h"
void ReadData(School_Year*&year_Head)
{
    const char* denim=",";
    char*discard;
    char*input;
    //check this push
    
    //Read year
    ifstream readYear;
    readYear.open("Year.csv",ios::in);
    School_Year*year_head=new School_Year;
    School_Year*year_Cur=year_head;
    string s;
    getline(readYear,s);
    while(!readYear.eof())
    {
        getline(readYear,s);
        if (s == "") break;
        input=new char[s.size()];
        strcpy(input,s.c_str());

        //take years
        char*year=strtok(input,denim);
        string Year=string(year);
        year_Cur->year=Year;
        year_Cur->Next=new School_Year;
        year_Cur=year_Cur->Next;
    }


    //Read year_class
    ifstream readYearClass;
    readYearClass.open("Year_Class.csv",ios::in);
    School_Year::Year_Class*year_Class_Head=new School_Year::Year_Class;
    School_Year::Year_Class*year_Class_Cur=year_Class_Head;
    School_Year::Year_Class::SV_List*year_Class_Sv_Head=new School_Year::Year_Class::SV_List;
    School_Year::Year_Class::SV_List*year_Class_Sv_Cur=year_Class_Sv_Head;
    getline(readYearClass,s);
    
    getline(readYearClass,s);
    input=new char[s.size()];
    strcpy(input,s.c_str());
    discard=strtok(input,denim);


    while(!readYearClass.eof())
    {
        string stoptmp="NO";
        char*class_name=strtok(NULL,denim);
        string Class_name=string(class_name);
        year_Class_Cur->nameClass=Class_name;
        year_Class_Cur->Next=new School_Year::Year_Class;
        year_Class_Cur=year_Class_Cur->Next;
        getline(readYearClass,s);
    
        while(stoptmp!="Class")
        {
            getline(readYearClass,s);
            input=new char[s.size()];
            strcpy(input,s.c_str());

            if(string(strtok(input,denim))!="Class")
            {
            char*No=strtok(input,denim);
            char*Student_ID=strtok(NULL,denim);
            char*SocialID=strtok(NULL,denim);
            char*FirstName=strtok(NULL,denim);
            string firstName=string(FirstName);
            char*LastName=strtok(NULL,denim);
            string lastName=string(LastName);
            char*Gender=strtok(NULL,denim);
            string gender=string(gender);
            char*Dateofbirth=strtok(NULL,denim);
            string dateofbirth=string(Dateofbirth);


            year_Class_Sv_Cur->no=atoi(No);
            year_Class_Sv_Cur->idStudent=atoi(Student_ID);
            year_Class_Sv_Cur->socialID=atoi(SocialID);
            year_Class_Sv_Cur->firstName=firstName;
            year_Class_Sv_Cur->lastName=lastName;
            year_Class_Sv_Cur->gender=gender;
            year_Class_Sv_Cur->dateOfBirth=dateofbirth;

            year_Class_Sv_Cur->Next=new School_Year::Year_Class::SV_List;
            year_Class_Sv_Cur=year_Class_Sv_Cur->Next;
            }
            else
            stoptmp=string(strtok(input,denim));
        }
        year_Class_Cur->Next=new School_Year::Year_Class;
        year_Class_Cur=year_Class_Cur->Next;
    }

    //Read year_semester
    ifstream readYearSemester;
    readYearSemester.open("Year_Semester.csv",ios::in);
    getline(readYearSemester,s);

    School_Year::Semester*year_Semester_Head=new School_Year::Semester;
    School_Year::Semester*year_Semester_Cur=year_Semester_Head;
    School_Year::Semester::Student_listMark*year_Semester_Sv_Head=new School_Year::Semester::Student_listMark;
    School_Year::Semester::Student_listMark*year_Semester_Sv_Cur=year_Semester_Sv_Head;
    School_Year::Semester::Subject*year_Semester_Subject_Head=new School_Year::Semester::Subject;
    School_Year::Semester::Subject*year_Semester_Subject_Cur=year_Semester_Subject_Head;
    School_Year::Semester::Subject::Student_listMark*year_Semester_Subject_Student_Head=new School_Year::Semester::Subject::Student_listMark;
    School_Year::Semester::Subject::Student_listMark*year_Semester_Subject_Student_Cur=year_Semester_Subject_Student_Head;
    getline(readYearSemester,s);
    getline(readYearSemester,s);
    input=new char[s.size()];
    strcpy(input,s.c_str());
    while(!readYearSemester.eof())
    {
        
        string stoptmp1="NO";
        string stoptmp2="NO";

        char*year_semester=strtok(input,denim);
        year_Semester_Cur->Term= atoi(year_semester) ;

        char*start_date=strtok(NULL,denim);
        string Start_date=string(start_date);
        year_Semester_Cur->start_Date=Start_date;

        char*end_date=strtok(NULL,denim);
        string End_date=string(end_date);
        year_Semester_Cur->end_Date=End_date;
        getline(readYearSemester,s);
        getline(readYearSemester,s);
        while(stoptmp2!="Subject")
        {
            getline(readYearSemester,s);
            input=new char[s.size()];
            strcpy(input,s.c_str());
            if(string(strtok(input,denim))!="Subject")
            {
        char*No=strtok(input,denim);
        char*Id=strtok(NULL,denim);
        char*Credit=strtok(NULL,denim);
        char*GPA=strtok(NULL,denim);
        char*AverageMark=strtok(NULL,denim);

        year_Semester_Sv_Cur->no=atoi(No);
        year_Semester_Sv_Cur->idStudent=atoi(Id);
        year_Semester_Sv_Cur->totalCredit=atoi(Credit);
        year_Semester_Sv_Cur->GPA=atoi(GPA);
        year_Semester_Sv_Cur->averageMark=atoi(AverageMark);

        year_Semester_Sv_Cur->Next=new School_Year::Semester::Student_listMark;
        year_Semester_Sv_Cur=year_Semester_Sv_Cur->Next;
            }
        else
        stoptmp2="Subject";
        }
        getline(readYearSemester,s);
        while(stoptmp1!="Term")
        {
            getline(readYearSemester,s);
            input=new char[s.size()];
            strcpy(input,s.c_str());
            
            if(string(strtok(input,denim))!="Term")
            {
            char*name_sub=strtok(input,denim);
            char*id_sub=strtok(NULL,denim);
            char*startdate=strtok(NULL,denim);
            char*enddate=strtok(NULL,denim);
            char*teacher_name=strtok(NULL,denim);
            char*day_of_session_1=strtok(NULL,denim);
            char*day_of_session_2=strtok(NULL,denim);
            char*time_1=strtok(NULL,denim);
            char*time_2=strtok(NULL,denim);
            char*maxregister=strtok(NULL,denim);
            char*number_credit=strtok(NULL,denim);

            string Name_sub=string(name_sub);
            string Id_sub=string(id_sub);
            string Startdate=string(start_date);
            string Enddate=string(enddate);
            string Teacher_name=string(teacher_name);
            string Day_of_session_1=string(day_of_session_1);
            string Day_of_session_2=string(day_of_session_2);
            string Time_1=string(time_1);
            string Time_2=string(time_2);

            year_Semester_Subject_Cur->name_Subject=Name_sub;
            year_Semester_Subject_Cur->id_Subject=Id_sub;
            year_Semester_Subject_Cur->startDate=Startdate;
            year_Semester_Subject_Cur->endDate=Enddate;
            year_Semester_Subject_Cur->teacher_Name=Teacher_name;
            year_Semester_Subject_Cur->day_Of_Session_1=Day_of_session_1;
            year_Semester_Subject_Cur->day_Of_Session_2=Day_of_session_2;
            year_Semester_Subject_Cur->at_Time_1=Time_1;
            year_Semester_Subject_Cur->at_Time_2=Time_2;
            year_Semester_Subject_Cur->maximumRegrister=atoi(maxregister);
            year_Semester_Subject_Cur->number_Of_Credit=atoi(number_credit);

            year_Semester_Subject_Cur->Next=new School_Year::Semester::Subject;
            year_Semester_Subject_Cur=year_Semester_Subject_Cur->Next;
            }
            else
            {
                stoptmp1="Term";
                discard=strtok(input,denim);
                discard=strtok(NULL,denim);
                discard=strtok(NULL,denim);
                getline(readYearSemester,s);
                input=new char[s.size()];
                strcpy(input,s.c_str());
            }
        }
        year_Semester_Cur->Next=new School_Year::Semester;
        year_Semester_Cur=year_Semester_Cur->Next;
    }
}