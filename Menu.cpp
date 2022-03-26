#include "lib.h"

//Check empty
bool Check_School_Year(School_Year* sYear_Head)
{
    if (sYear_Head == nullptr) return false;
    return true;
}

//Check Dup
bool Check_Duplicated(School_Year* sYear_Cur,string x)
{
    while (sYear_Cur != nullptr)
    {
        if (sYear_Cur -> year == x) return false;
        
        sYear_Cur = sYear_Cur -> Next;
    }
    return true;
}

//View Year

void View_Year(School_Year* sYear_Head)
{
    if (!Check_School_Year(sYear_Head)) 
        {
            cout<<"Nothing being added"<<endl;
            return ;
        }
            else 
                {
                    system("CLS");
                    cout<<"             School_Year: ";
                    
                    School_Year* sYear_Cur = sYear_Head;
                    while (sYear_Cur != nullptr)
                    {
                        cout<< atoi((sYear_Cur -> year).c_str()) << " - " << atoi((sYear_Cur -> year).c_str()) + 1  << ",    ";

                        sYear_Cur = sYear_Cur -> Next;
                    } 
                    cout<<endl<<endl;
                }
    //To show the class of the school year user want to choose
    string user_choosed_Year = "";
    cout<<"Which School-Year you want to view Classes. Noted: If you dont want to choose any year pls Enter 'N' "<<endl;
    cout<<"Enter answer: ";
    cin.ignore();
    getline(cin,user_choosed_Year);

    if (user_choosed_Year == 'N') return;

    //Menu for classes in specific school-year
    int user_Choose = 0;
    while (user_Choose != 3)
    {
        cout<<endl<<endl;
        cout<<"         Wellcome to course registration (Beta Ver)"<<endl;
        cout<<"             1: View Classes in School-Year: "<<user_choosed_Year<<endl;
        cout<<"             2: Create New Classes For: "<<user_choosed_Year<<endl;
        cout<<"             3: Back"<<endl;
        cout<<"             Your choice: "; 
        cin>>user_Choose;
        cout<<endl;

        switch (user_Choose)
        {
        
        case 1:
        {
           // View_Year(sYear_Head);
            break;
        }

        case 2:
        {
          //  Creat_Year(sYear_Head);
            continue;
            break;
        }
        
        default:
            return;
            break;
        }

        char choose = 'Y';
        cout<<"             Coninue? Your choice (Y/N): ";
        cin>>choose;

        if (choose == 'N') break;
    }

    return;
}

//Create Year
void Creat_Year(School_Year* &sYear_Head)
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

                return;
            }

            //Check if Next year is havent existed
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

            return;
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
            View_Year(sYear_Head);
            break;
        }

        case 2:
        {
            Creat_Year(sYear_Head);
            continue;
            break;
        }
        
        default:
            break;
        }

        char choose = 'Y';
        cout<<"             Coninue? Your choice (Y/N): ";
        cin>>choose;

        if (choose == 'N') break;
    }
    cout<<"Thanks for spending time"<<endl;
    return ;
}