#include "lib.h"

int main() {
    
    // ios_base::sync_with_stdio();
    // cin.tie(NULL); cout.tie(NULL);
    
    Account account;

beginAuthentication:
    system("cls");
    int choice = loginOption();
    switch(choice) {
        case 1: {
            getCredentials(account.username, account.password);
            if (loginStaff(account.username, account.password)==1) {
                cout<<"Success!\n";
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
            exit(1);

            break;
        }
        default: {
            cout<<"Invalid choice";
            Sleep(2000);
            goto beginAuthentication;
        }
    }
    
    // This is where the cin bug begins,
    // or my computer is as dumb as me
    int a;
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "adwaawd:\n";
    cin >> a;
    cout << a;

    // Changeable data - (●'◡'●)
    //Declare 
    // School_Year* sYear_Head = nullptr;

    // //Menu
    // Menu_School_Year(sYear_Head);

    // while (sYear_Head != nullptr)
    // {
    //     School_Year* temp = sYear_Head ;
    //     sYear_Head = sYear_Head -> Next;

    //     delete temp;
    // }
    
    return 0;
}
