//
//  View.cpp
//  Project nháp
//
//  Created by Minh Đỗ on 16/03/2022.
//

#pragma once

#include "viewLogin.hpp"

using namespace std;

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

    if (encryptedPassword.length() == 0)
        goto inputValidation;

    return encryptedPassword;
}

void FORMAT(string s) {
    cout<<"\t\t\t*********************\n\n";
    cout<<"\t\t\t\t"<<s<<"\n\n";
    cout<<"\t\t\t*********************\n\n";
}

int loginOption() {
    FORMAT("LOGIN");
    int choice;
    cout<<"1. Staff\n";
    cout<<"2. Student\n";
    cout<<"3. Exit\n\n\n";
    cout<<"Enter your choice: ";
    cin>>choice;
    return choice;
}

void getCredentials(string &username, string &password) {
    // FORMAT("LOGIN");
    cout<<"Username: ";
    cin>>username;
    cout<<"Password: ";
    cin>>password;
    // password = encryptPasswordInput();
}