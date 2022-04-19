#include "lib.h"

int main() {
    
    // ios_base::sync_with_stdio();
    // cin.tie(NULL); cout.tie(NULL);
    
    School_Year* sYear_Head = nullptr;
    Account account;
    bool loggedInAsAdmin = false;

beginAuthentication:
    system("cls");
    int choice = loginOption();

    cin.clear();
    cin.ignore(1000, '\n');

    switch(choice) {
        case 1: {
            getCredentials(account.username, account.password);
            if (loginStaff(account.username, account.password)==1) {
                cout<<"Success!";
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
                cout<<"Success!";
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
            cout<<"Thank you!\n";

            Delete_School_Year(sYear_Head);

            return 0;
        }
        default: {
            cout<<"Invalid choice";
            Sleep(2000);
            goto beginAuthentication;
        }
    }

    if (loggedInAsAdmin) {
        // Menu for staff
        Primal_Menu(sYear_Head, account.username);
        
        goto beginAuthentication;
    }
    else {
        PrintMainStudentMenu(sYear_Head, account.username);
        
        goto beginAuthentication;
    }

    return 0;
}
