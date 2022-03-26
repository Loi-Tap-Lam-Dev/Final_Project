#include "lib.h"

bool Check_School_Year(School_Year* sYear_Head)
{
    if (sYear_Head == nullptr) return false;
    return true;
}

bool Check_Duplicated(School_Year* sYear_Cur,string x)
{
    while (sYear_Cur != nullptr)
    {
        if (sYear_Cur -> year == x) return false;
        
        sYear_Cur = sYear_Cur -> Next;
    }
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
                        cout<< atoi((sYear_Cur -> year).c_str()) << " - " << atoi((sYear_Cur -> year).c_str()) + 1  << ",    ";

                        sYear_Cur = sYear_Cur -> Next;
                    }
                    cout<<endl;
                }
            break;
        }

        case 2:
        {
            string user_input = "";
            School_Year* sYear_Cur = sYear_Head;
            if (sYear_Head == nullptr) 
            {
                sYear_Head = new School_Year;
                
                cout<<"Enter School-Year (Ex: 2020-2021) : ";
                cin.ignore();
                getline(cin,user_input);
                
                //Convert string -> char*
                char* input = new char [user_input.size()];
                strcpy( input,user_input.c_str() );

                //Strtok
                const char* denim = "-";
                sYear_Head -> year = strtok(input,denim);

                continue;
            }

            while (sYear_Cur -> Next != nullptr) sYear_Cur = sYear_Cur -> Next;
            
            //Create Next Year
            sYear_Cur -> Next = new School_Year;
            sYear_Cur = sYear_Cur -> Next;

            char* contain = "";
            do
            {
                cout<<"Enter School-Year (Ex: 2020-2021) : ";
                cin.ignore();
                getline(cin,user_input);
                
                //Convert string -> char*
                char* input = new char [user_input.size()];
                strcpy( input,user_input.c_str() );

                //Strtok
                const char* denim = "-";
                contain = strtok(input,denim);

            } while ( !Check_Duplicated(sYear_Head,contain) );
            
            sYear_Cur -> year = contain;

            continue;
            break;
        }
        
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