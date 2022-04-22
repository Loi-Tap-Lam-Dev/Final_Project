//
//  Model.cpp
//  Project nháp
//
//  Created by Minh Đỗ on 16/03/2022.
//

// PROPOSAL:
// We should consider moving the user data to a binary file
// Tho if we decide not to care about security, let's not bother lol I'm lazy too

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

bool checkAvailability(string username, int mode) {
    string takenID;

    fstream readName;
    if (mode == 1)
        readName.open("CredentialsSta.txt", ios::in);
    else if (mode == 2)
        readName.open("CredentialsStu.txt", ios::in);

    while (readName >> takenID) {
        if (takenID == username) {
            readName.close();
            return false;
        }
    }

    readName.close();
    return true;
}

void changePassword(string username, string newPassword, int mode) {
    fstream fileMain, fileTemp;

    try {
        if (mode == 1)
            fileMain.open("CredentialsSta.txt");
        else if (mode == 2)
            fileMain.open("CredentialsStu.txt");
        else throw mode;
    }
    catch (int mode) {
        cout << "CHANGE REQUEST FAILED\n";
        cout << "Mode of " << mode << " does not exist!\n";
        cout << "Available modes: 1 - Staff | 2 - Student\n";
        
        return;
    }
    
    fileTemp.open("TempAccountData.txt", ios::out);
    
    string id, currentPassword;

    // Copy all the contents to a temporary file
    // and update the new password
    while (fileMain >> id >> currentPassword) {
        if (username == id) {
            fileTemp << id << " " << newPassword << endl;
            continue;
        }

        fileTemp << id << " " << currentPassword << endl;
    }

    fileMain.close();
    if (mode == 1)
        fileMain.open("CredentialsSta.txt", ios::out);
    else if (mode == 2)
        fileMain.open("CredentialsStu.txt", ios::out);
    
    // Change open mode of fileTemp
    // There could be a better way, but I don't know,
    // I ain't a professional
    fileTemp.close();
    fileTemp.open("TempAccountData.txt", ios::in);

    // Rewrite all data of current file
    while (fileTemp >> id >> currentPassword)
        fileMain << id << " " << currentPassword << endl;

    fileMain.close();
    fileTemp.close();
}

void appendAccount(string newUsername, string newPassword, int mode) {
    if (!checkAvailability(newUsername, mode)){
        cout << "Username is already taken!\n";
        return;
    }

    fstream updateFile;
    try {
        if (mode == 1)
            updateFile.open("CredentialsSta.txt");
        else if (mode == 2)
            updateFile.open("CredentialsStu.txt");
        else throw mode;
    }
    catch (int mode) {
        cout << "REGISTER REQUEST FAILED\n";
        cout << "Mode of " << mode << " does not exist!\n";
        cout << "Available modes: 1 - Staff | 2 - Student\n";
        
        return;
    }

    if (updateFile.fail()) {
        cout << "File failed!\n";
    }

    updateFile.seekp(0, ios::end);
    updateFile << newUsername << " " << newPassword << endl;
}

bool LoadStudentProfile(string username, Profile &studentProfile) {
    fstream studentFile;
    studentFile.open("./CSV_File/Student_Info.csv", ios::in);

    string fileString;
    getline(studentFile, fileString);

    while (!studentFile.eof()) {
        getline(studentFile, fileString);

        //Convert str -> char*;
        char *input = new char [ fileString.size() ];
        strcpy(input,fileString.c_str());

        studentProfile.No = atoi(strtok(input, ","));

        studentProfile.studentID = strtok(NULL, ",");
        studentProfile.firstName = strtok(NULL, ",");
        studentProfile.lastName = strtok(NULL, ",");
        studentProfile.gender = strtok(NULL, ",");
        studentProfile.DoB = strtok(NULL, ",");
        studentProfile.socialID = strtok(NULL, ",");

        if (studentProfile.studentID == username) {
            cout << "Data loaded succesfully!\n";
            studentFile.close();

            return true;
        }
    } 
    
    studentFile.close();

    return false;
}