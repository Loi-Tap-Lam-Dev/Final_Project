#pragma  once

//Include lib
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>     // To use strtok
#include <windows.h>    // Change console settings, evil library, use with caution!
#include <cstring>
#include <stdlib.h>     // To clear screen

#include <chrono> // Setting for delay the time
#include <thread> // Setting for delay the time

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono;    // nanoseconds, system_clock, seconds

//Declare fstream
fstream finp, fout;

// User profile structure (for students)
struct Profile {
    string studentID;
    string firstName, lastName;
    string gender;
    string DoB;
    string socialID;
};

//Show Title
void Down_2_Line()
{
    cout<<endl;
    cout<<endl;
}

void Down_3_Line()
{
    cout<<endl;
    cout<<endl;
}

void Space_3_Tab()
{
    cout<<"\t\t\t";
}

void Space_5_Tab()
{
    cout<<"\t\t\t\t\t";
}

void Space_2_Tab()
{
    cout<<"\t\t";
}

void Space_7_Tab()
{
    cout<<"\t\t\t\t\t\t\t";
}

void Space_9_Tab()
{
    cout<<"\t\t\t\t\t\t\t\t\t";
}

void Space_11_Tab()
{
    cout<<"\t\t\t\t\t\t\t\t\t\t\t";
}

void Space_13_Tab()
{
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t";
}
void Space_15_Tab()
{
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
}

void Heading()
{
    for (int i = 0; i <= 60; i++)
    {
        if (i ==  (60 / 2) ) cout<<" DATA REPRESENTATION ";
        cout<<"=";
    }
    Down_2_Line();
    cout<<endl;
}
void Heading_Score()
{
    for (int i = 0; i <= 60; i++)
    {
        if (i ==  (60 / 2) ) cout<<" SCORE REPRESENTATION ";
        cout<<"=";
    }
    Down_2_Line();
    cout<<endl;
}
void Heading_Menu_Search()
{
    for (int i = 0; i <= 60; i++)
    {
        if (i ==  (60 / 2) ) cout<<" SCORE SEARCHING MENU ";
        cout<<"=";
    }
    Down_2_Line();
    cout<<endl;
}

void Endding()
{
    Down_2_Line();
    Space_9_Tab();
    for (int i = 0; i <= 60; i++)
    {
        if (i ==  (60 / 2) ) cout<<"=====================";
        cout<<"=";
    }
    Down_2_Line();
}

//Include Function file
#include "..\View\DataBase.h"
#include "..\View\viewLogin.h"
#include "..\Model\Model_DeLeTe_Data.h"
#include "..\Model\modelLogin.hpp"


Account account;
#include "..\Model\Model.h"
#include "..\Model\Model_Menu.h"
#include "..\Model\Model_Print_Data.h"
#include "..\Model\Model_Read_Data.h"
// #include "Print_Data_New.cpp"

#include "..\Model\StudentUI.h"