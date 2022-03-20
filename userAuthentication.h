#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

#include "userDBModule.h"

using namespace std;

// --- Declaration --- //
string encryptPasswordInput();
bool validateUser();

// --- Definition --- //
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
    while (ReadConsoleA(inputHandle, &keyType, 1, &dwReadSize, NULL) && keyType != ENTER) {
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