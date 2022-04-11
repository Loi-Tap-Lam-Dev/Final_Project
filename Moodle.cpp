#include "lib.h"

int main() {
    
    // ios_base::sync_with_stdio();
    // cin.tie(NULL); cout.tie(NULL);
    
    Account account;

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
                //proceed
                School_Year* sYear_Head = nullptr;

                    //Menu
                    Primal_Menu(sYear_Head);

                    Delete_School_Year(sYear_Head);   
            }
            else {
                cout<<"\nLogin failed, please check your credentials and try again!\n";
                Sleep(2000);
                goto beginAuthentication;
            }
            
            // Test the change password function
            string newPass, retypePass;
            cout << "\nEnter new password: ";
            newPass = encryptPasswordInput();
            cout << "Retype: ";
            retypePass = encryptPasswordInput();

            while (!requestPassword(newPass, retypePass)) {
                cout << "Please re-enter!\n";
                cout << "Enter new password: ";
                newPass = encryptPasswordInput();
                cout << "Retype: ";
                retypePass = encryptPasswordInput();
            }

            changePassword(account.username, newPass, 1);

            break;
        }
        case 2: {
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

            // Test the change password function
            string newPass, retypePass;
            cout << "\nEnter new password: ";
            newPass = encryptPasswordInput();
            cout << "Retype: ";
            retypePass = encryptPasswordInput();

            while (!requestPassword(newPass, retypePass)) {
                cout << "Please re-enter!\n";
                cout << "Enter new password: ";
                newPass = encryptPasswordInput();
                cout << "Retype: ";
                retypePass = encryptPasswordInput();
            }

            changePassword(account.username, newPass, 2);

            break;
        }
        case 3: {
            cout<<"Thank you!\n";
            return 0;

            break;
        }
        default: {
            cout<<"Invalid choice";
            Sleep(2000);
            goto beginAuthentication;
        }
    }

    appendAccount("1124443", "test", 1);

    return 0;
}
