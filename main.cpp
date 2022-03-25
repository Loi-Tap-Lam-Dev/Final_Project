#include "lib.h"

int main() {

//Changeable data
    //Declare 
    School_Year* sYear_Head = nullptr;

    //Menu
    Menu_School_Year(sYear_Head);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Cant Reset Data
    //Declare the apocalypse   
    Year* yearHead = nullptr;

    //Read \- O v O -/
    readFileYear(yearHead);

    //Dizzplay
    //displayScreen(yearHead); // U can use if u want to see in the terminal
    displayFile(yearHead); //Otherwise display in file is much better

    //Delete, avoid mém mo ri lít kinh
    Delete_Data(yearHead);
    
    return 0;
}