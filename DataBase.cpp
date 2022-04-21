#pragma once
#include "lib.h"


//Account
struct Account
{
        string nameAccount, passWord;
        Account* accNext = nullptr;
};

//Database for short term data aka can be reset
struct School_Year {

    string year;

    //Class_Info
    struct Year_Class {

            struct SV_List {

                    int no , idStudent , socialID;

                    string lastName , firstName , gender , dateOfBirth;

                    SV_List* Prev = nullptr;
                    SV_List* Next = nullptr;
            };
        
             SV_List* yearClassSV_ListHead = nullptr; // To Save The Head Of The SV List of Class

             string nameClass;

             Year_Class* Prev = nullptr;
             Year_Class* Next = nullptr;   

    };

     Year_Class* yearCLassHead = nullptr; // To Save the  = nullptr of the Class List of Year

     //Semester   
    struct Semester {

             int Term;
             string start_Date, end_Date;

             struct Student_listMark {

                     int no , idStudent , totalCredit = 0;
                     double GPA = 0, averageMark = 0;
                     string fullName;
                     int count_Course_Attempt = 0; //Dont Print this out (Dung in dong nay)
                     Student_listMark* Prev = nullptr;
                     Student_listMark* Next = nullptr;
                
             };

             Student_listMark* yearSemesterStudent_listMarkHead = nullptr; // To Save the Head of the SV List of the Semester

             struct Subject {

                     string name_Subject, id_Subject;
                     string startDate, endDate;
                     string teacher_Name;
                     string day_Of_Session_1, day_Of_Session_2; // Mon/Tue/Wed
                     string at_Time_1, at_Time_2; //S1(7:30) S2(9:30) S3(13:30) S4(15:30)
                
                     int maximumRegrister = 50, number_Of_Credit = 0;


                      struct Student_listMark {

                        int no , idStudent;
                        double  midTermMark, finalTermMark , otherMark, totalMark;
                        string FullName;

                        Student_listMark* Prev = nullptr;
                        Student_listMark* Next = nullptr;

                       };

                     Student_listMark* yearSemesterSubStudent_ListHead = nullptr;

                     Subject* Prev = nullptr;
                     Subject*  Next = nullptr;

                };

                Subject* yearSemesterSubjectHead = nullptr;  // To Save the Head of the Subject List of Semester

                Semester* Prev = nullptr;
                Semester* Next = nullptr;
     };
    
     Semester* yearSemesterHead = nullptr;

     School_Year* Prev = nullptr;
     School_Year* Next = nullptr;
};