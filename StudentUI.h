#pragma once

#include <iostream>

#include "lib.h"

using namespace std;

void PrintClassList(School_Year *sYear_Head) {
    system("CLS");

    cout << "Displaying available classes:\n";

    if (sYear_Head == NULL) {
        cout << "No class available!\n";
        return;
    }
    
    School_Year *currentYear = sYear_Head;
    School_Year::Year_Class *currentClass = currentYear->yearCLassHead;
    
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
    cout << "\t\tAvailable operations:\n";
    cout << "\t\t   1: View student list in class\n";
    cout << "\t\t   2: Give up and quit\n";
}

void PrintMenu(School_Year *&sYear_Head)
{
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
        case 1: {
            PrintClassList(sYear_Head);
            break;
        }

        default:
            break;
    }

    system("pause");

    return ;
}