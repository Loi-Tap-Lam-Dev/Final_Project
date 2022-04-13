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

    // New display window
    int choice;
    cout << "\t\tAvailable operations:\n";
    cout << "\t\t   1: View student list in class\n";
    cout << "\t\t   2: Give up and quit\n\n";
    cout << "Your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: 
            cout << "1\n";
            string findClass;
            School_Year::Year_Class *targetClassHead;

            cin.clear();
            cin.ignore(1000, '\n');
            cout << "2\n";
            cout << "Enter class to view from: ";
            getline(cin, findClass);

            currentYear = sYear_Head;
            currentClass = currentYear->yearCLassHead;

            while (currentYear != NULL) {
                cout << "3\n";
                currentClass = currentYear->yearCLassHead;

                targetClassHead = find_Classes(currentClass, findClass);

                currentYear = currentYear->Next;
            }
            cout << "4\n";
            if (targetClassHead == NULL) {
                cout << "No class found!\n";
                system("pause");
                
                goto startWindow;
            }

            Show_Sv_Table(findClass, targetClassHead->yearClassSV_ListHead);

            goto startWindow;
        
        case 2: 
            cout << "Good choice!\n";
            break;
        
        default: 
            goto startWindow;
    }
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
            cout << "Feature not available!\n";
            goto startMainMenu;
        

        default: 
            goto startMainMenu;
    }

    system("pause");

    return ;
}