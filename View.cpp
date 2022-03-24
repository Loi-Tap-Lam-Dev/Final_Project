//
//  View.cpp
//  Project nháp
//
//  Created by Minh Đỗ on 16/03/2022.
//

#include "viewLogin.hpp"
using namespace std;


void FORMAT(string s) {
    cout<<"\t\t\t*********************\n\n";
    cout<<"\t\t\t\t\t"<<s<<"\n\n";
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
    FORMAT("LOGIN");
    cout<<"Username: ";
    cin>>username;
    cout<<"Password: ";
    cin>>password;
}





