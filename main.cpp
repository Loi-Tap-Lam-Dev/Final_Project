#include "lib.h"
#include "DataBase.cpp"
#include "viewLogin.hpp"
#include "modelLogin.hpp"

// #include "View.cpp"
// #include "Model.cpp"

using namespace std;

int main() {
    Year* Year_pHead = new Year;
    
    ios_base::sync_with_stdio();
    cin.tie(NULL); cout.tie(NULL);
    
    Account account;

beginAuthentication:
    int choice = loginOption();
    cin.ignore(1000, '\n');
    switch(choice) {
        case 1:
            getCredentials(account.username, account.password);
            if (loginStaff(account.username, account.password)==1) {
                cout<<"Success!";
                //proceed
            }
            else {
                cout<<"Login failed, please check your credentials and try again!\n";
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
                cout<<"Login failed, please check your credentials and try again!\n";
                goto beginAuthentication;
            }

            break;
        case 3:
            cout<<"Thank you!\n";
            exit(1);

            break;
        default:
            cout<<"Invalid choice";
            goto beginAuthentication;
    }

    return 0;
}
