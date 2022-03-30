//
//  Model.cpp
//  Project nháp
//
//  Created by Minh Đỗ on 16/03/2022.
//

#pragma once

#include <iostream>
#include <string>
#include <fstream>

// This file is evil, for some reason... 
// #include "modelLogin.hpp"

using namespace std;

bool loginStaff(string username, string password) {
    string id, pass;
    ifstream input("CredentialsSta.txt");
    while (input >> id >> pass) {
        if (username == id && password == pass) {
            cout<<"\nLogged in\n";
            input.close(); 
            return 1;
        }
    }
    input.close();
    return 0;
}

bool loginStudent(string username, string password) {
    string id, pass;
    ifstream input("CredentialsStu.txt");
    while (input >> id >> pass) {
        if (username == id && password == pass) {
            cout<<"\nLogged in\n";
            input.close();
            return 1;
        }
    }
    input.close();
    return 0;
}

bool requestPassword(string newPassword, string retypePassword) {
    if (newPassword == retypePassword) return true;

    return false;
}

// NOT FINISHED! There are bugs and stuff
void changePassword_Staff(string username, string password) {
    string id, pass;

    fstream fileIn, fileOut;
    fileIn.open("CredentialsSta.txt", ios::in);
    fileOut.open("CredentialsSta.txt", ios::out);

    while (fileIn >> id >> pass) {
        fileOut << id << " " << password << endl;
        cout << "eeeeeeeeeeeeeee\n";

        if (username == id) {
            fileOut << username << " " << password;
        }
    }

    fileIn.close();
    fileOut.close();
}

// void changePassword_Student(string, string) {

// }