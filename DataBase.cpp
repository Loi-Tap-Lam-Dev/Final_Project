#pragma once
#include "lib.h"


//Database to store longtime data, cant be reset only updated
struct Year {

    struct Class {

            struct SV_List {

                    int no , idStudent , socialID;

                    string lastName , firstName , gender , dateOfBirth;

                    SV_List* svNext = nullptr;
            };
        
             SV_List* yearClassSV_ListHead = nullptr; // To Save The Head Of The SV List of Class

             string nameClass;

             Class* clNext = nullptr;   

    };

     Class* yearCLassHead = nullptr; // To Save the  = nullptr of the Class List of Year

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     
     struct Semester {

             int Term;

             struct SV_List {

                     int no , idStudent , GPA , averageMark;

                     SV_List* svNext = nullptr;
                
             };

             SV_List* yearSemesterSv_ListHead = nullptr; // To Save the Head of the SV List of the Semester

             struct Subject {

                     string name_Subject, id_Subject;
                     string startDate, endDate;
                
                     int maximumRegrister;

                     struct Class {

                             struct SV_List {

                                int no , idStudent , midTermMark, finalTermMark , otherMark, totalMark;

                                SV_List* svNext = nullptr;

                             };

                             SV_List* yearSemesterSubjectClassSV_ListHead = nullptr; // To Save the Head of the SV List of Class

                             string nameClass;

                             Class* clNext = nullptr;

                     };

                     Class* yearSemesterSubjectClassHead = nullptr; // To Save the Head of the Class List of Subject
                
                     Subject* subNext = nullptr;

             };

             Subject* yearSemesterSubjectHead = nullptr;  // To Save the Head of the Subject List of Semester

             struct Schedule {

             };


             Semester* sNext = nullptr;

     };

     Semester* yearSemesterHead = nullptr; // To Save the Head of the Semester List of Year

     string nameYear;

     Year* yNext = nullptr;

};

//Account
struct Account
{
        string nameAccount, passWord;
        Account* accNext = nullptr;
};

//Database for short term data aka can be reset
struct School_Year {

    string year;

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

     School_Year* Prev = nullptr;

     School_Year* Next = nullptr;
};