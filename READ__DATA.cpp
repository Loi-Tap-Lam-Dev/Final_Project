#include "lib.h"

void Readdata(School_Year*&year_Head)
{
    const char*denim=",";
    char*discard;
    char*input;
    char*inputtmp;
    char*check;

    int tmp1=0,tmp2=0,tmp3=0,tmp4=0;

    string s;

    //Read Year
    ifstream readYear;
    readYear.open("Year.csv",ios::in);

    //new
    School_Year*year_head=new School_Year;
    School_Year*year_Cur=year_head;

    getline(readYear,s);
    while(!readYear.eof())
    {
        getline(readYear,s);
        input=new char[s.size()];
        strcpy(input,s.c_str());

        //take years
        char*year=strtok(input,denim);
        year_Cur->year=year;
        year_Cur->Next=new School_Year;
        year_Cur=year_Cur->Next;
    }


    //Read Year Class
    ifstream readYearClass;
    readYearClass.open("Year_Class.csv",ios::in);

    //new
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
        tmp1=0;
        char*class_name=strtok(NULL,denim);
        year_Class_Cur->nameClass=class_name;
        year_Class_Cur->Next=new School_Year::Year_Class;
        year_Class_Cur=year_Class_Cur->Next;

        while(tmp1==0&&!readYearClass.eof())
        {
            tmp2=0;
            getline(readYearClass,s);
            input=new char[s.size()];
            strcpy(input,s.c_str());

            inputtmp=new char[s.size()];
            strcpy(input,s.c_str());

            check=strtok(inputtmp,denim);
            if(check!="Class")
            {
                tmp2++;
            }

            if(tmp2==1)
            {
                char*No=strtok(input,denim);
                char*Student_ID=strtok(NULL,denim);
                char*SocialID=strtok(NULL,denim);
                char*FirstName=strtok(NULL,denim);
                char*LastName=strtok(NULL,denim);
                char*Gender=strtok(NULL,denim);
                char*Dateofbirth=strtok(NULL,denim);


                year_Class_Sv_Cur->no=atoi(No);
                year_Class_Sv_Cur->idStudent=atoi(Student_ID);
                year_Class_Sv_Cur->socialID=atoi(SocialID);
                year_Class_Sv_Cur->firstName=FirstName;
                year_Class_Sv_Cur->lastName=LastName;
                year_Class_Sv_Cur->gender=Gender;
                year_Class_Sv_Cur->dateOfBirth=Dateofbirth;

                year_Class_Sv_Cur->Next=new School_Year::Year_Class::SV_List;
                year_Class_Sv_Cur=year_Class_Sv_Cur->Next;
            }
            else
            {
                discard=strtok(input,denim);
                tmp1++;
            }
        }
        year_Class_Cur->Next=new School_Year::Year_Class;
        year_Class_Cur=year_Class_Cur->Next;
    }

    tmp1=0;
    tmp2=0;

    //Read Year Semester
    ifstream readYearSemester;
    readYearSemester.open("Year_Semester.csv",ios::in);

    //new
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

    getline(readYearSemester,s);
    input=new char[s.size()];
    strcpy(input,s.c_str());
    
    while(!readYearSemester.eof())
    {
        tmp1=0;
        tmp3=0;

        char*year_semester=strtok(input,denim);
        year_Semester_Cur->Term= atoi(year_semester);

        char*start_date=strtok(NULL,denim);
        year_Semester_Cur->start_Date=start_date;

        char*end_date=strtok(NULL,denim);
        year_Semester_Cur->end_Date=end_date;

        getline(readYearSemester,s);
        getline(readYearSemester,s);

        while(tmp1==0)
        {
            tmp2=0;
            getline(readYearSemester,s);
            input=new char[s.size()];
            strcpy(input,s.c_str());

            inputtmp=new char[s.size()];
            strcpy(inputtmp,s.c_str());

            check=strtok(inputtmp,denim);
            if(check!="Subject")
            tmp2++;

            if(tmp2==1)
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
            {
                tmp1++;
            }
        }
        getline(readYearSemester,s);

        while(tmp3==0&&!readYearSemester.eof())
        {
            tmp4=0;

            getline(readYearSemester,s);
            input=new char[s.size()];
            strcpy(input,s.c_str());

            inputtmp=new char[s.size()];
            strcpy(inputtmp,s.c_str());

            check=strtok(inputtmp,denim);
            if(check!="Term")
            tmp4++;

            if(tmp4==1)
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


                year_Semester_Subject_Cur->name_Subject=name_sub;
                year_Semester_Subject_Cur->id_Subject=id_sub;
                year_Semester_Subject_Cur->startDate=startdate;
                year_Semester_Subject_Cur->endDate=enddate;
                year_Semester_Subject_Cur->teacher_Name=teacher_name;
                year_Semester_Subject_Cur->day_Of_Session_1=day_of_session_1;
                year_Semester_Subject_Cur->day_Of_Session_2=day_of_session_2;
                year_Semester_Subject_Cur->at_Time_1=time_1;
                year_Semester_Subject_Cur->at_Time_2=time_2;
                year_Semester_Subject_Cur->maximumRegrister=atoi(maxregister);
                year_Semester_Subject_Cur->number_Of_Credit=atoi(number_credit);

                year_Semester_Subject_Cur->Next=new School_Year::Semester::Subject;
                year_Semester_Subject_Cur=year_Semester_Subject_Cur->Next;       
            }
            else
            {
                tmp3++;
                getline(readYearSemester,s);
                input=new char[s.size()];
                strcpy(input,s.c_str());
            }
        }
        year_Semester_Cur->Next=new School_Year::Semester;
        year_Semester_Cur=year_Semester_Cur->Next;
    }
}