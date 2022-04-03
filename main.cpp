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
                cout<<"Success!\n";
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

            // Attempting to fix console echo
            // EDIT: It's fixed! YAY!
            int yeeLmao;
            cout << "I am bugging lol you shall suffer: ";
            cin >> yeeLmao;
            cout << "Yee the Bug: " << yeeLmao << endl;

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

    
    return 0;
}
