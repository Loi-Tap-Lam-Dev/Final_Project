//
//  View.hpp
//  Project nháp
//
//  Created by Minh Đỗ on 16/03/2022.
//

#ifndef View_hpp
#define View_hpp

#include <stdio.h>
#include <iostream>
#include <windows.h>

#include "..\lib.h"

using namespace std;

#endif /* View_hpp */

void FORMAT(string s);
int loginOption();
void getCredentials(string &username, string &password);
string encryptPasswordInput();
