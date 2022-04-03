#pragma  once

//Include lib
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>     // To use strtok
#include <windows.h>    // Change console settings, evil library, use with caution!
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

#include "View\viewLogin.h"
#include "Model.h"