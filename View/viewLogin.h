//
//  View.cpp
//  Project nháp
//
//  Created by Minh Đỗ on 16/03/2022.
//

#pragma once

#include "viewLogin.hpp"

using namespace std;

///////////////////////////////GUI/////////////////////////////////////////
void Login_Down_2_Line()
{
    cout<<endl;
    cout<<endl;
}

void Login_Down_3_Line()
{
    cout<<endl;
    cout<<endl;
}

void Login_Space_3_Tab()
{
    cout<<"\t\t\t";
}

void Login_Space_5_Tab()
{
    cout<<"\t\t\t\t\t";
}

void Login_Space_2_Tab()
{
    cout<<"\t\t";
}

void Login_Space_7_Tab()
{
    cout<<"\t\t\t\t\t\t\t";
}

void Login_Space_9_Tab()
{
    cout<<"\t\t\t\t\t\t\t\t\t";
}

void Login_Space_11_Tab()
{
    cout<<"\t\t\t\t\t\t\t\t\t\t\t";
}

void Login_Space_13_Tab()
{
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t";
}
///////////////////////////////GUI/////////////////////////////////////////


// FUNCTION CURRENTLY DYING
string encryptPasswordInput() {
    // A function that messes around with the Windows console
    // Made possible with the help of Google and that random guy
    // on the internet, and the windows.h library

    const char BACKSPACE = 8, ENTER = 13;

    string encryptedPassword;
    char keyType;

    // Don't ask me what these funny words mean
    // Ask Google, or check the C++ forum or something
    DWORD consoleMode, dwReadSize;
    HANDLE inputHandle = GetStdHandle(STD_INPUT_HANDLE);
    GetConsoleMode(inputHandle, &consoleMode);
    SetConsoleMode(inputHandle, consoleMode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));

    inputValidation:
    while (ReadConsole(inputHandle, &keyType, 1, &dwReadSize, NULL) && keyType != ENTER) {
        if (keyType == BACKSPACE && encryptedPassword.length() != 0) {
            encryptedPassword.resize(encryptedPassword.length() - 1);
            cout << "\b \b";

            continue;
        }

        encryptedPassword += keyType;
        cout << "*";
    }

    cout << endl;

    if (encryptedPassword.length() == 0)
        goto inputValidation;

    SetConsoleMode(inputHandle, consoleMode);       // Reset console mode after finish masking

    return encryptedPassword;
}

void FORMAT(string s) {
    
    Login_Down_3_Line();
    Login_Down_2_Line();    
    Login_Space_9_Tab(); cout<<"\t\t\t*********************\n\n";
    Login_Space_9_Tab(); cout<<"\t\t\t\t"<<s<<"\n\n";
    Login_Space_9_Tab(); cout<<"\t\t\t*********************\n\n";
}

int loginOption() {
    FORMAT("LOGIN");
    int choice;
    Login_Space_11_Tab(); cout<<"\t\t";  cout<<"1. Staff\n";
    Login_Space_11_Tab(); cout<<"\t\t";  cout<<"2. Student\n";
    Login_Space_11_Tab(); cout<<"\t\t";  cout<<"3. Exit\n\n\n";
    Login_Space_11_Tab(); cout<<"\t";  cout<<"Enter your choice: ";
    cin>>choice;
    return choice;
}

void getCredentials(string &username, string &password) {
    // FORMAT("LOGIN");
    Login_Space_11_Tab(); cout<<"\t";  cout<<"Username: ";
    cin>>username;
    Login_Space_11_Tab(); cout<<"\t";  cout<<"Password: ";
    // cin>>password;
    password = encryptPasswordInput();
}