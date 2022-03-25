#include "lib.h"


//Display Screen
void displayScreen(Year* yearHead)
{
    cout<<"Year "<<yearHead -> nameYear<<": ";
    cout<<endl<<"  ";

    cout<<"Class info"<<endl<<"     ";
    for (Year::Class* year_Class_Cur = yearHead -> yearCLassHead; year_Class_Cur -> clNext != nullptr; year_Class_Cur = year_Class_Cur -> clNext)
    {
        //Class info
        cout<<"Class "<<year_Class_Cur -> nameClass;
        cout<<endl<<"           ";
            for (Year::Class::SV_List* year_Class_Sv_Cur = year_Class_Cur -> yearClassSV_ListHead;
                year_Class_Sv_Cur -> svNext != nullptr; year_Class_Sv_Cur = year_Class_Sv_Cur -> svNext)
                {
                    cout<<year_Class_Sv_Cur -> no<<" "<<year_Class_Sv_Cur -> idStudent<<" "<<year_Class_Sv_Cur -> socialID<<" "<<year_Class_Sv_Cur -> firstName<<" "<<
                    year_Class_Sv_Cur -> lastName<<" "<< year_Class_Sv_Cur -> gender<<" "<<year_Class_Sv_Cur -> dateOfBirth<<endl<<"           ";
                }
        cout<<endl<<"     ";
    }
    cout<<endl<<"  ";

    cout<<"Semester info"<<endl<<"     ";
    for (Year::Semester* year_Semester_Cur = yearHead -> yearSemesterHead; year_Semester_Cur -> sNext != nullptr; year_Semester_Cur = year_Semester_Cur -> sNext)
    {
        //Term
        cout<<"Term "<<year_Semester_Cur -> Term<<endl<<"       ";
        
        //Sv Semester Mark
        cout<<"Sv Semester Mark "<<endl<<"          ";
        for (Year::Semester::SV_List* year_Semester_SvListCur = year_Semester_Cur -> yearSemesterSv_ListHead; year_Semester_SvListCur -> svNext != nullptr;
        year_Semester_SvListCur = year_Semester_SvListCur -> svNext )
        {
            cout<<year_Semester_SvListCur -> no<<" "<<year_Semester_SvListCur -> idStudent<<" "<<year_Semester_SvListCur -> GPA<<" "<<year_Semester_SvListCur -> averageMark<<endl<<"          ";
        }
        cout<<endl<<"       ";

        cout<<"Subject "<<endl<<"          ";
        for (Year::Semester::Subject* year_Semester_Subject_Cur = year_Semester_Cur -> yearSemesterSubjectHead;
        year_Semester_Subject_Cur -> subNext != nullptr; year_Semester_Subject_Cur = year_Semester_Subject_Cur -> subNext)
        {
            //Subject
            cout<<year_Semester_Subject_Cur -> name_Subject<<" - Start date: "<<year_Semester_Subject_Cur -> startDate<<" - End Date: "<<year_Semester_Subject_Cur -> endDate<<" - Maximum: "<<year_Semester_Subject_Cur -> maximumRegrister<<endl<<"          ";
            
            //Class
            for (Year::Semester::Subject::Class* semester_Class = year_Semester_Subject_Cur -> yearSemesterSubjectClassHead; semester_Class -> clNext != nullptr; semester_Class = semester_Class -> clNext)
            {
                cout<<"Class: "<<semester_Class -> nameClass<<endl<<"               ";

                for (Year::Semester::Subject::Class::SV_List* Class_Sv_Cur = semester_Class -> yearSemesterSubjectClassSV_ListHead;
                Class_Sv_Cur -> svNext != nullptr; Class_Sv_Cur = Class_Sv_Cur -> svNext)
                {
                    cout<<"No: "<<Class_Sv_Cur -> no<<" - ID: "<<Class_Sv_Cur -> idStudent<<" - Mid: "<<Class_Sv_Cur -> midTermMark<<" - Final: "<<Class_Sv_Cur -> finalTermMark<<" - Other: "<<Class_Sv_Cur -> otherMark<<endl<<"               ";
                }
                cout<<endl<<"           ";
            }
            cout<<endl<<"          ";
        }
        cout<<endl<<"       ";
    }
    return ;
}


//Display File
void displayFile(Year* yearHead)
{
    //Open
    fout.open("Output.txt", ios::out);

    //Print
    fout<<"Year "<<yearHead -> nameYear<<": ";
    fout<<endl<<"  ";

    fout<<"Class info"<<endl<<"     ";
    for (Year::Class* year_Class_Cur = yearHead -> yearCLassHead; year_Class_Cur -> clNext != nullptr; year_Class_Cur = year_Class_Cur -> clNext)
    {
        //Class info
        fout<<"Class "<<year_Class_Cur -> nameClass;
        fout<<endl<<"           ";
            for (Year::Class::SV_List* year_Class_Sv_Cur = year_Class_Cur -> yearClassSV_ListHead;
                year_Class_Sv_Cur -> svNext != nullptr; year_Class_Sv_Cur = year_Class_Sv_Cur -> svNext)
                {
                    fout<<year_Class_Sv_Cur -> no<<" "<<year_Class_Sv_Cur -> idStudent<<" "<<year_Class_Sv_Cur -> socialID<<" "<<year_Class_Sv_Cur -> firstName<<" "<<
                    year_Class_Sv_Cur -> lastName<<" "<< year_Class_Sv_Cur -> gender<<" "<<year_Class_Sv_Cur -> dateOfBirth<<endl<<"           ";
                }
        fout<<endl<<"     ";
    }
    fout<<endl<<"  ";

    fout<<"Semester info"<<endl<<"     ";
    for (Year::Semester* year_Semester_Cur = yearHead -> yearSemesterHead; year_Semester_Cur -> sNext != nullptr; year_Semester_Cur = year_Semester_Cur -> sNext)
    {
        //Term
        fout<<"Term "<<year_Semester_Cur -> Term<<endl<<"       ";
        
        //Sv Semester Mark
        fout<<"Sv Semester Mark "<<endl<<"          ";
        for (Year::Semester::SV_List* year_Semester_SvListCur = year_Semester_Cur -> yearSemesterSv_ListHead; year_Semester_SvListCur -> svNext != nullptr;
        year_Semester_SvListCur = year_Semester_SvListCur -> svNext )
        {
            fout<<year_Semester_SvListCur -> no<<" "<<year_Semester_SvListCur -> idStudent<<" "<<year_Semester_SvListCur -> GPA<<" "<<year_Semester_SvListCur -> averageMark<<endl<<"          ";
        }
        fout<<endl<<"       ";

        fout<<"Subject "<<endl<<"          ";
        for (Year::Semester::Subject* year_Semester_Subject_Cur = year_Semester_Cur -> yearSemesterSubjectHead;
        year_Semester_Subject_Cur -> subNext != nullptr; year_Semester_Subject_Cur = year_Semester_Subject_Cur -> subNext)
        {
            //Subject
            fout<<year_Semester_Subject_Cur -> id_Subject<<" - "<<year_Semester_Subject_Cur -> name_Subject<<" - Start date: "<<year_Semester_Subject_Cur -> startDate<<" - End Date: "<<year_Semester_Subject_Cur -> endDate<<" - Maximum: "<<year_Semester_Subject_Cur -> maximumRegrister<<endl<<"          ";
            
            //Class
            for (Year::Semester::Subject::Class* semester_Class = year_Semester_Subject_Cur -> yearSemesterSubjectClassHead; semester_Class -> clNext != nullptr; semester_Class = semester_Class -> clNext)
            {
                fout<<"Class: "<<semester_Class -> nameClass<<endl<<"               ";

                for (Year::Semester::Subject::Class::SV_List* Class_Sv_Cur = semester_Class -> yearSemesterSubjectClassSV_ListHead;
                Class_Sv_Cur -> svNext != nullptr; Class_Sv_Cur = Class_Sv_Cur -> svNext)
                {
                    fout<<"No: "<<Class_Sv_Cur -> no<<" - ID: "<<Class_Sv_Cur -> idStudent<<" - Total: "<<Class_Sv_Cur -> finalTermMark<<" - Mid: "<<Class_Sv_Cur -> midTermMark<<" - Final: "<<Class_Sv_Cur -> finalTermMark<<" - Other: "<<Class_Sv_Cur -> otherMark<<endl<<"               ";
                }
                fout<<endl<<"           ";
            }
            fout<<endl<<"          ";
        }
        fout<<endl<<"       ";
    }

    //Close
    fout.close();
    
    return ;
}