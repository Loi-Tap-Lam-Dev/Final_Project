#include "lib.h"


int main() {

//Changeable data - (●'◡'●)

    //Declare 
    School_Year* sYear_Head = nullptr;

    //Read Data
    //ReadData(sYear_Head);
    Read_Data_From_File(sYear_Head);
    Read_Semester(sYear_Head);
    
    //Menu
    Primal_Menu(sYear_Head);

    //Print Data - Check 💨
    //outInfor(sYear_Head);
    
    //forStudent_ToView_ScoreBoard_Of_A_Semester(sYear_Head);
    
    //Delete
    Delete_School_Year(sYear_Head);
    
    return 0;
}