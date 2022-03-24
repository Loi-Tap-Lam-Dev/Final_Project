//
//  Model.cpp
//  Project nháp
//
//  Created by Minh Đỗ on 16/03/2022.
//

#include "Model.hpp"

#include "View.hpp"

using namespace std;


bool loginStaff(string username, string password) {
    string id, pass;
    ifstream input("CredentialsSta.txt");
    while (input >> id >> pass) {
        cout<<id<<" "<<pass;
        if (username == id && password == pass) {
            cout<<"logged in";
            return 1;
        }
        else {
            return 0;
        }
    }
    input.close();
    return 0;
    
}

bool loginStudent(string username, string password) {
    string id, pass;
    ifstream input("CredentialsStu.txt");
    while (input >> id >> pass) {
        cout<<id<<" "<<pass;
        if (username == id && password == pass) {
            cout<<"logged in";
            return 1;
        }
        else {
            return 0;
        }
    }
    input.close();
    return 0;
    return 0;
}
