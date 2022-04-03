//
//  Model.hpp
//  Project nháp
//
//  Created by Minh Đỗ on 16/03/2022.
//

#ifndef Model_hpp
#define Model_hpp

#include <stdio.h>

using namespace std;

#endif /* Model_hpp */
struct Account {
    string username;
    string password;
    bool verify;
};

bool loginStaff(string, string);
bool loginStudent(string, string);

bool requestPassword(string, string);
bool checkAvailability(string);

void changePassword(string, string, int);
void appendAccount(string, string);
void registerAccount();