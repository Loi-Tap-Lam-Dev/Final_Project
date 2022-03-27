#include "lib.h"

//Noted task havent finished: Create, View Classes in school year in Function View Year line 89


//Checkb year empty - ༼ つ ◕_◕ ༽つ
bool Check_School_Year(School_Year* sYear_Head)
{
    if (sYear_Head == nullptr) return false;
    return true;
}

//Check Dup - (❁´◡`❁)
bool Check_Duplicated(School_Year* sYear_Cur,string x)
{
    while (sYear_Cur != nullptr)
    {
        if (sYear_Cur -> year == x) return false;
        
        sYear_Cur = sYear_Cur -> Next;
    }
    return true;
}

//View Year - ╰(*°▽°*)╯
void View_Year(School_Year* sYear_Head)
{
    //At first check if empty or not - ✔
    if (!Check_School_Year(sYear_Head)) 
        {
            cout<<"Nothing being added"<<endl;
            return ;
        }
            else 
                {
                    //Show the Available School_Year - 👌
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

    //To show the class of the school year user want to choose - 🤔
    string user_choosed_Year = "";

        cout<<"Which School-Year you want to view Classes. Ex: 2021-2022"<<endl;
        cout<<"Noted: If you dont want to choose any year pls Enter 'N' "<<endl;
        cout<<"Enter answer: ";

        cin.ignore();
        getline(cin,user_choosed_Year);

    if (user_choosed_Year == "N") return;

    //Use strtok - 👍
    const char* denim = "-";
    char* temp = new char [user_choosed_Year.size()];

    // But it neeeded to convert string -> char* - 🔑
    strcpy(temp,user_choosed_Year.c_str());
    user_choosed_Year = strtok(temp, denim);

    //Menu for classes in specific school-year - 📲
    int user_Choose = 0;

    while (user_Choose != 3)
    {
        cout<<endl<<endl;
        cout<<"         Wellcome to course registration (Beta Ver)"<<endl;
        cout<<"             1: View Classes in School-Year: "<<atoi(user_choosed_Year.c_str())<<"-"<<atoi(user_choosed_Year.c_str()) + 1<<endl;
        cout<<"             2: Create New Classes For: "<<atoi(user_choosed_Year.c_str())<<"-"<<atoi(user_choosed_Year.c_str()) + 1<<endl;
        cout<<"             3: Back"<<endl;
        cout<<"             Your choice: "; 

        cin>>user_Choose;

        cout<<endl;

        //Switch user_Choose
        switch (user_Choose)
        {
        
            //View Classes 
            case 1:
            {
                
                break;
            }

            //Create Classes
            case 2:
            {
                
                continue;
                break;
            }
            
            default:
                return;
                break;
        }

        //Ask user to continue or not?
        char choose = 'Y';
            cout<<"             Coninue? Your choice (Y/N): ";
            cin>>choose;

        if (choose == 'N') break;
    }

    //End of this funcs
    return;
}

//Create Year - ヾ(≧▽≦*)o
void Creat_Year(School_Year* &sYear_Head)
{
    //Declareed
    string user_input = "";
    School_Year* sYear_Cur = sYear_Head;

    //Check if sYear_Head empty for create new at first
            if (sYear_Head == nullptr) 
            {
                sYear_Head = new School_Year;
                
                //Input
                cout<<"Enter School-Year (Ex: 2020-2021 or just 2021) : ";
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

            //Check if value is being duplicated or not?
            char* contain = "";
            do
            {
                //Input
                cout<<"Enter School-Year (Ex: 2020-2021) : ";
                cin.ignore();
                getline(cin,user_input);
                
                //Convert string -> char*
                char* input = new char [user_input.size()];
                strcpy( input,user_input.c_str() );

                //Strtok
                const char* denim = "-";
                contain = strtok(input,denim);

                //Print out remind user to enter value again
                if (!Check_Duplicated(sYear_Head,contain)) cout<<"Your data has been duplicated. Pls retry"<<endl;

            } while ( !Check_Duplicated(sYear_Head,contain) );
            
            sYear_Cur -> year = contain;

            return;
}

//Menu School Year - ✍(◔◡◔)
void Menu_School_Year(School_Year* &sYear_Head)
{
    //First we need to clear screen and ask user which one they want to choose
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

        //Better use switch
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

        // Ask for continue
        char choose = 'Y';
        cout<<"             Coninue? Your choice (Y/N): ";
        cin>>choose;

        if (choose == 'N') break;
    }

    cout<<"Thanks for spending time"<<endl;

    return ;
}