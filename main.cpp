#include "lib.h"
#include "DataBase.cpp"
#include "viewLogin"
#include "modelLogin"

using namespace std;

int main() {
    Year* Year_pHead = new Year;
    
    ios_base::sync_with_stdio();
    cin.tie(NULL); cout.tie(NULL);
    Account account;
    int choice = loginOption();
    switch(choice){
        case 1:
            getCredentials(account.username, account.password);
            if(loginStaff(account.username, account.password)==1){
                cout<<"Success!";
                //proceed
            }
            else{
                cout<<"Login failed, please check your credentials and try again!\n";
                main(argc, argv);
            }
        case 2:
            getCredentials(account.username, account.password);
            if(loginStudent(account.username, account.password)==1) {
                cout<<"Success!";
                //proceed
            }
            else {
                cout<<"Login failed, please check your credentials and try again!\n";
                main(argc, argv);
            }
        case 3:
            cout<<"Thank you!\n";
            exit(1);
        break;
        default:
            cout<<"Invalid choice";
            main(argc, argv);
            
            
    }

    return 0;
}
