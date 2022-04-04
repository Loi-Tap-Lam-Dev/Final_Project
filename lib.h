#pragma  once

//Include lib
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>     // To use strtok
#include <windows.h>    // Change console settings
#include <cstring>
#include <stdlib.h>     // To clear screen

#include <chrono> // Setting for delay the time
#include <thread> // Setting for delay the time

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono;    // nanoseconds, system_clock, seconds

//Declare fstream
fstream finp, fout;

//Include Function file
#include "View\DataBase.h"
#include "Read_Data.cpp"
#include "View_Data.cpp"
#include "DeLeTe_Data.cpp"
#include "View_Menu.cpp"
#include "Model\modelLogin.hpp"
// TGHuy:
// - I use these to run the program on VS Code
// - This is bad and unnecessary, don't be like me
//
#include "View\viewLogin.h"
#include "Model\Model.h"
