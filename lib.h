#pragma  once

//Include lib
#include <iostream>
#include <fstream>
#include <string>
#include <string.h> //To use strtok
#include <cstring>
#include <stdlib.h> // To clear screen

#include <chrono> // Setting for delay the time
#include <thread> // Setting for delay the time

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono;    // nanoseconds, system_clock, seconds
//Declare fstream
fstream finp, fout;


//Include Function file
#include "DataBase.cpp"
#include "Read_Data.cpp"
#include "View_Data.cpp"
#include "DeLeTe_Data.cpp"
#include "Model_Menu.cpp"
#include "Print_Data.cpp"