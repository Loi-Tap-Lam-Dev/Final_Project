#pragma  once

//Include lib
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>     // To use strtok
#include <windows.h>    // Change console settings
#include <cstring>
#include <stdlib.h>     // To clear screen

using namespace std;

//Declare fstream
fstream finp, fout;

//Include Function file
#include "View\DataBase.h"
#include "Read_Data.cpp"
#include "Display_Data.cpp"
#include "DeLeTe_Data.cpp"
#include "Menu.cpp"
#include "Model\modelLogin.hpp"

// TGHuy:
// - I use these to run the program on VS Code
// - This is bad and unnecessary, don't be like me
//
#include "View\viewLogin.h"
#include "Model.h"