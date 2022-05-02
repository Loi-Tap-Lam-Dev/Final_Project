#include "Lib\lib.h"

int main() {
    
    //Declare
    School_Year* sYear_Head = nullptr;
    bool loggedInAsAdmin = false;

beginAuthentication:
    system("CLS");
    int choice = loginOption();

    cin.clear();
    cin.ignore(1000, '\n');

    switch(choice) {
        case 1: {
            getCredentials(account.username, account.password);
            if (loginStaff(account.username, account.password)==1) {
                cout<<"Success!\n";
                loggedInAsAdmin = true;
            }
            else {
                cout<<"\nLogin failed, please check your credentials and try again!\n";
                Sleep(2000);
                goto beginAuthentication;
            }
            
            break;
        }
        case 2: {
            getCredentials(account.username, account.password);
            if(loginStudent(account.username, account.password)==1) {
                cout<<"Success!\n";
                loggedInAsAdmin = false;
            }
            else {
                cout<<"\nLogin failed, please check your credentials and try again!\n";
                Sleep(2000);
                goto beginAuthentication;
            }

            break;
        }
        case 3: {
            PrintData(sYear_Head);

            Delete_School_Year(sYear_Head);
            
            cout << "All data have been successfully saved!\n";
            cout << "Thank you! You can now safely close the application.\n";

            return 0;
        }
        default: {
            cout<<"Invalid choice";
            Sleep(2000);
            goto beginAuthentication;
        }
    }
    
    //Read data from file
    Read_Data_From_File(sYear_Head);
    Read_Semester(sYear_Head);

    if (loggedInAsAdmin) {
        
        // Menu for staff
        Primal_Menu(sYear_Head);

    }
    else {
        Profile studentProfile;

        if (!LoadStudentProfile(account.username, studentProfile)) {
            cout << "Unable to load your data!\n";
            cout << "The data is either corrupted, or your username is not found!\n";

            Sleep(3000);

            goto beginAuthentication;
        }

        cout << "Account data succesfully loaded! Please wait a few seconds!\n";

        Sleep(3000);

        PrintMainStudentMenu(sYear_Head, account.username, studentProfile);
    }

    // Save and resets runtime data after every sections
    PrintData(sYear_Head);
    Delete_School_Year(sYear_Head);

    goto beginAuthentication;

    return 0;
}
