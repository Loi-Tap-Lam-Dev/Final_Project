//
//  Model.cpp
//  Project nháp
//
//  Created by Minh Đỗ on 16/03/2022.
//

#pragma once

// This file is evil, for some reason... 
// #include "modelLogin.hpp"

using namespace std;

bool loginStaff(string username, string password) {
    string id, pass;
    ifstream input("CredentialsSta.txt");
    while (input >> id >> pass) {
        if (username == id && password == pass) {
            cout<<"\nLogged in\n";
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
            return 1;
        }
    }
    input.close();
    return 0;
}
