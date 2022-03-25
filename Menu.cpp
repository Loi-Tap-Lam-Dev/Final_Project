#include "lib.h"

bool Check_School_Year(School_Year* sYear_Head)
{
    if (sYear_Head == nullptr) return false;
    return true;
}

void Menu_School_Year(School_Year* &sYear_Head)
{
    int user_Choose = 0;
    while (user_Choose != 3)
    {
        system("CLS");
        cout<<"         Wellcome to course registration (Beta Ver)"<<endl;
        cout<<"             1: View School Year"<<endl;
        cout<<"             2: Create School Year"<<endl;
        cout<<"             3: Back"<<endl;
        cout<<"             Your choice: "; 
        cin>>user_Choose;
        cout<<endl;

        switch (user_Choose)
        {
        
        case 1:
        {
            if (!Check_School_Year(sYear_Head)) cout<<"Nothing being added"<<endl;
            else 
                {
                    cout<<"School_Year: ";
                    
                    School_Year* sYear_Cur = sYear_Head;
                    while (sYear_Cur != nullptr)
                    {
                        cout<< atoi((sYear_Cur -> year).c_str()) << " - " << atoi((sYear_Cur -> year).c_str()) + 1  << "    ";

                        sYear_Cur = sYear_Cur -> Next;
                    }
                }
            break;
        }

        case 2:
        
        default:
            break;
        }

        char choose = 'Y';
        cout<<"Coninue? Your choice (Y/N): ";
        cin>>choose;

        if (choose == 'N') break;
    }
    cout<<"Thanks for spending time"<<endl;
    return ;
}