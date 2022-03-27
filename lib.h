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
#include "DataBase.cpp"
#include "Read_Data.cpp"
#include "Display_Data.cpp"
#include "DeLeTe_Data.cpp"
#include "Menu.cpp"