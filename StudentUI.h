#pragma once

#include <iostream>

#include "lib.h"

using namespace std;

void ClassListMenu(School_Year *sYear_Head) {
startWindow:
    system("CLS");

    cout << "Displaying available classes:\n";

    if (sYear_Head == NULL) {
        cout << "No class available!\n";
        system("pause");

        return;
    }
    
    School_Year *currentYear = sYear_Head;
    School_Year::Year_Class *currentClass = currentYear->yearCLassHead;
    
    cout << "|  ";
    while (currentYear != NULL) {
        currentClass = currentYear->yearCLassHead;
        while (currentClass != NULL) {
            cout << currentClass->nameClass << "  |  ";
            currentClass = currentClass->Next;
        }

        cout << endl;
        currentYear = currentYear->Next;
    }

    currentYear = sYear_Head;

    // New display window
    int choice;
    cout << "\t\tAvailable operations:\n";
    cout << "\t\t   1: View student list in class\n";
    cout << "\t\t   2: Give up and quit\n\n";
    cout << "Your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            string findClass;
            School_Year::Year_Class *targetClassHead = NULL;

            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Enter class to view from: ";
            getline(cin, findClass);

            currentYear = sYear_Head;
            currentClass = currentYear->yearCLassHead;

            while (currentYear != NULL) {
                currentClass = currentYear->yearCLassHead;

                targetClassHead = find_Classes(currentClass, findClass);

                if (targetClassHead != NULL) break;

                currentYear = currentYear->Next;
            }

            if (targetClassHead == NULL) {
                cout << "No class found!\n";
                system("pause");
                
                goto startWindow;
            }

            Show_Sv_Table(findClass, targetClassHead->yearClassSV_ListHead);
            
            system("pause");

            goto startWindow;
        }
        
        case 2: {
            cout << "Good choice!\n";
            system("pause");
            break;
        }
        
        default: 
            goto startWindow;
    }
}

void CourseListMenu(School_Year *sYear_Head) {
startCourseMenu:
    system("CLS");

    if (sYear_Head == NULL ||  sYear_Head->yearSemesterHead == NULL || sYear_Head->yearSemesterHead->yearSemesterSubjectHead == NULL) {
        cout << "No course available!\n";
        system("pause");

        return;
    }

    School_Year *currentYear = sYear_Head;
    School_Year::Semester *currentSemester = currentYear->yearSemesterHead;

    cout << "Displaying all available courses:\n";

    while (currentYear != NULL) {
        cout << "Year: " << currentYear->year << endl;

        while (currentSemester != NULL) {
            Show_Subject_Table(to_string(currentSemester->Term), currentSemester->yearSemesterSubjectHead);
            currentSemester = currentSemester->Next;
        }

        currentYear = currentYear->Next;
    }

    currentYear = sYear_Head;

    // Course menu will go here
    int choice;
    cout << "\t\tAvailable operations:\n";
    cout << "\t\t   1: View student list in a course\n";
    cout << "\t\t   2: View my courses\n";
    cout << "\t\t   3: View scoreboard\n";
    cout << "\t\t   4: Give up and quit\n\n";
    cout << "Your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            string findCourseID;

            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Enter course ID to view from: ";
            getline(cin, findCourseID);

            // Find the course
            School_Year::Semester *findSemester;
            School_Year::Semester::Subject *findCourse;

            bool courseFound = false;
            while (currentYear != NULL) {
                findSemester = currentYear->yearSemesterHead;

                while (findSemester != NULL) {
                    findCourse = findSemester->yearSemesterSubjectHead;

                    while (findCourse != NULL) {
                        if (findCourse->id_Subject == findCourseID) {
                            Show_ScoreBoard(findCourse->yearSemesterSubStudent_ListHead);
                            courseFound = true;

                            break;
                        }

                        findCourse = findCourse->Next;
                    }

                    findSemester = findSemester->Next;
                }

                if (courseFound) break;

                currentYear = currentYear->Next;
            }

            system("pause");

            goto startCourseMenu;
        }

        case 2: {
            string findStudentID;

            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Enter your ID: ";
            getline(cin, findStudentID);

            // Find the course
            School_Year::Semester *findSemester;
            School_Year::Semester::Subject *findCourse;
            School_Year::Semester::Subject::Student_listMark *findStudent;

            // Reuses the function Show_Subject_Table from Model_Menu.cpp
            cout<<"| Course ID\t| Course Name\t| Teacher Name\t\t| Start Date\t| End Date\t| Session 1\t| Time\t\t| Session 2\t| Time\t\t| Number of credits\t| Maximum Student|"<<endl;
            while (currentYear != NULL) {
                findSemester = currentYear->yearSemesterHead;

                while (findSemester != NULL) {
                    findCourse = findSemester->yearSemesterSubjectHead;

                    while (findCourse != NULL) {
                        findStudent = findCourse->yearSemesterSubStudent_ListHead;

                        while (findStudent != NULL) {
                            if (findStudent->idStudent == stoi(findStudentID)) {
                                
                                cout<<"| "<<findCourse -> id_Subject<<"\t\t| "<<findCourse -> name_Subject<<"\t\t| ";

                                //Teacher Name
                                if ((findCourse -> teacher_Name).size() > 14) cout<<findCourse -> teacher_Name<<"\t| ";
                                else cout<<findCourse -> teacher_Name<<"\t\t| ";
                                
                                //Start date, Endate
                                cout<<findCourse -> startDate<<"\t| "<<findCourse -> endDate<<"\t| "<<findCourse -> day_Of_Session_1<<"\t\t| ";

                                if (findCourse -> at_Time_1 == "S3" ) cout<<"13:30 - 15:29\t| ";
                                if (findCourse -> at_Time_1 == "S4" ) cout<<"15:30 - 17:29\t| ";
                                if (findCourse -> at_Time_1 == "S1" ) cout<<"7:30 - 9:29\t| ";
                                if (findCourse -> at_Time_1 == "S2" ) cout<<"9:30 - 11:29\t| ";

                                cout<<findCourse -> day_Of_Session_2<<"\t\t| ";

                                if (findCourse -> at_Time_2 == "S3" ) cout<<"13:30 - 15:29\t| ";
                                if (findCourse -> at_Time_2 == "S4" ) cout<<"15:30 - 17:29\t| ";
                                if (findCourse -> at_Time_2 == "S1" ) cout<<"7:30 - 9:29\t| ";
                                if (findCourse -> at_Time_2 == "S2" ) cout<<"9:30 - 11:29\t| ";

                                cout<<findCourse -> number_Of_Credit<<"\t\t\t| "<<findCourse -> maximumRegrister<<" \t\t|"<<endl;
                            }

                            findStudent = findStudent->Next;
                        }

                        findCourse = findCourse->Next;
                    }

                    findSemester = findSemester->Next;
                }

                currentYear = currentYear->Next;
            }

            system("pause");

            goto startCourseMenu;
        }

        case 3: {
            forStudent_ToView_ScoreBoard_Of_A_Semester(sYear_Head);
            
            system("pause");

            goto startCourseMenu;
        }
        
        case 4: {
            cout << "Good choice!\n";
            system("pause");
            break;
        }
        
        default: 
            goto startCourseMenu;
    }
}

void PrintProfile(Profile loginProfile) {
    cout << "Your profile:\n";

    cout << "Student ID: " << loginProfile.studentID << endl;
    cout << "Full name: " << loginProfile.firstName << " " << loginProfile.lastName << endl;
    cout << "Gender: " << loginProfile.gender << endl;
    cout << "Date of Birth (DoB): " << loginProfile.DoB << endl;
    cout << "Social ID: " << loginProfile.socialID << endl;

    system("pause");
}

void PrintMainStudentMenu(School_Year *&sYear_Head, string loginUsername, Profile loginProfile)
{
startMainMenu:
    int user_Choose = 0;
    
    system("CLS");
    if (sYear_Head != nullptr)
    {
        Show_Year_Table(sYear_Head);
    }

    cout<<"         Wellcome to course registration (Beta Ver)"<<endl;
    cout<<"             1: View class"<<endl;
    cout<<"             2: View courses"<<endl;
    cout<<"             3: Change password"<<endl;
    cout<<"             4: View profile"<<endl;
    cout<<"             5: Log out"<<endl;
    cout<<"             Your choice: "; 
    cin>>user_Choose;
    cout<<endl;

    //Better use switch
    switch (user_Choose)  {
        case 1: {
            ClassListMenu(sYear_Head);
            goto startMainMenu;
        }

        case 2: {
            CourseListMenu(sYear_Head);
            goto startMainMenu;
        }

        case 3: {
            string newPass, retypePass;
            cout << "\nEnter new password: ";
            newPass = encryptPasswordInput();
            cout << "Retype: ";
            retypePass = encryptPasswordInput();

            while (!requestPassword(newPass, retypePass)) {
                cout << "Please re-enter!\n";
                cout << "Enter new password: ";
                newPass = encryptPasswordInput();
                cout << "Retype new password: ";
                retypePass = encryptPasswordInput();
            }

            changePassword(loginUsername, newPass, 2);

            goto startMainMenu;
        }

        case 4: {
            PrintProfile(loginProfile);
            
            goto startMainMenu;
        }

        case 5: {
            cout << "Logging out...\n";
            break;
        }

        default: 
            goto startMainMenu;
    }

    system("pause");

    return ;
}