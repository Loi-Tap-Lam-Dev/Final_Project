#include "lib.h"
#include "DataBase.cpp"

using namespace std;

int main() {
    Year* Year_pHead = new Year;

    // User authentication
    string password;
    cout << "Enter password: ";
    password = encryptPasswordInput();
    cout << endl << password << endl;       // Use for debug, remove before launch

    return 0;
}