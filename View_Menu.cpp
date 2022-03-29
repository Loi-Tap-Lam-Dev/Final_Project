#include "lib.h"

//Noted task havent finished: 
//Noted: Try to make orderd linked list

//Check classes empty
bool Check_Classes(School_Year::Year_Class* Classes_Head)
{
    if (Classes_Head == nullptr) return false;
    return true;
}

//Checkb year empty - ༼ つ ◕_◕ ༽つ
bool Check_School_Year(School_Year* sYear_Head)
{
    if (sYear_Head == nullptr) return false;
    return true;
}

//Check Year Dup - (❁´◡`❁)
bool Check_Year_Duplicated(School_Year* sYear_Cur, string x)
{
    while (sYear_Cur != nullptr)
    {
        if (sYear_Cur -> year == x) return false;
        
        sYear_Cur = sYear_Cur -> Next;
    }
    return true;
}

//Check Classes Dup - ヽ(✿ﾟ▽ﾟ)ノ
bool Check_Classes_Duplicated(School_Year::Year_Class* Classes_Cur, string x)
{
    while (Classes_Cur != nullptr)
    {
        if (Classes_Cur -> nameClass == x) return false;
        
        Classes_Cur = Classes_Cur -> Next;
    }
    return true;
}

//Find the year with the same naem of user choosed - ヾ(⌐■_■)ノ♪
School_Year* find_School_Year(School_Year* sYear_Cur,string user_choosed_Year)
{
    while (sYear_Cur != nullptr)
    {
        if (sYear_Cur -> year == user_choosed_Year) return sYear_Cur;
        
        sYear_Cur = sYear_Cur -> Next;
    }
}

//View Classes - ᕦ(ò_óˇ)ᕤ
void View_Classes(string user_School_Year,School_Year::Year_Class* Classes_Head)
{
    if (!Check_Classes(Classes_Head)) 
        {
            cout<<"Nothing being added"<<endl;
            return ;
        }
            else 
                {
                    //Show the Available School_Year - 👌
                    system("CLS");
                    cout<<"School_Year: "<<atoi(user_School_Year.c_str())<<"-"<<atoi(user_School_Year.c_str()) + 1<<endl;
                    cout<<"             Classes: ";
                    
                    School_Year::Year_Class* Classes_Cur = Classes_Head;

                    while (Classes_Cur != nullptr)
                    {
                        cout<<Classes_Cur -> nameClass<<" , ";
                        Classes_Cur = Classes_Cur -> Next;
                    }

                    cout<<endl<<endl;
                }
}

//Create Classes - (ﾉ*ФωФ)ﾉ
void Create_Classes(School_Year* &Year_Cur, School_Year::Year_Class* &Classes_Head)
{
    //Declareed
    string user_input = "";
    School_Year::Year_Class* Classes_Cur = Classes_Head;

    //Check if Classes_Head empty for create new at first
            if (Classes_Head == nullptr) 
            {
                //Input
                cout<<"Noted: Valided classes name (21clc01,..) if the school year was: 2021 - 2022 "<<endl;
                cout<<"Your school year chosen: "<<Year_Cur -> year<<" . Enter Classes Name: ";
                cin.ignore();
                getline(cin,user_input);
                
                //Convert string -> char*
                char* input = new char [user_input.size()];
                strcpy( input,user_input.c_str() );

                //Check if the data is corrected
                if (user_input.substr(0,2) != Year_Cur -> year . substr(2,2)) return ;

                //Declare
                Classes_Head = new School_Year::Year_Class;

                //Strtok
                const char* denim = "-";
                Classes_Head -> nameClass = strtok(input,denim);

                //Dont forget to save the head of the class list
                Year_Cur -> yearCLassHead = Classes_Head;
                return;
            }        

            //Check if value is being duplicated or not?
            char* contain = "";
            cin.ignore();
            do
            {
                //Input
                cout<<"Noted: Valided classes name (21clc01,..) if the school year was: 2021 - 2022 "<<endl;
                cout<<"Your school year chosen: "<<Year_Cur -> year<<" . Enter Classes Name: ";
                getline(cin,user_input);
                
                //Check if the data is corrected
                if (user_input.substr(0,2) != Year_Cur -> year . substr(2,2)) return ;

                //Convert string -> char*
                char* input = new char [user_input.size()];
                strcpy( input,user_input.c_str() );

                //Strtok
                const char* denim = "-";
                contain = strtok(input,denim);

                //Print out remind user to enter value again
                if (!Check_Classes_Duplicated(Classes_Head,contain)) cout<<"Your data has been duplicated. Pls retry"<<endl<<endl;

            } while ( !Check_Classes_Duplicated(Classes_Head,contain) );

            //Check if Next year is havent existed
            while (Classes_Cur -> Next != nullptr) Classes_Cur = Classes_Cur -> Next;

            //Create Next Year
            Classes_Cur -> Next = new School_Year::Year_Class;
            Classes_Cur = Classes_Cur -> Next;
            
            Classes_Cur -> nameClass = contain;

            return;
}

//View Year - ╰(*°▽°*)╯
void View_Year(School_Year* sYear_Head)
{
    Showing_School_Year:
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
    //Beside, the value of the user must being added
        string user_choosed_Year = "";
    do
    {
            cout<<"Which School-Year you want to view Classes. Ex: 2021-2022"<<endl;
            cout<<"Noted: If you dont want to choose any year pls Enter 'N' "<<endl;
            cout<<"Enter answer: ";

            cin.ignore();
            getline(cin,user_choosed_Year);

        if (user_choosed_Year == "N") return;

        //Check if the user choosed Year is existed
        if (Check_Year_Duplicated(sYear_Head,user_choosed_Year)) 
        {
            cout<<"This school-year: "<<user_choosed_Year<<" hasnt existed. Pls try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            system("pause");
            goto Showing_School_Year;
        }
    } while (Check_Year_Duplicated(sYear_Head,user_choosed_Year));
    
    //Use strtok - 👍
    const char* denim = "-";
    char* temp = new char [user_choosed_Year.size()];

    // But it neeeded to convert string -> char* - 🔑
    strcpy(temp,user_choosed_Year.c_str());
    user_choosed_Year = strtok(temp, denim);

    //Menu for classes in specific school-year - 📲
    int user_Choose = 0;
    School_Year::Year_Class* Classes_Head = nullptr; // To view or create. First is Declare

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
                    cout<<"School_Year: "<<atoi(user_choosed_Year.c_str())<<"-"<<atoi(user_choosed_Year.c_str()) + 1<<endl;
                    School_Year* sYear_Cur = find_School_Year(sYear_Head,user_choosed_Year);
                    View_Classes(user_choosed_Year,sYear_Cur -> yearCLassHead);
                    break;
                }

                //Create Classes
                case 2:
                {
                    // cout<<find_School_Year(sYear_Head,user_choosed_Year) -> year;
                    // system("pause");
                    School_Year* sYear_Cur = find_School_Year(sYear_Head,user_choosed_Year);
                    Create_Classes(sYear_Cur,Classes_Head);
                    continue;
                    break;
                }
                
                default:
                    break;
            }

    }

    cout<<"         Ending Menu Classes"<<endl;
    system("pause");
    
    //End of this funcs
    return;
}

//Create Year - ヾ(≧▽≦*)o
void Create_Year(School_Year* &sYear_Head)
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
            cin.ignore();
            do
            {
                //Input
                cout<<"Enter School-Year (Ex: 2020-2021) : ";
                // cin.ignore();
                getline(cin,user_input);
                
                //Convert string -> char*
                char* input = new char [user_input.size()];
                strcpy( input,user_input.c_str() );

                //Strtok
                const char* denim = "-";
                contain = strtok(input,denim);

                //Print out remind user to enter value again
                if (!Check_Year_Duplicated(sYear_Head,contain)) cout<<"Your data has been duplicated. Pls retry"<<endl<<endl;

            } while ( !Check_Year_Duplicated(sYear_Head,contain) );
            
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
                continue;
                break;
            }

            case 2:
            {
                Create_Year(sYear_Head);
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