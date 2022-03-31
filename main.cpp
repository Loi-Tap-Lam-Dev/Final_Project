#include "lib.h"

int main() {

//Changeable data - (●'◡'●)
    //Declare 
    School_Year* sYear_Head = nullptr;

    //Menu
    Menu_School_Year(sYear_Head);

    while (sYear_Head != nullptr)
    {
        School_Year* temp = sYear_Head ;

        School_Year::Year_Class* Classes_Head = temp -> yearCLassHead;

            while (Classes_Head != nullptr)
            {
                School_Year::Year_Class* temp_Classes = Classes_Head;

                Classes_Head = Classes_Head -> Next;

                delete temp_Classes;
            }

        sYear_Head = sYear_Head -> Next;

        delete temp;
    }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// //Cant Reset Data
//     //Declare the apocalypse   
//     Year* yearHead = nullptr;

//     //Read \- O v O -/
//     readFileYear(yearHead);

//     //Dizzplay
//     //displayScreen(yearHead); // U can use if u want to see in the terminal
//     displayFile(yearHead); //Otherwise display in file is much better

//     //Delete, avoid mém mo ri lít kinh
//     Delete_Data(yearHead);
    
    return 0;
}