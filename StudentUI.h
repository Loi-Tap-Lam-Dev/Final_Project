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
    if (sYear_Head->yearSemesterHead->yearSemesterSubjectHead == NULL) {
        cout << "No course available!\n";
        system("pause");

        return;
    }

    School_Year *currentYear = sYear_Head;

    cout << "Available courses:\n";

    while (currentYear != NULL) {
        Show_Subject_Table(to_string(currentYear->yearSemesterHead->Term), currentYear->yearSemesterHead->yearSemesterSubjectHead);

        currentYear = currentYear->Next;
    }

    currentYear = sYear_Head;
}

void PrintMainStudentMenu(School_Year *&sYear_Head)
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
    cout<<"             3: Log out"<<endl;
    cout<<"             Your choice: "; 
    cin>>user_Choose;
    cout<<endl;

    //Better use switch
    switch (user_Choose)  {
        case 1:
            ClassListMenu(sYear_Head);
            goto startMainMenu;

        case 2: 
            CourseListMenu(sYear_Head);
            system("pause");
            goto startMainMenu;

        case 3:
            cout << "Logging out...\n";
            break;

        default: 
            goto startMainMenu;
    }

    system("pause");

    return ;
}