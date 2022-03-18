#pragma once
#include "lib.h"

struct Year {

    struct Class {

            struct SV_List {

                    int no , idStudent , socialID;

                    string lastName , firstName , gender , dateOfBirth;

                    SV_List* svNext = nullptr;
            };
        
             SV_List* yearClassSV_ListHead; // To Save The Head Of The SV List of Class

             string nameClass;

             Class* clNext = nullptr;   

    };

     Class* yearCLassHead; // To Save the Head of the Class List of Year

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     
     struct Semester {

             struct SV_List {

                     int no , idStudent , GPA , averageMark;

                     SV_List* svNext = nullptr;
                
             };

             SV_List* yearSemesterSv_ListHead; // To Save the Head of the SV List of the Semester

             struct Subject {

                     string startDate, endDate;

                     int maximumRegrister;

                     struct Class {

                             struct SV_List {

                                int no , idStudent , midTermMark, finalTermMark , otherMark;

                                SV_List* svNext = nullptr;

                             };

                             SV_List* yearSemesterSubjectClassSV_ListHead; // To Save the Head of the SV List of Class

                             string nameClass;

                             Class* clNext = nullptr;

                     };

                     Class* yearSemesterSubjectClassHead; // To Save the Head of the Class List of Subject
                
                     Subject* subNext = nullptr;

             };

             Subject* yearSemesterSubjectHead;  // To Save the Head of the Subject List of Semester

             struct Schedule {

             };


             Semester* sNext = nullptr;

     };

     Semester* yearSemesterHead; // To Save the Head of the Semester List of Year

     string nameYear;

     Year* yNext = nullptr;

};


struct Account
{
        string nameAccount, passWord;
        Account* accNext = nullptr;
};
