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

// User profile structure (for students)
struct Profile {
    string studentID;
    string firstName, lastName;
    string gender;
    string DoB;
    string socialID;
};

//Include Function file
#include "View\DataBase.h"
#include "DeLeTe_Data.cpp"
#include "Model\modelLogin.hpp"

#include "View\viewLogin.h"
#include "Model\Model.h"
#include "Model_Menu.cpp"
#include "Print_Data_New.cpp"
#include "Read_Data.cpp"
// #include "Print_Data_New.cpp"

#include "StudentUI.h"