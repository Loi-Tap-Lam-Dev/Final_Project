#pragma once

#include <iostream>

#include "..\Lib\lib.h"

using namespace std;

void ClassListMenu(School_Year *sYear_Head) {
startWindow:
    system("CLS");
    
    Down_3_Line();
    Down_2_Line();
    Space_7_Tab(); cout << "Displaying available classes:\n";

    Space_9_Tab();
    Heading();
    if (sYear_Head == NULL) {
        
        Space_7_Tab(); cout << "No class available!\n";
        Space_7_Tab(); system("pause");

        return;
    }
    
    School_Year *currentYear = sYear_Head;
    School_Year::Year_Class *currentClass = currentYear->yearCLassHead;
    
    Space_7_Tab(); cout << "|  ";
    while (currentYear != NULL) {
        currentClass = currentYear->yearCLassHead;
        while (currentClass != NULL) {
            cout << currentClass->nameClass << "  |  ";
            currentClass = currentClass->Next;
        }

        cout << endl;
        currentYear = currentYear->Next;
    }
    Endding();
    currentYear = sYear_Head;

    // New display window
    int choice;
    Space_9_Tab(); cout << "\t\tAvailable operations:\n";
    Space_9_Tab(); cout << "\t\t   1: View student list in class\n";
    Space_9_Tab(); cout << "\t\t   2: Give up and quit\n\n";
    Space_11_Tab(); cout << "Your choice: ";
    cin >> choice;
    
    switch (choice) {
        case 1: {
            string findClass;
            School_Year::Year_Class *targetClassHead = NULL;

            cin.clear();
            cin.ignore(1000, '\n');
            cout<<endl;
            Space_9_Tab(); cout << "Enter class to view from: ";
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
                Space_9_Tab(); cout << "No class found!\n";
                Space_9_Tab(); system("pause");
                
                goto startWindow;
            }

            Show_Sv_Table(findClass, targetClassHead->yearClassSV_ListHead);
            
            Space_9_Tab(); system("pause");

            goto startWindow;
        }
        
        case 2: {
            cout<<endl;
            Space_9_Tab(); cout << "Good choice!\n";
            Space_9_Tab(); system("pause");
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
        Space_9_Tab(); cout << "No course available!\n";
        Space_9_Tab(); system("pause");

        return;
    }

    School_Year *currentYear = sYear_Head;
    School_Year::Semester *currentSemester = currentYear->yearSemesterHead;

    Down_3_Line();
    Space_9_Tab(); cout << "Displaying all available courses:\n";

    while (currentYear != NULL) {
        Space_9_Tab(); cout << "Year: " << currentYear->year << endl;

        while (currentSemester != NULL) {
            Show_Subject_Table(to_string(currentSemester->Term), currentSemester->yearSemesterSubjectHead);
            currentSemester = currentSemester->Next;
        }

        currentYear = currentYear->Next;
    }

    currentYear = sYear_Head;

    // Course menu will go here
    int choice;
    Space_9_Tab(); cout << "\t\tAvailable operations:\n";
    Space_9_Tab(); cout << "\t\t   1: View student list in a course\n";
    Space_9_Tab(); cout << "\t\t   2: View my courses\n";
    Space_9_Tab(); cout << "\t\t   3: View scoreboard\n";
    Space_9_Tab(); cout << "\t\t   4: Give up and quit\n\n";
    Space_9_Tab(); cout << "Your choice: ";
    cin >> choice;

    cout<<endl;
    switch (choice) {
        case 1: {
            string findCourseID;

            cin.clear();
            cin.ignore(1000, '\n');
            Space_11_Tab(); cout << "Enter course ID to view from: ";
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

            Space_9_Tab(); system("pause");

            goto startCourseMenu;
        }

        case 2: {
            string findStudentID;

            cin.clear();
            cin.ignore(1000, '\n');
            Space_11_Tab(); cout << "Enter your ID: ";
            getline(cin, findStudentID);

            cout<<endl;
            // Find the course
            School_Year::Semester *findSemester;
            School_Year::Semester::Subject *findCourse;
            School_Year::Semester::Subject::Student_listMark *findStudent;

            // Reuses the function Show_Subject_Table from Model_Menu.cpp
            Space_2_Tab(); cout<<"| Course ID\t| Course Name\t\t| Teacher Name\t\t| Start Date  | End Date    | Session 1\t| Time\t\t | Session 2\t| Time\t\t | Credits\t| Max Student   |"<<endl;
            while (currentYear != NULL) {
                findSemester = currentYear->yearSemesterHead;

                while (findSemester != NULL) {
                    findCourse = findSemester->yearSemesterSubjectHead;

                    while (findCourse != NULL) {
                        findStudent = findCourse->yearSemesterSubStudent_ListHead;

                        while (findStudent != NULL) {
                            if (findStudent->idStudent == stoi(findStudentID)) {
                                
                                Space_2_Tab(); cout<<"| "<<findCourse -> id_Subject<<"\t| ";
        
                                if (findCourse -> name_Subject.size() < 5) cout<<findCourse -> name_Subject<<"\t\t\t| ";
                                else if (findCourse -> name_Subject.size() < 14) cout<<findCourse -> name_Subject<<"\t\t| ";
                                else cout<<findCourse -> name_Subject<<"\t| ";

                                //Teacher Name
                                if ((findCourse -> teacher_Name).size() > 14) cout<<findCourse -> teacher_Name<<"\t| ";
                                else cout<<findCourse -> teacher_Name<<"\t\t| ";
                                
                                //Start date, Endate
                                cout<<findCourse -> startDate<<"  | "<<findCourse -> endDate<<"  | ";
                                cout<<findCourse -> day_Of_Session_1<<"\t| ";

                                if (findCourse -> at_Time_1 == "S3" ) cout<<"13:30 - 15:29  | ";
                                if (findCourse -> at_Time_1 == "S4" ) cout<<"15:30 - 17:29  | ";
                                if (findCourse -> at_Time_1 == "S1" ) cout<<"7:30 - 9:29\t | ";
                                if (findCourse -> at_Time_1 == "S2" ) cout<<"9:30 - 11:29\t | ";

                                if (findCourse -> day_Of_Session_2.size() > 3) cout<<findCourse -> day_Of_Session_2<<"\t| ";
                                else 
                                cout<<findCourse -> day_Of_Session_2<<"\t\t| ";
                                
                                if (findCourse -> at_Time_2 == "S3" ) cout<<"13:30 - 15:29  | ";
                                if (findCourse -> at_Time_2 == "S4" ) cout<<"15:30 - 17:29  | ";
                                if (findCourse -> at_Time_2 == "S1" ) cout<<"7:30 - 9:29\t | ";
                                if (findCourse -> at_Time_2 == "S2" ) cout<<"9:30 - 11:29\t | ";

                                cout<<findCourse -> number_Of_Credit<<"\t\t| "<<findCourse -> maximumRegrister<<" \t\t|"<<endl;
                            }

                            findStudent = findStudent->Next;
                        }

                        findCourse = findCourse->Next;
                    }

                    findSemester = findSemester->Next;
                }

                currentYear = currentYear->Next;
            }

            cout<<endl;
            Space_11_Tab(); system("pause");

            goto startCourseMenu;
        }

        case 3: {
            forStudent_ToView_ScoreBoard_Of_A_Semester(sYear_Head);
            
            Space_11_Tab(); system("pause");

            goto startCourseMenu;
        }
        
        case 4: {
            Space_11_Tab(); cout << "Good choice!\n";
            Space_11_Tab(); system("pause");
            break;
        }
        
        default: 
            goto startCourseMenu;
    }
}

void PrintProfile(Profile loginProfile) {
    Space_11_Tab(); cout << "Your profile:\n";

    Space_11_Tab(); cout << "Student ID: " << loginProfile.studentID << endl;
    Space_11_Tab(); cout << "Full name: " << loginProfile.firstName << " " << loginProfile.lastName << endl;
    Space_11_Tab(); cout << "Gender: " << loginProfile.gender << endl;
    Space_11_Tab(); cout << "Date of Birth (DoB): " << loginProfile.DoB << endl;
    Space_11_Tab(); cout << "Social ID: " << loginProfile.socialID << endl;

    Space_11_Tab(); system("pause");
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

    Space_11_Tab(); cout<<"  Wellcome to course registration (Beta Ver)"<<endl;
    Space_11_Tab(); cout<<"      1: View class"<<endl;
    Space_11_Tab(); cout<<"      2: View courses"<<endl;
    Space_11_Tab(); cout<<"      3: Change password"<<endl;
    Space_11_Tab(); cout<<"      4: View profile"<<endl;
    Space_11_Tab(); cout<<"      5: Log out"<<endl;
    Space_11_Tab(); cout<<"      Your choice: "; 
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
            cout<<endl;
            Space_11_Tab(); 
            cout << "Enter new password: ";
            newPass = encryptPasswordInput();
            cout<<endl;
            
            Space_11_Tab(); cout << "Retype: ";
            retypePass = encryptPasswordInput();
            cout<<endl;
            while (!requestPassword(newPass, retypePass)) {
                Space_11_Tab(); cout << "Please re-enter!\n";
                Space_11_Tab(); cout << "Enter new password: ";
                newPass = encryptPasswordInput();
                cout<<endl;
                Space_11_Tab(); cout << "Retype new password: ";
                retypePass = encryptPasswordInput();
                cout<<endl;
            }

            changePassword(loginUsername, newPass, 2);

            goto startMainMenu;
        }

        case 4: {
            PrintProfile(loginProfile);
            
            goto startMainMenu;
        }

        case 5: {
            Space_11_Tab(); cout << "Logging out...\n";
            break;
        }

        default: 
            goto startMainMenu;
    }

    Space_11_Tab(); system("pause");

    return ;
}