#pragma  once

//Include lib
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>     // To use strtok
#include <windows.h>    // Change console settings, evil library, use with caution!
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
#include "Read_Data_New.cpp"
#include "DeLeTe_Data.cpp"
#include "Model\modelLogin.hpp"

#include "View\viewLogin.h"
#include "Model\Model.h"
#include "Model_Menu.cpp"
#include "Print_Data.cpp"

#include "StudentUI.h"
