#include "lib.h"
#include "DataBase.cpp"
#include "viewLogin.hpp"
#include "modelLogin.hpp"

// TGHuy:
// - I use these to run the program on VS Code
// - This is bad and unnecessary, don't be like me
//
#include "View.cpp"
#include "Model.cpp"

using namespace std;

int main() {
    Year* Year_pHead = new Year;
    
    ios_base::sync_with_stdio();
    cin.tie(NULL); cout.tie(NULL);
    
    Account account;

beginAuthentication:
    system("cls");
    int choice = loginOption();
    switch(choice) {
        case 1: 
            getCredentials(account.username, account.password);
            if (loginStaff(account.username, account.password)==1) {
                cout<<"Success!";
                //proceed
            }
            else {
                cout<<"\nLogin failed, please check your credentials and try again!\n";
                Sleep(2000);
                goto beginAuthentication;
            }

            break;
        case 2:
            getCredentials(account.username, account.password);
            if(loginStudent(account.username, account.password)==1) {
                cout<<"Success!";
                //proceed
            }
            else {
                cout<<"\nLogin failed, please check your credentials and try again!\n";
                Sleep(2000);
                goto beginAuthentication;
            }

            break;
        case 3:
            cout<<"Thank you!\n";
            exit(1);

            break;
        default:
            cout<<"Invalid choice";
            Sleep(2000);
            goto beginAuthentication;
    }

//Changeable data - (●'◡'●)

    //Declare 
    School_Year* sYear_Head = nullptr;

    //Menu
    Menu_School_Year(sYear_Head);

    while (sYear_Head != nullptr)
    {
        School_Year* temp = sYear_Head ;
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
