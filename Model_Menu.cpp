#include "lib.h"

int YOrN() {
    cout<<"0. Yes\n";
    cout<<"1. No\n";
    cout<<"Press a key to continue\n";
    int choice;
    cin>>choice;
    return choice;
}

bool registration_status() {
    FILE *status;
    int res_status;
    status = fopen("Registration Status.txt", "r");
    fscanf(status, "%d", &res_status);
    fclose(status);
    return res_status;
}

void update_registration_status(School_Year* sYear_Head);

//Show Title

void Down_2_Line()
{
    cout<<endl;
    cout<<endl;
}

void Down_3_Line()
{
    cout<<endl;
    cout<<endl;
}

void Space_3_Tab()
{
    cout<<"\t\t\t";
}

void Space_5_Tab()
{
    cout<<"\t\t\t\t\t";
}

void Space_2_Tab()
{
    cout<<"\t\t";
}

void Space_7_Tab()
{
    cout<<"\t\t\t\t\t\t\t";
}

void Space_9_Tab()
{
    cout<<"\t\t\t\t\t\t\t\t\t";
}

void Space_11_Tab()
{
    cout<<"\t\t\t\t\t\t\t\t\t\t\t";
}

void Space_13_Tab()
{
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t";
}
void Space_15_Tab()
{
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
}

void Heading()
{
    for (int i = 0; i <= 60; i++)
    {
        if (i ==  (60 / 2) ) cout<<" DATA REPRESENTATION ";
        cout<<"=";
    }
    Down_2_Line();
    cout<<endl;
}

void Endding()
{
    Down_2_Line();
    Space_9_Tab();
    for (int i = 0; i <= 60; i++)
    {
        if (i ==  (60 / 2) ) cout<<"=====================";
        cout<<"=";
    }
    Down_2_Line();
}

//Check is there enough 3 term of Semester
int Check_Num_Semester(School_Year::Semester* Semester_Head)
{
    int count = 0;

    while (Semester_Head != nullptr)
    {
        count ++;
        Semester_Head = Semester_Head -> Next;
        
    }
    
    return count;
}

//Check Sv_List empty - ┌( ಠ_ಠ)┘
bool Check_Sv_List(School_Year::Year_Class::SV_List* Sv_Head)
{
    if (Sv_Head == nullptr) return false;
    return true;
}

//Check classes empty - ┌( ಠ_ಠ)┘
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

//Check Sv Dup in Input scene
bool Check_Sv_Duplicated_Input(School_Year::Year_Class::SV_List* Sv_Cur,School_Year::Year_Class::SV_List* Temp_Sv)
{
    while (Sv_Cur -> Next != nullptr)
    {
        if (Sv_Cur -> no == Temp_Sv -> no) return false; //Check no

        if (Sv_Cur -> idStudent == Temp_Sv -> idStudent) return false; //Check Id_SV

        if (Sv_Cur -> socialID == Temp_Sv ->socialID) return false; //Check Social ID

        //Only need to check 3 of this because every data remain is allowed to be duplicated

        Sv_Cur = Sv_Cur -> Next;
    }
    return true;
}

//Check Sv Dup in Input scene
bool Check_Sv_Duplicated(School_Year::Year_Class::SV_List* Sv_Cur,School_Year::Year_Class::SV_List* Temp_Sv)
{
    while (Sv_Cur != nullptr)
    {
        if (Sv_Cur -> no == Temp_Sv -> no) return false; //Check no

        if (Sv_Cur -> idStudent == Temp_Sv -> idStudent) return false; //Check Id_SV

        if (Sv_Cur -> socialID == Temp_Sv ->socialID) return false; //Check Social ID

        //Only need to check 3 of this because every data remain is allowed to be duplicated

        Sv_Cur = Sv_Cur -> Next;
    }
    return true;
}

//Check Semester
bool Check_Semester_Duplicated(School_Year::Semester* Semester_Cur, int temp)
{
    while (Semester_Cur != nullptr)
    {
        if (Semester_Cur -> Term == temp) return false;

        Semester_Cur = Semester_Cur -> Next;
    }
    return true;
}

//Check Subject Input
bool Check_Subject_Duplicated_Input(School_Year::Semester::Subject* Subject_Head,School_Year::Semester::Subject* Subject_Cur)
{
    while (Subject_Head -> Next != nullptr)
    {
        if (Subject_Head -> id_Subject == Subject_Cur -> id_Subject) return false;

        if (Subject_Head -> name_Subject == Subject_Cur -> name_Subject) return false;

        if (Subject_Head -> day_Of_Session_1  == Subject_Cur -> day_Of_Session_1 ) 
            {
                if (Subject_Head -> at_Time_1  == Subject_Cur -> at_Time_1 )  return false;
            }

        if (Subject_Head -> day_Of_Session_2  == Subject_Cur -> day_Of_Session_2 ) 
            {
                if (Subject_Head -> at_Time_2  == Subject_Cur -> at_Time_2 )  return false;
            }
        Subject_Head = Subject_Head -> Next;
    }
    return true;
}

//Check Subject Duplicated
bool Check_Subject_Duplicated(School_Year::Semester::Subject* Subject_Head,School_Year::Semester::Subject* Subject_Cur)
{
    while (Subject_Head != nullptr)
    {
        if (Subject_Cur == Subject_Head ) goto Next;

        if (Subject_Head -> id_Subject == Subject_Cur -> id_Subject) return false;

        if (Subject_Head -> name_Subject == Subject_Cur -> name_Subject) return false;

        if (Subject_Head -> day_Of_Session_1  == Subject_Cur -> day_Of_Session_1 ) 
            {
                if (Subject_Head -> at_Time_1  == Subject_Cur -> at_Time_1 )  return false;
            }

        if (Subject_Head -> day_Of_Session_2  == Subject_Cur -> day_Of_Session_2 ) 
            {
                if (Subject_Head -> at_Time_2  == Subject_Cur -> at_Time_2 )  return false;
            }

        Next:
        Subject_Head = Subject_Head -> Next;
    }
    return true;
}

//Check ID Student Match With Score Board To Adjust
bool Check_IdStu_Course_Dup(School_Year::Semester::Subject::Student_listMark* Student_Head, School_Year::Semester::Subject::Student_listMark* Student_Cur)
{
    while (Student_Head != nullptr)
    {
        if (Student_Cur -> idStudent == Student_Head -> idStudent) return false;
        Student_Head = Student_Head -> Next;
    }
    return true;
}

//Compare 
School_Year::Semester::Student_listMark* Compare_Result_Of_Whole_term(School_Year::Semester::Subject::Student_listMark* Student_Cur,School_Year::Semester::Student_listMark* Whole_Term_Head)
{
    while (Whole_Term_Head != nullptr)
    {
        if (Student_Cur -> idStudent == Whole_Term_Head -> idStudent) return Whole_Term_Head;
        Whole_Term_Head = Whole_Term_Head -> Next;
    }
    return nullptr;
}

//Find the year with the same naem of user choosed - ヾ(⌐■_■)ノ♪
School_Year* find_School_Year(School_Year* sYear_Cur,string user_choosed_Year)
{
    while (sYear_Cur != nullptr)
    {
        if (sYear_Cur -> year == user_choosed_Year) return sYear_Cur;
        
        sYear_Cur = sYear_Cur -> Next;
    }
    return nullptr;
}

//Find the classes with the same name of user choosed - ヾ(⌐■_■)ノ♪
School_Year::Year_Class* find_Classes(School_Year::Year_Class* Classes_Cur,string user_choosed_Class)
{
    while (Classes_Cur!= nullptr)
    {   
        if (Classes_Cur -> nameClass == user_choosed_Class) return Classes_Cur;
        
        Classes_Cur= Classes_Cur-> Next;
    }
    return nullptr;
}

//Find Sv due to No, Id, Social ID
School_Year::Year_Class::SV_List* find_Student(School_Year::Year_Class::SV_List* Sv_Cur,School_Year::Year_Class::SV_List* Temp_Sv)
{
    while (Sv_Cur != nullptr)
    {
        if (Sv_Cur -> no == Temp_Sv -> no) return Sv_Cur; //Check no

        if (Sv_Cur -> idStudent == Temp_Sv -> idStudent) return Sv_Cur; //Check Id_SV

        if (Sv_Cur -> socialID == Temp_Sv ->socialID) return Sv_Cur; //Check Social ID

        //Only need to check 3 of this because every data remain is allowed to be duplicated

        Sv_Cur = Sv_Cur -> Next;
    }
    return nullptr;
}

//Find Semester
School_Year::Semester* find_Semester(School_Year::Semester* Semester_Cur, int temp)
{
    while (Semester_Cur != nullptr)
    {
        if (Semester_Cur -> Term == temp) return Semester_Cur;

        Semester_Cur = Semester_Cur -> Next;
    }
    return nullptr;
}

//Find Subject
School_Year::Semester::Subject* find_Subject(School_Year::Semester::Subject* Subject_Head,School_Year::Semester::Subject* Subject_Cur)
{
    while (Subject_Head != nullptr)
    {
        if (Subject_Head -> id_Subject == Subject_Cur -> id_Subject) return Subject_Head;

        if (Subject_Head -> name_Subject == Subject_Cur -> name_Subject) return Subject_Head;

        if (Subject_Head -> day_Of_Session_1  == Subject_Cur -> day_Of_Session_1 ) 
            {
                if (Subject_Head -> at_Time_1  == Subject_Cur -> at_Time_1 )  return Subject_Head;
            }

        if (Subject_Head -> day_Of_Session_2  == Subject_Cur -> day_Of_Session_2 ) 
            {
                if (Subject_Head -> at_Time_2  == Subject_Cur -> at_Time_2 )  return Subject_Head;
            }

        Subject_Head = Subject_Head -> Next;
    }
    return nullptr;
}

//Find Student In Score Board
School_Year::Semester::Subject::Student_listMark* find_Student_ScoreBoard(School_Year::Semester::Subject::Student_listMark* Score_Head,School_Year::Semester::Subject::Student_listMark* Score_Temp )
{
    while (Score_Head != nullptr)
    {
        if (Score_Head -> idStudent == Score_Temp -> idStudent) return Score_Head;
        Score_Head = Score_Head -> Next;
    }
    School_Year::Semester::Subject::Student_listMark* Null_Value = nullptr;
    return Null_Value;
}

//Show School-Year table - <( ‵□′)───C＜─___-)||
void Show_Year_Table(School_Year* sYear_Head)
{
    //Show the table full of School_Year - 👌
    system("CLS");

    //Gui
    Down_2_Line();
    Space_9_Tab();
    Heading();

    Space_3_Tab(); cout<<"School_Year:    |    ";
    
    School_Year* sYear_Cur = sYear_Head;
    int count = 1;

        while (sYear_Cur != nullptr)
        {
            cout<< atoi((sYear_Cur -> year).c_str()) << " - " << atoi((sYear_Cur -> year).c_str()) + 1  << "    |    ";
            if (count == 7) 
                {
                    Down_2_Line();
                    Space_5_Tab();
                    cout<<"|    ";
                    count = 0;
                }
            count++;
            sYear_Cur = sYear_Cur -> Next;
        } 

    Endding();
}

//Show Classes table - （︶^︶）
void Show_Classes_Table(string user_School_Year,School_Year::Year_Class* Classes_Head)
{
     //Show the Classes from chosen school year - 👌
        system("CLS");
        
        //Gui
        Down_2_Line();
        Space_9_Tab();
        Heading();

        Space_3_Tab(); cout<<"School_Year:    |    "<<atoi(user_School_Year.c_str())<<"-"<<atoi(user_School_Year.c_str()) + 1<<"   |"<<endl;
        Space_3_Tab(); cout<<"Classes:        |   ";
        
        int count = 1;
        School_Year::Year_Class* Classes_Cur = Classes_Head;

        while (Classes_Cur != nullptr)
        {
            cout<<Classes_Cur -> nameClass<<"   |    ";
            if (count == 9) 
                {
                    Down_2_Line();
                    Space_5_Tab();
                    cout<<"|    ";
                    count = 0;
                }
            count++;
            Classes_Cur = Classes_Cur -> Next;
        }

        Endding();
}

//Show SV_list table - 
void Show_Sv_Table(string user_Class,School_Year::Year_Class::SV_List* Sv_Head)
{
     //Show the Classes from chosen school year - 👌
        system("CLS");

        //Gui
        Down_2_Line();
        Space_9_Tab();
        Heading();

        Space_5_Tab(); cout<<"| Classes\t|"<<user_Class<<"\t\t|"<<endl<<endl;
        Space_5_Tab(); cout<<"| No\t| Student ID\t\t| First Name\t| Last Name\t\t| Gender\t| DateOfBirth\t\t| Social ID\t\t|"<<endl;
        Space_5_Tab();
        
        School_Year::Year_Class::SV_List* Sv_Cur = Sv_Head;

        while (Sv_Cur != nullptr) 
        {
            cout<<"| "<<Sv_Cur -> no<<"\t| "<<Sv_Cur ->idStudent<<"\t\t| "<<Sv_Cur ->firstName<<"\t\t| ";

            if (Sv_Cur -> lastName.size() < 5) cout<<Sv_Cur ->lastName<<"\t\t\t| ";
            else cout<<Sv_Cur ->lastName<<"\t\t| ";
            cout<<Sv_Cur ->gender<<"\t\t| "<<Sv_Cur ->dateOfBirth<<"\t\t| "<<Sv_Cur ->socialID<<"\t\t| "<<endl;
            
            Space_5_Tab();
            Sv_Cur = Sv_Cur -> Next;
        }

        Endding();
}

//Show Semester
void Show_Semester_Table(string user_School_Year,School_Year::Semester* Semester_Head)
{
     //Show the table full of School_Year - 👌
        system("CLS");

        //Gui
        Down_2_Line();
        Space_9_Tab();
        Heading();

        Space_11_Tab(); cout<<"| School_Year:    | "<<atoi(user_School_Year.c_str())<<"-"<<atoi(user_School_Year.c_str()) + 1<<"\t|"<<endl;
        Space_11_Tab(); cout<<"| Semester      | Start Date\t| End Date\t|"<<endl;
        Space_11_Tab(); cout<<"| ";
        School_Year::Semester* Semester_Cur = Semester_Head;

            while (Semester_Cur != nullptr)
            {
                switch (Semester_Cur -> Term)
                {
               
                    case 1:
                    {
                         cout<<Semester_Cur -> Term<<" (Fall)\t| "<<Semester_Cur -> start_Date<<"\t| "<<Semester_Cur -> end_Date<<"\t|";
                        break;
                    }

                    case 2:
                    {
                         cout<<Semester_Cur -> Term<<" (Summer)\t| "<<Semester_Cur -> start_Date<<"\t| "<<Semester_Cur -> end_Date<<"\t|";
                        break;
                    }
                    
                    default:
                    {
                         cout<<Semester_Cur -> Term<<" (Autumn)\t| "<<Semester_Cur -> start_Date<<"\t| "<<Semester_Cur -> end_Date<<"\t|";
                        break;
                    }
                }
                
                if (Semester_Cur -> Next != nullptr)
                {
                    cout<<endl;
                    Space_11_Tab(); cout<<"| ";
                }

                Semester_Cur = Semester_Cur -> Next;
            } 

        cout<<endl;
        Endding();
}

//Show Subject Table
void Show_Subject_Table(string user_Semester,School_Year::Semester::Subject* Subject_Head)
{
    // system("CLS");
    //Gui
        Down_2_Line();
        Space_9_Tab();
        Heading();
    Space_2_Tab(); cout<<"| Semester\t|"<<user_Semester<<"\t|"<<endl<<endl;
    Space_2_Tab(); cout<<"| Course ID\t| Course Name\t\t| Teacher Name\t\t| Start Date  | End Date    | Session 1\t| Time\t\t | Session 2\t| Time\t\t | Credits\t| Max Student   |"<<endl;
    
    while (Subject_Head != nullptr)
    {
        Space_2_Tab(); cout<<"| "<<Subject_Head -> id_Subject<<"\t| ";
        
        if (Subject_Head -> name_Subject.size() < 5) cout<<Subject_Head -> name_Subject<<"\t\t\t| ";
        else if (Subject_Head -> name_Subject.size() < 14) cout<<Subject_Head -> name_Subject<<"\t\t| ";
        else cout<<Subject_Head -> name_Subject<<"\t| ";

        //Teacher Name
        if ((Subject_Head -> teacher_Name).size() > 14) cout<<Subject_Head -> teacher_Name<<"\t| ";
        else cout<<Subject_Head -> teacher_Name<<"\t\t| ";
        
        //Start date, Endate
        cout<<Subject_Head -> startDate<<"  | "<<Subject_Head -> endDate<<"  | ";
        cout<<Subject_Head -> day_Of_Session_1<<"\t| ";

        if (Subject_Head -> at_Time_1 == "S3" ) cout<<"13:30 - 15:29  | ";
        if (Subject_Head -> at_Time_1 == "S4" ) cout<<"15:30 - 17:29  | ";
        if (Subject_Head -> at_Time_1 == "S1" ) cout<<"7:30 - 9:29\t | ";
        if (Subject_Head -> at_Time_1 == "S2" ) cout<<"9:30 - 11:29\t | ";

        if (Subject_Head -> day_Of_Session_2.size() > 3) cout<<Subject_Head -> day_Of_Session_2<<"\t| ";
        else 
        cout<<Subject_Head -> day_Of_Session_2<<"\t\t| ";
        
        if (Subject_Head -> at_Time_2 == "S3" ) cout<<"13:30 - 15:29  | ";
        if (Subject_Head -> at_Time_2 == "S4" ) cout<<"15:30 - 17:29  | ";
        if (Subject_Head -> at_Time_2 == "S1" ) cout<<"7:30 - 9:29\t | ";
        if (Subject_Head -> at_Time_2 == "S2" ) cout<<"9:30 - 11:29\t | ";

        cout<<Subject_Head -> number_Of_Credit<<"\t\t| "<<Subject_Head -> maximumRegrister<<" \t\t|"<<endl;

        Subject_Head = Subject_Head -> Next;
    }

    Endding();
}

//Show Specific Subject
void Show_Specific_Subject_Table(string user_Semester,School_Year::Semester::Subject* Subject_Head,School_Year::Semester::Subject* Subject_Cur)
{
    system("CLS");
    Down_2_Line();
        Space_9_Tab();
        Heading();

    Space_2_Tab(); cout<<"You Are Choosing: "<<endl<<endl;
    Space_2_Tab(); cout<<"| Course ID\t| Course Name\t\t| Teacher Name\t\t| Start Date  | End Date    | Session 1\t| Time\t\t | Session 2\t| Time\t\t | Credits\t| Max Student   |"<<endl;

    while (Subject_Head != nullptr)
    {
        if (Subject_Head != Subject_Cur) 
        {
            Subject_Head = Subject_Head -> Next;
            continue;
        }

        Space_2_Tab(); cout<<"| "<<Subject_Head -> id_Subject<<"\t| ";
        
        if (Subject_Head -> name_Subject.size() < 5) cout<<Subject_Head -> name_Subject<<"\t\t\t| ";
        else if (Subject_Head -> name_Subject.size() < 14) cout<<Subject_Head -> name_Subject<<"\t\t| ";
        else cout<<Subject_Head -> name_Subject<<"\t| ";

        //Teacher Name
        if ((Subject_Head -> teacher_Name).size() > 14) cout<<Subject_Head -> teacher_Name<<"\t| ";
        else cout<<Subject_Head -> teacher_Name<<"\t\t| ";
        
        //Start date, Endate
        cout<<Subject_Head -> startDate<<"  | "<<Subject_Head -> endDate<<"  | ";
        cout<<Subject_Head -> day_Of_Session_1<<"\t| ";

        if (Subject_Head -> at_Time_1 == "S3" ) cout<<"13:30 - 15:29  | ";
        if (Subject_Head -> at_Time_1 == "S4" ) cout<<"15:30 - 17:29  | ";
        if (Subject_Head -> at_Time_1 == "S1" ) cout<<"7:30 - 9:29\t | ";
        if (Subject_Head -> at_Time_1 == "S2" ) cout<<"9:30 - 11:29\t | ";

        if (Subject_Head -> day_Of_Session_2.size() > 3) cout<<Subject_Head -> day_Of_Session_2<<"\t| ";
        else 
        cout<<Subject_Head -> day_Of_Session_2<<"\t\t| ";
        
        if (Subject_Head -> at_Time_2 == "S3" ) cout<<"13:30 - 15:29  | ";
        if (Subject_Head -> at_Time_2 == "S4" ) cout<<"15:30 - 17:29  | ";
        if (Subject_Head -> at_Time_2 == "S1" ) cout<<"7:30 - 9:29\t | ";
        if (Subject_Head -> at_Time_2 == "S2" ) cout<<"9:30 - 11:29\t | ";

        cout<<Subject_Head -> number_Of_Credit<<"\t\t| "<<Subject_Head -> maximumRegrister<<" \t\t|"<<endl;

        Endding();

        return;
    } 
    
    Endding();
}

//Show ScoreBoard
void Show_ScoreBoard(School_Year::Semester::Subject::Student_listMark* Score_head)
{
    if (Score_head == nullptr)
    {
        cout<<"Nothing to show. Please Try Again"<<endl;
        system("pause");
        return;
    }
    cout<<"\t|No\t|Student_ID\t|Full_Name\t\t|Mid-Term Mark\t|Final Mark\t|Other Mark\t|Total\t|"<<endl;
    while (Score_head != nullptr)
    {
        cout<<"\t|"<<Score_head -> no<<"\t|"<<Score_head -> idStudent<<"\t|";
         
        if (Score_head -> FullName .size() < 9) cout<<Score_head -> FullName<<"\t\t\t|";
        else if (Score_head -> FullName .size() < 14) cout<<Score_head -> FullName<<"\t\t|";
        else cout<<Score_head -> FullName<<"\t|";

        cout<<Score_head -> midTermMark<<"\t\t|"<<Score_head -> finalTermMark<<"\t\t|"<<Score_head -> otherMark<<"\t\t|"<<Score_head -> totalMark<<"\t|";
        cout<<endl;
        Score_head = Score_head -> Next;
    }
    cout<<endl;
}

//Show Specific Result 
void Show_Specific_StuResult(School_Year::Semester::Subject::Student_listMark* Score_head,School_Year::Semester::Subject::Student_listMark* Score_Cur)
{
    if (Score_head == nullptr)
    {
        cout<<"Nothing to show. Please Try Again"<<endl;
        system("pause");
        return;
    }
    cout<<"\t|No\t|Student_ID\t|Full_Name\t\t|Mid-Term Mark\t|Final Mark\t|Other Mark\t|Total\t|"<<endl;
    while (Score_head != nullptr)
    {
        if (Score_head == Score_Cur)
        {
            cout<<"\t|"<<Score_head -> no<<"\t|"<<Score_head -> idStudent<<"\t|";
         
            if (Score_head -> FullName .size() < 9) cout<<Score_head -> FullName<<"\t\t\t|";
            else if (Score_head -> FullName .size() < 14) cout<<Score_head -> FullName<<"\t\t|";
            else cout<<Score_head -> FullName<<"\t|";

            cout<<Score_head -> midTermMark<<"\t\t|"<<Score_head -> finalTermMark<<"\t\t|"<<Score_head -> otherMark<<"\t\t|"<<Score_head -> totalMark<<"\t|";
            cout<<endl;
            return;
        }
        Score_head = Score_head -> Next;
    }
    cout<<endl;
}

//Show Term Mark Of Specific Student ID
void Show_Specific_TermMark_Of_Student(School_Year::Semester::Student_listMark* Term_Mark, School_Year::Semester::Student_listMark* Term_Mark_Cur)
{
    if (Term_Mark == nullptr)
    {
        cout<<"Nothing to show. Please Try Again"<<endl;
        system("pause");
        return;
    }
    cout<<"\t|No\t|Student_ID\t|Full_Name\t\t|Total_Credit\t|Average_Mark\t|GPA\t|"<<endl;
    while (Term_Mark!= nullptr)
    {
        if (Term_Mark -> idStudent == Term_Mark_Cur -> idStudent)
        {
            cout<<"\t|"<<Term_Mark -> no<<"\t|"<<Term_Mark -> idStudent<<"\t|";

            if (Term_Mark -> fullName .size() < 9) cout<<Term_Mark -> fullName<<"\t\t|";
            else cout<<Term_Mark -> fullName<<"\t|";

            cout<<Term_Mark -> totalCredit<<"\t\t|"<<Term_Mark -> averageMark<<"\t\t|"<<Term_Mark -> GPA<<"\t|";

            return;
        }

        Term_Mark = Term_Mark -> Next;
    }
    cout<<endl;
}

//View Student List
void View_Sv_List(string user_Class, School_Year::Year_Class::SV_List* Sv_Head )
{
    //Show SV Table
    if (!Check_Sv_List(Sv_Head)) 
        {
            Space_5_Tab(); cout<<"Nothing being added"<<endl;
            Space_5_Tab(); system("Pause");
            return ;
        }
            else 
                {
                   Show_Sv_Table(user_Class,Sv_Head);
                }
    Space_5_Tab(); system("pause");
}

//Create Student List Manual
void Create_Sv_List_Manual(School_Year::Year_Class* &Class_Cur, School_Year::Year_Class::SV_List* &Sv_Head)
{
    //Declared
    string user_input = "";
    School_Year::Year_Class::SV_List* Sv_Cur = Sv_Head;

    //Check if Sv_Head empty for create new at first
    if (Sv_Head == nullptr) 
            {
                //Input
                Space_5_Tab(); cout<<"Your Class: "<<Class_Cur -> nameClass<<endl;
                
                //Declare for the element of SV list contain
                int no = 0 , idStudent , socialID;
                string lastName , firstName , gender , dateOfBirth;

                //Also create new node for the Sv_head
                Sv_Head = new School_Year::Year_Class::SV_List;

                Sv_Head -> no = no + 1 ; // Because this is the top of the list so it will be no = 1

                Space_5_Tab(); cout<<"ID Student: "; 
                    cin>>idStudent;
                Space_5_Tab(); cout<<"First Name: ";
                    cin.ignore(); // To get line
                    getline(cin,firstName);
                Space_5_Tab(); cout<<"Last Name: ";

                    getline(cin,lastName);
                Space_5_Tab(); cout<<"Gender (Male/Female/Other): ";
                    
                    getline(cin,gender);
                Space_5_Tab(); cout<<"Date of Birh: ";
                    
                    getline(cin,dateOfBirth);
                Space_5_Tab(); cout<<"Social ID: ";
                    cin>>socialID;

                //Assigned those value into the list
                Sv_Head -> idStudent = idStudent;
                Sv_Head -> firstName = firstName;
                Sv_Head -> lastName = lastName;
                Sv_Head -> gender = gender;
                Sv_Head -> dateOfBirth = dateOfBirth;
                Sv_Head -> socialID = socialID;

                //Dont forget to save the head of the Sv_list
                Class_Cur -> yearClassSV_ListHead = Sv_Head;

                return;
            }        
    
    //Check if Next SV_List is havent existed
            while (Sv_Cur -> Next != nullptr) Sv_Cur = Sv_Cur -> Next;

            //Create Next Classes and dont forget do store the Prev
            Sv_Cur -> Next = new School_Year::Year_Class::SV_List;
            Sv_Cur -> Next -> Prev = Sv_Cur;
            Sv_Cur = Sv_Cur -> Next;

    //Check if value is being duplicated or not?
    do
    {
        //Input
        Space_5_Tab(); cout<<"Your Class: "<<Class_Cur -> nameClass<<endl;
        
        //Declare for the element of SV list contain
        int no = 0 , idStudent , socialID;
        string lastName , firstName , gender , dateOfBirth;

        no = Sv_Cur -> Prev -> no + 1; // The No will be automatically count by the Node you add 

        Space_5_Tab();  cout<<"ID Student: "; 
            cin>>idStudent;
        Space_5_Tab(); cout<<"First Name: ";
            cin.ignore(); // To get line
            getline(cin,firstName);
        Space_5_Tab(); cout<<"Last Name: ";
            getline(cin,lastName);
        Space_5_Tab(); cout<<"Gender (Male/Female/Other): ";
            
            getline(cin,gender);
        Space_5_Tab(); cout<<"Date of Birh: ";
            
            getline(cin,dateOfBirth);
        Space_5_Tab(); cout<<"Social ID: ";
            cin>>socialID;

        //Assigned those value into the list
        Sv_Cur -> no = no;
        Sv_Cur -> idStudent = idStudent;
        Sv_Cur -> firstName = firstName;
        Sv_Cur -> lastName = lastName;
        Sv_Cur -> gender = gender;
        Sv_Cur -> dateOfBirth = dateOfBirth;
        Sv_Cur -> socialID = socialID;

        //Print out remind user to enter value again
        if (!Check_Sv_Duplicated_Input(Sv_Head,Sv_Cur)) 
        {
            Space_5_Tab(); 
            cout<<"Your data has been duplicated. Pls retry."<<endl<<endl;
        }
    } while ( !Check_Sv_Duplicated_Input(Sv_Head,Sv_Cur) );
    

    return ;
}

//Create_Sv_List Import
void Create_Sv_List_Import(School_Year::Year_Class* &Class_Cur, School_Year::Year_Class::SV_List* &Sv_Head)
{
    //Declared
    School_Year::Year_Class::SV_List* Sv_Cur = Sv_Head;

    int no = 0 , idStudent , socialID;
    string lastName , firstName , gender , dateOfBirth;

    fstream  finp;

    cout << "a\n";
    finp.open("CSV_File/Student_Info.csv", ios::in);
    cout << "open\n";

    if (!finp.is_open())
        {
            Space_5_Tab(); cout<<"The file is empty, Please import the data"<<endl;
            return;
        }
    //Check if Sv_Head empty for create new at first
    
    string line_input = "";
    getline(finp, line_input); //Skip one line
    
    while ( !finp.eof() )
    {
        if (Sv_Head == nullptr)
        {
            Sv_Head = new School_Year::Year_Class::SV_List;

            getline(finp, line_input);

            if (line_input == "") break;

            //Convert str -> char*;
            char* input = new char [ line_input.size() ];
            strcpy(input,line_input.c_str());

            //Set denim
            const char* denim = ",";

            no = atoi( strtok(input,denim) );
            idStudent = atoi( strtok(NULL,denim) );
            firstName = strtok(NULL,denim);
            lastName = strtok(NULL,denim);
            gender = strtok(NULL,denim);
            dateOfBirth = strtok(NULL,denim);
            socialID = atoi( strtok(NULL,denim) );

            Sv_Head -> no = no;
            Sv_Head -> idStudent = idStudent;
            Sv_Head -> firstName = firstName;
            Sv_Head -> lastName = lastName;
            Sv_Head -> gender = gender;
            Sv_Head -> dateOfBirth = dateOfBirth;
            Sv_Head -> socialID = socialID;

            Class_Cur -> yearClassSV_ListHead = Sv_Head;

            //Set up for the next income
            Sv_Cur = Sv_Head;
            
            continue;
        }

        //Get Data
        getline(finp, line_input);
        
        if (line_input == "") break;

        //Convert str -> char*;
        char* input = new char [ line_input.size() ];
        strcpy(input,line_input.c_str());

        //Set denim
        const char* denim = ",";

        //Create new node
        while (Sv_Cur -> Next != nullptr) Sv_Cur = Sv_Cur -> Next;
        Sv_Cur -> Next = new School_Year::Year_Class::SV_List;
        Sv_Cur -> Next -> Prev = Sv_Cur;
        Sv_Cur = Sv_Cur -> Next;

        no = atoi( strtok(input,denim) );
        idStudent = atoi( strtok(NULL,denim) );
        firstName = strtok(NULL,denim);
        lastName = strtok(NULL,denim);
        gender = strtok(NULL,denim);
        dateOfBirth = strtok(NULL,denim);
        socialID = atoi( strtok(NULL,denim) );

        Sv_Cur -> no = Sv_Cur -> Prev -> no + 1;
        Sv_Cur -> idStudent = idStudent;
        Sv_Cur -> firstName = firstName;
        Sv_Cur -> lastName = lastName;
        Sv_Cur -> gender = gender;
        Sv_Cur -> dateOfBirth = dateOfBirth;
        Sv_Cur -> socialID = socialID;
    }
    
    finp.close();

    return ;
}

//Adjust Sv List
void Adjust_Sv_List(School_Year::Year_Class* Class_Cur, School_Year::Year_Class::SV_List* &Sv_Head)
{
    if (Sv_Head == nullptr)
    {
        Space_5_Tab(); cout<<"There are nothing to be adjusted. Please Create One.";
        Space_5_Tab(); system("pause");
        return;
    }

    Show_Sv_Table(Class_Cur -> nameClass, Sv_Head);

    int user_Choose_Student ;
    string temp = "Y";
    cin.ignore();
    School_Year::Year_Class::SV_List* Temp_Sv = nullptr;
    do
    {
        delete Temp_Sv;
        Temp_Sv = new School_Year::Year_Class::SV_List;
        
        Space_5_Tab(); cout<<"You want to adjust your student due to: "<<endl;
        Space_5_Tab(); cout<<"     1: No"<<endl;
        Space_5_Tab(); cout<<"     2: ID Student"<<endl;
        Space_5_Tab(); cout<<"     3: Social ID"<<endl;
        Space_5_Tab(); cout<<"     4: Back"<<endl;
        Space_5_Tab(); cout<<"     Your Choice: ";
        
        cin>>user_Choose_Student;

        switch (user_Choose_Student)
        {
        
        case 1:
        {
            Space_5_Tab(); cout<<"\n Enter No: ";
            cin>>Temp_Sv -> no;

            break;
        }
        
        case 2:
        {
            Space_5_Tab(); cout<<"\n Enter Student ID: ";
            cin>>Temp_Sv -> idStudent;
            
            break;
        }

        case 3:
        {
            Space_5_Tab(); cout<<"\n Enter Social ID: ";
            cin>>Temp_Sv -> socialID;
        }
        default:
            return;
            break;
        }

        if (Check_Sv_Duplicated(Sv_Head,Temp_Sv)) 
        {
            Space_5_Tab(); cout<<"There arent any student match with your info. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            Space_5_Tab(); system("pause");
        }
    } while (Check_Sv_Duplicated(Sv_Head,Temp_Sv));

    School_Year::Year_Class::SV_List* Sv_Cur = find_Student(Sv_Head,Temp_Sv);

    cout<<endl;
    cin.ignore();
    do
    {
        Show_Sv_Table(Class_Cur -> nameClass, Sv_Head);

        int user_Choice; 
        Space_5_Tab(); cout<<"What do you want to change?"<<endl;
        Space_5_Tab(); cout<<"     1: Student ID."<<endl;
        Space_5_Tab(); cout<<"     2: Social ID."<<endl;
        Space_5_Tab(); cout<<"     3: First Name."<<endl;
        Space_5_Tab(); cout<<"     4: Last Name."<<endl;
        Space_5_Tab(); cout<<"     5: Gender."<<endl;
        Space_5_Tab(); cout<<"     6: Date of Birth."<<endl;
        Space_5_Tab(); cout<<"     7: Back."<<endl;
        Space_5_Tab(); cout<<"     Your answer: ";
        cin>>user_Choice;


        cin.ignore();
            Temp_Sv = new School_Year::Year_Class::SV_List;
        switch (user_Choice)
        {
            case 1:
            {
                Space_5_Tab(); cout<<"What do you want to change Student ID, from "<<Sv_Cur -> idStudent<<" to?"<<endl;
                Space_5_Tab(); cout<<"Enter Student ID: ";
                cin>>Temp_Sv -> idStudent;
                cin.ignore();

                if (!Check_Sv_Duplicated (Sv_Head,Temp_Sv))
                    {
                        Space_5_Tab(); cout<<"Your input is Incorrect. Please try again."<<endl;
                        
                        //Enter any key to continue and go back to  "Showing_School_Year"
                        Space_5_Tab(); system("pause");
                        cout<<"\n";

                        break;
                    }

                Sv_Cur -> idStudent = Temp_Sv -> idStudent;

                break;
            }
            
            case 3:
            {
                Space_5_Tab(); cout<<"What do you want to change First Name, from "<<Sv_Cur -> firstName<<" to?"<<endl;
                Space_5_Tab(); cout<<"Enter First Name: ";
                getline(cin,Temp_Sv -> firstName);

                if (!Check_Sv_Duplicated (Sv_Head,Temp_Sv))
                    {
                        Space_5_Tab(); cout<<"Your input is Incorrect. Please try again."<<endl;
                        
                        //Enter any key to continue and go back to  "Showing_School_Year"
                        Space_5_Tab(); system("pause");
                        cout<<"\n";

                        break;
                    }

                Sv_Cur -> firstName = Temp_Sv -> firstName ;

                break;
            }

            case 4:
            {
                Space_5_Tab(); cout<<"What do you want to change Last Name, from "<<Sv_Cur -> lastName<<" to?"<<endl;
                Space_5_Tab(); cout<<"Enter Last Name: ";
                getline(cin,Temp_Sv -> lastName);

                if (!Check_Sv_Duplicated (Sv_Head,Temp_Sv))
                    {
                        Space_5_Tab(); cout<<"Your input is Incorrect. Please try again."<<endl;
                        
                        //Enter any key to continue and go back to  "Showing_School_Year"
                        Space_5_Tab(); system("pause");
                        cout<<"\n";

                        break;
                    }

                Sv_Cur -> lastName = Temp_Sv -> lastName ;

                break;
            }

            case 5:
            {
                Space_5_Tab(); cout<<"What do you want to change Gender, from "<<Sv_Cur -> gender<<" to?"<<endl;
                Space_5_Tab(); cout<<"Enter Gender: ";
                getline(cin,Temp_Sv -> gender);

                if (!Check_Sv_Duplicated (Sv_Head,Temp_Sv))
                    {
                        Space_5_Tab(); cout<<"Your input is Incorrect. Please try again."<<endl;
                        
                        //Enter any key to continue and go back to  "Showing_School_Year"
                        Space_5_Tab(); system("pause");
                        cout<<"\n";

                        break;
                    }

                Sv_Cur-> gender = Temp_Sv -> gender ;

                break;
            }

            case 6:
            {
                Space_5_Tab(); cout<<"What do you want to change Date Of Birth, from "<<Sv_Cur -> dateOfBirth<<" to?"<<endl;
                Space_5_Tab(); cout<<"Enter Date Of Birth: ";
                getline(cin,Temp_Sv -> dateOfBirth);

                if (!Check_Sv_Duplicated (Sv_Head,Temp_Sv))
                    {
                        Space_5_Tab(); cout<<"Your input is Incorrect. Please try again."<<endl;
                        
                        //Enter any key to continue and go back to  "Showing_School_Year"
                        Space_5_Tab(); system("pause");
                        cout<<"\n";

                        break;
                    }

                Sv_Cur -> dateOfBirth = Temp_Sv -> dateOfBirth ;

                break;
            }

            case 2:
            {
                Space_5_Tab(); cout<<"What do you want to change Social ID, from "<<Sv_Cur -> socialID<<" to?"<<endl;
                Space_5_Tab(); cout<<"Enter Social ID: ";
                cin>>Temp_Sv -> socialID;
                cin.ignore();

                if (!Check_Sv_Duplicated (Sv_Head,Temp_Sv))
                    {
                        Space_5_Tab(); cout<<"Your input is Incorrect. Please try again."<<endl;
                        
                        //Enter any key to continue and go back to  "Showing_School_Year"
                        Space_5_Tab(); system("pause");
                        cout<<"\n";

                        break;
                    }

                Sv_Cur -> socialID = Temp_Sv -> socialID ;

                break;
            }

            default:
                {
                   Space_5_Tab();  system("pause");
                    return;
                    break;
                }
        }

        
        if (Check_Sv_Duplicated (Sv_Head,Temp_Sv))
        {
            cout<<endl;
            Space_5_Tab(); cout<<"Continue To Change Info Of This Course?"<<endl;
            Space_5_Tab(); cout<<"Enter (Y/N): "; 
            getline(cin,temp);
        }

    } while (!Check_Sv_Duplicated (Sv_Head, Temp_Sv) && temp == "Y");
    
    cout<<"\n";
    Space_5_Tab(); cout<<"Change Success"<<endl;

    Space_5_Tab(); system("pause");
    return;

}

//Delete SV_list
void Delete_Sv_List(School_Year::Year_Class* &Class_Cur, School_Year::Year_Class::SV_List* &Sv_Head)
{
    if (Sv_Head == nullptr)
    {
        Space_5_Tab(); cout<<"There are nothing to be deleted. Please Create One.";
        Space_5_Tab(); system("pause");
        return;
    }

    Show_Sv_Table(Class_Cur -> nameClass, Sv_Head);

    int user_Choose_Student ;
    cin.ignore();
    School_Year::Year_Class::SV_List* Temp_Sv = nullptr;
    do
    {
        delete Temp_Sv;
        Temp_Sv = new School_Year::Year_Class::SV_List;
        
        Space_5_Tab(); cout<<"You want to delete your student due to: "<<endl;
        Space_5_Tab(); cout<<"     1: No"<<endl;
        Space_5_Tab(); cout<<"     2: ID Student"<<endl;
        Space_5_Tab(); cout<<"     3: Social ID"<<endl;
        Space_5_Tab(); cout<<"     4: Back"<<endl;
        Space_5_Tab(); cout<<"     Your Choice: ";
        
        cin>>user_Choose_Student;

        switch (user_Choose_Student)
        {
        
        case 1:
        {
            Space_5_Tab(); cout<<"\n Enter No: ";
            cin>>Temp_Sv -> no;

            break;
        }
        
        case 2:
        {
            Space_5_Tab(); cout<<"\n Enter Student ID: ";
            cin>>Temp_Sv -> idStudent;
            
            break;
        }

        case 3:
        {
            Space_5_Tab(); cout<<"\n Enter Social ID: ";
            cin>>Temp_Sv -> socialID;
        }
        default:
            return;
            break;
        }

        if (Check_Sv_Duplicated(Sv_Head,Temp_Sv)) 
        {
            Space_5_Tab(); cout<<"There arent any student match with your info. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            Space_5_Tab(); system("pause");
        }
    } while (Check_Sv_Duplicated(Sv_Head,Temp_Sv));
    
    School_Year::Year_Class::SV_List* Sv_Cur = find_Student(Sv_Head,Temp_Sv);

    if (Sv_Cur == Sv_Head)
    {
        if (Sv_Head -> Next == nullptr)
        {
            Sv_Head = nullptr;
            Class_Cur -> yearClassSV_ListHead = Sv_Head;
            
            Space_5_Tab(); system("pause");
            return;
        }

        Sv_Head = Sv_Head -> Next;
        Sv_Head -> Prev = nullptr;  
        Class_Cur -> yearClassSV_ListHead = Sv_Head;

            Space_5_Tab(); system("pause");
            return;
    }

    Temp_Sv = Sv_Cur;

    Sv_Cur -> Prev -> Next = Temp_Sv -> Next;

    delete Temp_Sv;

    Space_5_Tab(); system("pause");
    return;
}

//View Classes - ᕦ(ò_óˇ)ᕤ
void View_Classes(string user_School_Year,School_Year::Year_Class* &Classes_Head)
{
    //Use a checking var to ignore line
    bool Check_Ignore = false;

    //Show Classes Table
    Showing_Classes:
    if (!Check_Classes(Classes_Head)) 
        {
            Space_5_Tab(); cout<<"Nothing being added"<<endl;
            Space_5_Tab(); system("Pause");
            return ;
        }
            else 
                {
                    Show_Classes_Table(user_School_Year,Classes_Head);
                }
    //Next step
        string user_Choosed_Class = "";
        
        if (!Check_Ignore) cin.ignore();
    do
    {
        //Menu of User choice about School-Year they want to view
            Space_5_Tab(); cout<<"Which Class you want to view info. Ex: 21clc01"<<endl;
            Space_5_Tab(); cout<<"Note: If you dont want to choose any class pls Enter 'N' "<<endl;
            Space_5_Tab(); cout<<"Enter answer: ";

            getline(cin,user_Choosed_Class);

        if (user_Choosed_Class == "N") return;

        //Check if the user choosed Year is existed - True is it not Duplicated which mean the Data is Incorrect
        if (Check_Classes_Duplicated(Classes_Head,user_Choosed_Class)) 
        {
            Space_5_Tab(); cout<<"Your input Classes: "<<user_Choosed_Class<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            Space_5_Tab(); system("pause");
            Check_Ignore = true;
            goto Showing_Classes;
        }

    } while (Check_Classes_Duplicated(Classes_Head,user_Choosed_Class));
    
    //Menu for student list in specific classes - 📲
    int user_Choose = 0;
    School_Year::Year_Class* Classes_Cur = find_Classes(Classes_Head,user_Choosed_Class); // To locate the classes user is choosing
    School_Year::Year_Class::SV_List* Sv_Head = Classes_Cur -> yearClassSV_ListHead; //To view or create. 

    while (user_Choose != 5)
    {
        cout<<endl<<endl;

        //Classes Table
        Show_Classes_Table(user_School_Year,Classes_Head);

        //Sv_List
        if (Sv_Head != nullptr)
        {
            Show_Sv_Table(user_Choosed_Class, Sv_Head);
        }

        Space_11_Tab(); cout<<"   Menu Functions To Control Student List Elements In A Class"<<endl;
        Space_11_Tab(); cout<<"      1: View Info Student In Class: "<<user_Choosed_Class<<endl;
        Space_11_Tab(); cout<<"      2: Create Student List For: "<<user_Choosed_Class<<endl;
        Space_11_Tab(); cout<<"      3: Adjust Student List In: "<<user_Choosed_Class<<endl;
        Space_11_Tab(); cout<<"      4: Delete Student In: "<<user_Choosed_Class<<endl;
        Space_11_Tab(); cout<<"      5: Back"<<endl;
        Space_11_Tab(); cout<<"      Your choice: "; 

        cin>>user_Choose;

        cout<<endl;

        //Switch user_Choose
            switch (user_Choose)
            {
            
            //View Sv_List 
                case 1:
                {
                    //Declare
                    School_Year::Year_Class* Classes_Cur = find_Classes(Classes_Head,user_Choosed_Class);

                    //Functions View_SV_List
                    View_Sv_List(user_Choosed_Class, Classes_Cur -> yearClassSV_ListHead);

                    continue;

                    break;
                }

                //Create Classes
                case 2:
                {
                    //Ask user whether he want to import a csv or manual
                    int user_Prefer = 0;
                    Space_5_Tab(); cout<<"\t Which one do you prefer: Manual (1) or Quick Import a CSV File (2)"<<endl;
                    Space_5_Tab(); cout<<"Your answer: ";
                    cin>>user_Prefer;

                    switch (user_Prefer)
                        {
                        case 1:
                        {
                            //Declare
                            School_Year::Year_Class* Classes_Cur = find_Classes(Classes_Head,user_Choosed_Class);

                            //Functions Create_SV_List
                            Create_Sv_List_Manual (Classes_Cur,Sv_Head);

                            break;
                        }
                        
                        case 2:
                        {
                            //Notice and rule
                            Space_5_Tab();  cout<<"To import a CSV there is a rule: No , ID_Student , First Name , Last Name , Gender , Date of Birth , Social ID"<<endl;
                            sleep_until( system_clock::now() + seconds(1) );
                            Space_5_Tab();  cout<<"Notice: If u havent Import in CSV_File/Student_Info.csv, now it's your time! then continue"<<endl;

                            Space_5_Tab();  system("pause");
                            //Declare
                            School_Year::Year_Class* Classes_Cur = find_Classes(Classes_Head,user_Choosed_Class);

                            //Functions Create_SV_List
                            Create_Sv_List_Import (Classes_Cur,Sv_Head);

                            break;
                        }
                        
                        default:
                            break;
                        }
                    
                    continue;

                    break;
                }
            
            case 3:
                {
                    //Declare
                    School_Year::Year_Class* Classes_Cur = find_Classes(Classes_Head,user_Choosed_Class);

                    //Functions Adjust_SV_List
                    Adjust_Sv_List (Classes_Cur,Sv_Head);

                    continue;
                    
                    break;
                }

             case 4:
                {
                    //Declare
                    School_Year::Year_Class* Classes_Cur = find_Classes(Classes_Head,user_Choosed_Class);

                    //Functions Delete_SV_List
                    Delete_Sv_List (Classes_Cur,Sv_Head);

                    continue;
                    
                    break;
                }

            default:

                break;
            }
    }
    Space_5_Tab();  cout<<"Ending Menu Student List..."<<endl;
    Space_5_Tab();  system("pause");
    
    //End of this funcs
    return;
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
                Space_5_Tab();  cout<<"Noted: Valided classes name (21clc01,..) if the school year was: 2021 - 2022 "<<endl;
                Space_5_Tab();  cout<<"Your school year chosen: "<<Year_Cur -> year<<" . Enter Classes Name: ";
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
                Space_5_Tab();  cout<<"Noted: Valided classes name (21clc01,..) if the school year was: 2021 - 2022 "<<endl;
                Space_5_Tab();  cout<<"Your school year chosen: "<<Year_Cur -> year<<" . Enter Classes Name: ";
                getline(cin,user_input);
                
                //Check if the data is corrected - If not the funcs will automatically delete the data
                if (user_input.substr(0,2) != Year_Cur -> year . substr(2,2)) return ;

                //Convert string -> char*
                char* input = new char [user_input.size()];
                strcpy( input,user_input.c_str() );

                //Strtok
                const char* denim = "-";
                contain = strtok(input,denim);

                //Print out remind user to enter value again
                if (!Check_Classes_Duplicated(Classes_Head,contain)) 
                    {
                        Space_5_Tab();  cout<<"Your data has been duplicated. Pls retry."<<endl<<endl;
                    }

            } while ( !Check_Classes_Duplicated(Classes_Head,contain) );

            //Check if Next Classes is havent existed
            while (Classes_Cur -> Next != nullptr) Classes_Cur = Classes_Cur -> Next;

            //Create Next Classes and dont forget do store the Prev
            Classes_Cur -> Next = new School_Year::Year_Class;
            Classes_Cur -> Next -> Prev = Classes_Cur;
            Classes_Cur = Classes_Cur -> Next;
            
            Classes_Cur -> nameClass = contain;

            return;
}

//Delete Classes - ε=( o｀ω′)ノ
void Delete_Classes(School_Year* &sYear_Cur,School_Year::Year_Class* &Classes_Head)
{
    if (Classes_Head == nullptr)
    {
        Space_5_Tab();  cout<<"There are nothing to be deleted. Please Create One.";
        Space_5_Tab();  system("pause");
        return;
    }

    bool Check_Ignore = false;
    string user_Choose_Class = "";
        
        if (!Check_Ignore) cin.ignore();
    do
    {
        //Menu of User choice about School-Year they want to view
            Space_5_Tab();  cout<<"Which Class you want to Delete. Ex: 21clc09"<<endl;
            Space_5_Tab();  cout<<"Note: If you dont want to choose any class pls Enter 'N' "<<endl;
            Space_5_Tab();  cout<<"Enter answer: ";

            getline(cin,user_Choose_Class);

        if (user_Choose_Class == "N") return;

        //Check if the user choosed Year is existed - True is it not Duplicated which mean the Data is Incorrect
        if (Check_Classes_Duplicated(Classes_Head,user_Choose_Class)) 
        {
            Space_5_Tab();  cout<<"Your input Class: "<<user_Choose_Class<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            Space_5_Tab();  system("pause");
            Check_Ignore = true;
        }

    } while (Check_Classes_Duplicated(Classes_Head,user_Choose_Class));

    School_Year::Year_Class* Class_Cur = find_Classes(Classes_Head,user_Choose_Class);

    //Delete all element
    Delete_Element_Of_YearClass(Class_Cur,2);

    if (Class_Cur == Classes_Head)
    {
        if (Class_Cur -> Next == nullptr)
            {
                Classes_Head = nullptr;
                sYear_Cur -> yearCLassHead = Classes_Head;
                Space_5_Tab();  system("pause");
                return;
            }

        Classes_Head = Classes_Head -> Next;
        sYear_Cur -> yearCLassHead = Classes_Head;
        Space_5_Tab();  system("pause");
        return;
    }

    School_Year::Year_Class* Temp_Class = Class_Cur;

    Class_Cur ->  Prev -> Next = Temp_Class -> Next;

    delete Temp_Class;

    Space_5_Tab();  system("pause");
    return;
}

//Adjust Classes
void Adjust_Classes(School_Year* &sYear_Cur,School_Year::Year_Class* &Classes_Head)     
{
    if (Classes_Head == nullptr)
    {
        Space_5_Tab();  cout<<"There are nothing to be adjusted. Please Create One.";
        Space_5_Tab();  system("pause");
        return;
    }

    bool Check_Ignore = false;
    string user_Choose_Class = "";
        
        if (!Check_Ignore) cin.ignore();
        
        if (Classes_Head != nullptr)
        {
            Show_Classes_Table(sYear_Cur -> year,Classes_Head);
        }
    do
    {
        //Menu of User choice about School-Year they want to view
            Space_5_Tab();  cout<<"Which Class you want to Adjust. Ex: 21clc09 "<<endl;
            Space_5_Tab();  cout<<"Note: If you dont want to choose any class pls Enter 'N' "<<endl;
            Space_5_Tab();  cout<<"Enter answer: ";

            getline(cin,user_Choose_Class);

        if (user_Choose_Class == "N") return;

        //Check if the user choosed Year is existed - True is it not Duplicated which mean the Data is Incorrect
        if (Check_Classes_Duplicated(Classes_Head,user_Choose_Class)) 
        {
            Space_5_Tab();  cout<<"Your input class: "<<user_Choose_Class<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            Space_5_Tab();  system("pause");
            cout<<"\n";
            Check_Ignore = true;
        }
    } while (Check_Classes_Duplicated(Classes_Head,user_Choose_Class));

    cout<<"\n";
    School_Year::Year_Class* Class_Cur = find_Classes(Classes_Head,user_Choose_Class);

    string user_Another_Class;
    do
    {
        //Menu of User choice about School-Year they want to view
            Show_Classes_Table(sYear_Cur -> year,Classes_Head);
            Space_7_Tab();  cout<<"What do you want to change from "<<user_Choose_Class<<" to ?. Ex: 21clc09 -> 21clc10. ";
            cout<<"Note: If you dont want to change pls Enter 'N' "<<endl;
            Space_13_Tab();  cout<<"  Enter answer: ";

            getline(cin,user_Another_Class);

        if (user_Another_Class == "N") return;

        //Check if the data is corrected
        if (user_Another_Class.substr(0,2) != sYear_Cur -> year . substr(2,2)) return ;


        //Check if the user choosed Year is existed - True is it not Duplicated which mean the Data is Incorrect
        if (!Check_Classes_Duplicated(Classes_Head,user_Another_Class)) 
        {
            Down_2_Line();
            Space_5_Tab();  cout<<"Your input Class: "<<user_Another_Class<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            Space_5_Tab();  system("pause");
            cout<<"\n";
            Check_Ignore = true;
        }
    } while (!Check_Classes_Duplicated(Classes_Head,user_Another_Class));

    Class_Cur -> nameClass = user_Another_Class;

    cout<<"\n";
    Space_5_Tab();  cout<<"Change Success"<<endl;

    Space_5_Tab();  system("pause");
    return;
}

//View Course
void View_Course(string user_Semester, School_Year::Semester::Subject* Subject_Head)
{
    //Show SV Table
    if (Subject_Head == nullptr) 
        {
            Space_5_Tab();  cout<<"Nothing being added"<<endl;
            Space_5_Tab();  system("Pause");
            return ;
        }
            else 
                {
                   system("CLS");
                   Show_Subject_Table(user_Semester,Subject_Head);
                }
    Space_5_Tab();  system("pause");
}

//Create Course Manual
void Create_Course_Manual(School_Year::Semester* &ySemester_Cur, School_Year::Semester::Subject* &Subject_Head)
{
    //Declare
    School_Year::Semester::Subject* Subject_Cur = Subject_Head;

    if (Subject_Head == nullptr)
        {
            Space_5_Tab();  cout<<"Your Semster: "<<ySemester_Cur -> Term<<endl;

            //Declare
            string name_Subject, id_Subject;
            string startDate, endDate;
            string teacher_Name;
            string day_Of_Session_1, day_Of_Session_2; // Mon/Tue/Wed
            string at_Time_1, at_Time_2; //S1(7:30) S2(9:30) S3(13:30) S4(15:30)
    
            int maximumRegrister, number_Of_Credit;

            //Enter Data
            Space_5_Tab();  cout<<"Course ID: ";
                cin.ignore();
            getline(cin,id_Subject);

            Space_5_Tab();  cout<<"Course Name: ";
            getline(cin,name_Subject);

            Space_5_Tab();  cout<<"Teacher Name: ";
            getline(cin,teacher_Name);

            Space_5_Tab();  cout<<"Start Date: ";
            getline(cin,startDate);

            Space_5_Tab();  cout<<"End Date: ";
            getline(cin,endDate);

            Input_SessionHead:
            Space_5_Tab();  cout<<"Day of Session 1 (Mon/Tue/Wed/..): ";
            getline(cin,day_Of_Session_1);

            Space_5_Tab();  cout<<"At what time of Session 1 { S1(7:30) S2(9:30) S3(13:30) S4(15:30) }"<<endl;
            Space_5_Tab();  cout<<"Enter: ";
            getline(cin,at_Time_1);

            Space_5_Tab();  cout<<"Day of Session 2 (Mon/Tue/Wed/..): ";
            getline(cin,day_Of_Session_2);

            Space_5_Tab();  cout<<"At what time of Session 2 { S1(7:30) S2(9:30) S3(13:30) S4(15:30) }"<<endl;
            Space_5_Tab();  cout<<"Enter: ";
            getline(cin,at_Time_2);

            //Check if duplicated time
            if (day_Of_Session_1 == day_Of_Session_2 && at_Time_1 == at_Time_2)
                {
                    Space_5_Tab();  cout<<"Your input time is Incorrect. Please Try Again."<<endl;
                    Space_5_Tab();  system("pause");
                    cout<<endl;
                    goto Input_SessionHead;
                }
            
            Space_5_Tab();  cout<<"Maximum number of student in this course: ";
            cin>>maximumRegrister;

            Space_5_Tab();  cout<<"Number of credits: ";
            cin>>number_Of_Credit;

            Subject_Head = new School_Year::Semester::Subject;

            //Assign data
            Subject_Head -> id_Subject = id_Subject;
            Subject_Head -> name_Subject = name_Subject;
            Subject_Head -> teacher_Name = teacher_Name;
            Subject_Head -> startDate = startDate;
            Subject_Head -> endDate = endDate;
            Subject_Head -> day_Of_Session_1 = day_Of_Session_1;
            Subject_Head -> at_Time_1 = at_Time_1;
            Subject_Head -> day_Of_Session_2 = day_Of_Session_2;
            Subject_Head -> at_Time_2 = at_Time_2;
            Subject_Head -> maximumRegrister = maximumRegrister;
            Subject_Head -> number_Of_Credit = number_Of_Credit;

            ySemester_Cur -> yearSemesterSubjectHead = Subject_Head;

            return;
        }

     //Check if Next SV_List is havent existed
            while (Subject_Cur -> Next != nullptr) Subject_Cur = Subject_Cur -> Next;

            //Create Next Classes and dont forget do store the Prev
            Subject_Cur -> Next = new School_Year::Semester::Subject;
            Subject_Cur -> Next -> Prev = Subject_Cur;
            Subject_Cur = Subject_Cur -> Next;

    //Check if value is being duplicated or not?
    do
    {   
        cout<<endl;
        Space_5_Tab();  
        cout<<"Your Semster: "<<ySemester_Cur -> Term<<endl;

            //Declare
            string name_Subject, id_Subject;
            string startDate, endDate;
            string teacher_Name;
            string day_Of_Session_1, day_Of_Session_2; // Mon/Tue/Wed
            string at_Time_1, at_Time_2; //S1(7:30) S2(9:30) S3(13:30) S4(15:30)
    
            int maximumRegrister, number_Of_Credit;


            //Enter Data
            Space_5_Tab(); cout<<"Course ID: ";
                cin.ignore();
            getline(cin,id_Subject);

            Space_5_Tab(); cout<<"Course Name: ";
            getline(cin,name_Subject);

            Space_5_Tab(); cout<<"Teacher Name: ";
            getline(cin,teacher_Name);

            Space_5_Tab(); cout<<"Start Date: ";
            getline(cin,startDate);

            Space_5_Tab(); cout<<"End Date: ";
            getline(cin,endDate);

            Input_SessionCur:

            Space_5_Tab(); cout<<"Day of Session 1 (Mon/Tue/Wed/..): ";
            getline(cin,day_Of_Session_1);

            Space_5_Tab(); cout<<"At what time of Session 1 { S1(7:30) S2(9:30) S3(13:30) S4(15:30) }"<<endl;
            Space_5_Tab(); cout<<"Enter: ";
            getline(cin,at_Time_1);

            Space_5_Tab(); cout<<"Day of Session 2 (Mon/Tue/Wed/..): ";
            getline(cin,day_Of_Session_2);

            Space_5_Tab(); cout<<"At what time of Session 2 { S1(7:30) S2(9:30) S3(13:30) S4(15:30) }"<<endl;
            Space_5_Tab(); cout<<"Enter: ";
            getline(cin,at_Time_2);

            //Check if duplicated time
            if (day_Of_Session_1 == day_Of_Session_2 && at_Time_1 == at_Time_2)
                {
                    Space_5_Tab(); cout<<"Your input time is Incorrect. Please Try Again."<<endl;
                    Space_5_Tab(); system("pause");
                    cout<<endl;
                    goto Input_SessionCur;
                }
            
            Space_5_Tab(); cout<<"Maximum number of student in this course: ";
            cin>>maximumRegrister;

            Space_5_Tab(); cout<<"Number of credits: ";
            cin>>number_Of_Credit;

            //Assign data
            Subject_Cur -> id_Subject = id_Subject;
            Subject_Cur -> name_Subject = name_Subject;
            Subject_Cur -> teacher_Name = teacher_Name;
            Subject_Cur -> startDate = startDate;
            Subject_Cur -> endDate = endDate;
            Subject_Cur -> day_Of_Session_1 = day_Of_Session_1;
            Subject_Cur -> at_Time_1 = at_Time_1;
            Subject_Cur -> day_Of_Session_2 = day_Of_Session_2;
            Subject_Cur -> at_Time_2 = at_Time_2;
            Subject_Cur -> maximumRegrister = maximumRegrister;
            Subject_Cur -> number_Of_Credit = number_Of_Credit;


        //Print out remind user to enter value again
        if (!Check_Subject_Duplicated_Input(Subject_Head,Subject_Cur)) 
        
        {
            Space_5_Tab(); 
            cout<<"Your data has been duplicated. Pls retry."<<endl<<endl;
        }
   
    } while ( !Check_Subject_Duplicated_Input(Subject_Head,Subject_Cur) );

    return;

}

//Create Course Import
void Create_Course_Import(School_Year::Semester* &ySemester_Cur, School_Year::Semester::Subject* &Subject_Head)
{
    //Declare
    string name_Subject, id_Subject;
    string startDate, endDate;
    string teacher_Name;
    string day_Of_Session_1, day_Of_Session_2; // Mon/Tue/Wed
    string at_Time_1, at_Time_2; //S1(7:30) S2(9:30) S3(13:30) S4(15:30)

    int maximumRegrister = 50, number_Of_Credit;

    fstream  finp;

    finp.open("./CSV_File/Course_Info.csv", ios::in);

    if (!finp.is_open())
        {
            Space_5_Tab(); cout<<"The file is empty, Please import the data"<<endl;
            return;
        }
    while (!finp.eof())
    {
         //Declared
        School_Year::Semester::Subject* Subject_Cur = Subject_Head;

        if (Subject_Head == nullptr)
        {
            Subject_Head = new School_Year::Semester::Subject;

            string line_input = "";
            getline(finp, line_input); //Skip 1 line
            getline(finp, line_input); 

            //Convert str -> char*;
            char* input = new char [ line_input.size() ];
            strcpy(input,line_input.c_str());

            //Set denim
            const char* denim = ",";

            //Get Data
            id_Subject = strtok(input,denim);
            name_Subject = strtok(NULL,denim);
            teacher_Name = strtok(NULL,denim);
            startDate = strtok(NULL,denim);
            endDate = strtok(NULL,denim);
            day_Of_Session_1 = strtok(NULL,denim);
            at_Time_1 = strtok(NULL,denim);
            day_Of_Session_2 = strtok(NULL,denim);
            at_Time_2 = strtok(NULL,denim);
            number_Of_Credit = atoi( strtok(NULL,denim) );
            maximumRegrister = atoi( strtok(NULL,denim) );

            //Assign
            Subject_Head -> id_Subject =  id_Subject;
            Subject_Head -> name_Subject = name_Subject;
            Subject_Head -> teacher_Name = teacher_Name;
            Subject_Head -> startDate = startDate;
            Subject_Head -> endDate = endDate;
            Subject_Head -> day_Of_Session_1 = day_Of_Session_1;
            Subject_Head -> at_Time_1 = at_Time_1;
            Subject_Head -> day_Of_Session_2 = day_Of_Session_2;
            Subject_Head -> at_Time_2 = at_Time_2;
            Subject_Head ->  number_Of_Credit = number_Of_Credit;
            Subject_Head -> maximumRegrister = maximumRegrister;

            //Head
            ySemester_Cur -> yearSemesterSubjectHead = Subject_Head;

            continue; 
        }

        //Get Data
        string line_input = "";
        getline(finp, line_input); //Skip 1 line
        getline(finp, line_input); 

        //Convert str -> char*;
        char* input = new char [ line_input.size() ];
        strcpy(input,line_input.c_str());

        //Set denim
        const char* denim = ",";

        //Create new node
        while (Subject_Cur -> Next != nullptr) Subject_Cur = Subject_Cur -> Next;
        Subject_Cur -> Next = new School_Year::Semester::Subject;
        Subject_Cur -> Next -> Prev = Subject_Cur;
        Subject_Cur = Subject_Cur -> Next;

        //Get Data
        id_Subject = strtok(input,denim);
        name_Subject = strtok(NULL,denim);
        teacher_Name = strtok(NULL,denim);
        startDate = strtok(NULL,denim);
        endDate = strtok(NULL,denim);
        day_Of_Session_1 = strtok(NULL,denim);
        at_Time_1 = strtok(NULL,denim);
        day_Of_Session_2 = strtok(NULL,denim);
        at_Time_2 = strtok(NULL,denim);
        number_Of_Credit = atoi( strtok(NULL,denim) );
        maximumRegrister = atoi( strtok(NULL,denim) );

        //Assign
        Subject_Cur -> id_Subject =  id_Subject;
        Subject_Cur -> name_Subject = name_Subject;
        Subject_Cur -> teacher_Name = teacher_Name;
        Subject_Cur -> startDate = startDate;
        Subject_Cur -> endDate = endDate;
        Subject_Cur -> day_Of_Session_1 = day_Of_Session_1;
        Subject_Cur -> at_Time_1 = at_Time_1;
        Subject_Cur -> day_Of_Session_2 = day_Of_Session_2;
        Subject_Cur -> at_Time_2 = at_Time_2;
        Subject_Cur ->  number_Of_Credit = number_Of_Credit;
        Subject_Cur -> maximumRegrister = maximumRegrister;
    }

    finp.close();

    return;
}

//Adjust Course 
void Adjust_Course(School_Year::Semester* ySemester_Cur, School_Year::Semester::Subject* &Subject_Head)
{
    if (ySemester_Cur == nullptr)
    {
        Space_5_Tab(); cout<<"There are nothing to be adjusted. Please Create One";
        Space_5_Tab(); system("pause");
        return;
    }

    system("CLS");
     Show_Subject_Table(to_string(ySemester_Cur -> Term), Subject_Head);
    bool Check_Ignore = false;
    string user_Choose_Course = "";
    School_Year::Semester::Subject* Subject_Temp = new School_Year::Semester::Subject;
        
        cin.ignore();
    do
    {
        //Menu of User choice about School-Year they want to view
            Space_5_Tab(); cout<<"Which Course you want to Adjust. Ex: PHY0001 "<<endl;
            Space_5_Tab(); cout<<"Note: If you dont want to choose any Course pls Enter 'N' "<<endl;
            Space_5_Tab(); cout<<"Enter Course ID: ";

            getline(cin,user_Choose_Course);


        if (user_Choose_Course == "N") return;

        Subject_Temp -> id_Subject = user_Choose_Course;

        //Check if the user choosed Year is existed - True is it not Duplicated which mean the Data is Incorrect
        if (Check_Subject_Duplicated(Subject_Head,Subject_Temp)) 
        {
            Space_5_Tab(); cout<<"Your input Course: "<<Subject_Temp -> id_Subject<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            Space_5_Tab(); system("pause");
            cout<<"\n";
        }
    } while (Check_Subject_Duplicated(Subject_Head,Subject_Temp));


    cout<<"\n";
    School_Year::Semester::Subject* Subject_ToFind = new School_Year::Semester::Subject;
    Subject_ToFind -> id_Subject = user_Choose_Course;

    School_Year::Semester::Subject* Subject_Cur = find_Subject(Subject_Head,Subject_ToFind);

    //Delete 
    delete Subject_ToFind;

    //Declare
    string temp = "Y";

    do
    {
        //Show table
        Show_Specific_Subject_Table(to_string(ySemester_Cur -> Term),Subject_Head,Subject_Cur);

        int user_Choice; 
        Space_5_Tab(); cout<<"What do you want to change?"<<endl;
        Space_5_Tab(); cout<<"     1: Course ID."<<endl;
        Space_5_Tab(); cout<<"     2: Course Name."<<endl;
        Space_5_Tab(); cout<<"     3: Teacher Name."<<endl;
        Space_5_Tab(); cout<<"     4: Start Date."<<endl;
        Space_5_Tab(); cout<<"     5: End Date."<<endl;
        Space_5_Tab(); cout<<"     6: Day Of Session 1."<<endl;
        Space_5_Tab(); cout<<"     7: Time of Day's Session 1."<<endl;
        Space_5_Tab(); cout<<"     8: Day Of Session 2."<<endl;
        Space_5_Tab(); cout<<"     9: Time of Day's Session 2."<<endl;
        Space_5_Tab(); cout<<"     10: Number of Credits."<<endl;
        Space_5_Tab(); cout<<"     11: Maximum Student Number."<<endl;
        Space_5_Tab(); cout<<"     12: Back."<<endl;
        Space_5_Tab(); cout<<"     Your answer: ";
        cin>>user_Choice;
        
        cout<<"\n";

            cin.ignore();
            Subject_ToFind = new School_Year::Semester::Subject;

        switch (user_Choice)
        {
            case 1:
            {
                Space_5_Tab(); cout<<"What do you want to change Course ID, from "<<Subject_Cur -> id_Subject<<" to?"<<endl;
                Space_5_Tab(); cout<<"Enter Course ID: ";
                getline(cin,Subject_ToFind -> id_Subject);

                if (!Check_Subject_Duplicated(Subject_Head,Subject_ToFind))
                    {
                        Space_5_Tab(); cout<<"Your input is Incorrect. Please try again."<<endl;
                        
                        //Enter any key to continue and go back to  "Showing_School_Year"
                        Space_5_Tab(); system("pause");
                        cout<<"\n";

                        break;
                    }

                Subject_Cur -> id_Subject = Subject_ToFind -> id_Subject;

                break;
            }
            
            case 2:
            {
                Space_5_Tab(); cout<<"What do you want to change Course Name, from "<<Subject_Cur -> name_Subject<<" to?"<<endl;
                Space_5_Tab(); cout<<"Enter Course Name: ";
                getline(cin,Subject_ToFind -> name_Subject);

                if (!Check_Subject_Duplicated(Subject_Head,Subject_ToFind))
                    {
                        Space_5_Tab(); cout<<"Your input is Incorrect. Please try again."<<endl;
                        
                        //Enter any key to continue and go back to  "Showing_School_Year"
                        Space_5_Tab(); system("pause");
                        cout<<"\n";

                        break;
                    }

                Subject_Cur -> name_Subject = Subject_ToFind -> name_Subject ;

                break;
            }

            case 3:
            {
                Space_5_Tab(); cout<<"What do you want to change Teacher Name, from "<<Subject_Cur -> teacher_Name<<" to?"<<endl;
                Space_5_Tab(); cout<<"Enter Teacher Name: ";
                getline(cin,Subject_ToFind -> teacher_Name);

                if (!Check_Subject_Duplicated(Subject_Head,Subject_ToFind))
                    {
                        Space_5_Tab(); cout<<"Your input is Incorrect. Please try again."<<endl;
                        
                        //Enter any key to continue and go back to  "Showing_School_Year"
                        Space_5_Tab(); system("pause");
                        cout<<"\n";

                        break;
                    }

                Subject_Cur -> teacher_Name = Subject_ToFind -> teacher_Name ;

                break;
            }

            case 4:
            {
                Space_5_Tab(); cout<<"What do you want to change Start Date Of Course, from "<<Subject_Cur -> startDate<<" to?"<<endl;
                Space_5_Tab(); cout<<"Enter Start Date Of Course: ";
                getline(cin,Subject_ToFind -> startDate);


                if (!Check_Subject_Duplicated(Subject_Head,Subject_ToFind))
                    {
                        Space_5_Tab(); cout<<"Your input is Incorrect. Please try again."<<endl;
                        
                        //Enter any key to continue and go back to  "Showing_School_Year"
                        Space_5_Tab(); system("pause");
                        cout<<"\n";

                        break;
                    }

                Subject_Cur -> startDate = Subject_ToFind -> startDate ;

                break;
            }

            case 5:
            {
                Space_5_Tab(); cout<<"What do you want to change End Date Of Course, from "<<Subject_Cur -> endDate<<" to?"<<endl;
                Space_5_Tab(); cout<<"Enter End Date Of Course: ";
                getline(cin,Subject_ToFind -> endDate);

                if (!Check_Subject_Duplicated(Subject_Head,Subject_ToFind))
                    {
                        Space_5_Tab(); cout<<"Your input is Incorrect. Please try again."<<endl;
                        
                        //Enter any key to continue and go back to  "Showing_School_Year"
                        system("pause");
                        cout<<"\n";

                        break;
                    }

                Subject_Cur -> endDate = Subject_ToFind -> endDate ;

                break;
            }

            case 6:
            {
                Space_5_Tab(); cout<<"What do you want to change Day of Session 1 in week, from "<<Subject_Cur -> day_Of_Session_1<<" to?"<<endl;
                Space_5_Tab(); cout<<"Enter Day of Session 1 in week: ";
                getline(cin,Subject_ToFind -> day_Of_Session_1);

                if (!Check_Subject_Duplicated(Subject_Head,Subject_ToFind))
                    {
                        Space_5_Tab(); cout<<"Your input is Incorrect. Please try again."<<endl;
                        
                        //Enter any key to continue and go back to  "Showing_School_Year"
                        system("pause");
                        cout<<"\n";

                        break;
                    }

                Subject_Cur -> day_Of_Session_1 = Subject_ToFind -> day_Of_Session_1 ;

                break;
            }

            case 7:
            {
                Space_5_Tab(); cout<<"What do you want to change Time of Session 1, from "<<Subject_Cur -> at_Time_1<<" to?"<<endl;
                Space_5_Tab(); cout<<"Enter Time of Session 1: ";
                getline(cin,Subject_ToFind -> at_Time_1);

                if (!Check_Subject_Duplicated(Subject_Head,Subject_ToFind))
                    {
                        Space_5_Tab(); cout<<"Your input is Incorrect. Please try again."<<endl;
                        
                        //Enter any key to continue and go back to  "Showing_School_Year"
                        system("pause");
                        cout<<"\n";

                        break;
                    }

                Subject_Cur -> at_Time_1 = Subject_ToFind -> at_Time_1 ;

                break;
            }

            case 8:
            {
                Space_5_Tab(); cout<<"What do you want to change Day of Session 2 in week, from "<<Subject_Cur -> day_Of_Session_2<<" to?"<<endl;
                Space_5_Tab(); cout<<"Enter Day of Session 2 in week: ";
                getline(cin,Subject_ToFind -> day_Of_Session_2);

                if (!Check_Subject_Duplicated(Subject_Head,Subject_ToFind))
                    {
                        Space_5_Tab(); cout<<"Your input is Incorrect. Please try again."<<endl;
                        
                        //Enter any key to continue and go back to  "Showing_School_Year"
                        Space_5_Tab(); system("pause");
                        cout<<"\n";

                        break;
                    }

                Subject_Cur -> day_Of_Session_2 = Subject_ToFind -> day_Of_Session_2 ;

                break;
            }

            case 9:
            {
                Space_5_Tab(); cout<<"What do you want to change Time of Session 2, from "<<Subject_Cur -> at_Time_2<<" to?"<<endl;
                Space_5_Tab(); cout<<"Enter Time of Session 2: ";
                getline(cin,Subject_ToFind -> at_Time_2);

                if (!Check_Subject_Duplicated(Subject_Head,Subject_ToFind))
                    {
                        Space_5_Tab(); cout<<"Your input is Incorrect. Please try again."<<endl;
                        
                        //Enter any key to continue and go back to  "Showing_School_Year"
                        system("pause");
                        cout<<"\n";

                        break;
                    }

                Subject_Cur -> at_Time_2 = Subject_ToFind -> at_Time_2 ;

                break;
            }

            case 10:
            {
                Space_5_Tab(); cout<<"What do you want to change Number Of Credit, from "<<Subject_Cur -> number_Of_Credit<<" to?"<<endl;
                Space_5_Tab(); cout<<"Enter Number Of Credit: ";
                cin>>Subject_ToFind -> number_Of_Credit;
                cin.ignore();

                if (!Check_Subject_Duplicated(Subject_Head,Subject_ToFind))
                    {
                        Space_5_Tab(); cout<<"Your input is Incorrect. Please try again."<<endl;
                        
                        //Enter any key to continue and go back to  "Showing_School_Year"
                        Space_5_Tab(); system("pause");
                        cout<<"\n";

                        break;
                    }


                Subject_Cur -> number_Of_Credit = Subject_ToFind -> number_Of_Credit ;

                break;
            }

            case 11:
            {
                Space_5_Tab(); cout<<"What do you want to change Maximum Student Registration, from "<<Subject_Cur -> maximumRegrister<<" to?"<<endl;
                Space_5_Tab(); cout<<"Enter Maximum Student Registration: ";
                cin>>Subject_ToFind -> maximumRegrister;
                cin.ignore();

                if (!Check_Subject_Duplicated(Subject_Head,Subject_ToFind))
                    {
                        Space_5_Tab(); cout<<"Your input is Incorrect. Please try again."<<endl;
                        
                        //Enter any key to continue and go back to  "Showing_School_Year"
                        system("pause");
                        cout<<"\n";

                        break;
                    }

                Subject_Cur -> maximumRegrister = Subject_ToFind -> maximumRegrister ;

                break;
            }

            default:
                {
                    Space_5_Tab(); system("pause");
                    return;
                    break;
                }
        }

        
        if (Check_Subject_Duplicated(Subject_Head,Subject_ToFind))
        {
            cout<<endl;
            Space_5_Tab(); cout<<"Continue To Change Info Of This Course?"<<endl;
            Space_5_Tab(); cout<<"Enter (Y/N): "; 
            getline(cin,temp);
        }

    } while (!Check_Subject_Duplicated(Subject_Head, Subject_ToFind) && temp == "Y");
    

    cout<<"\n";
    Space_5_Tab(); cout<<"Change Success"<<endl;

    Space_5_Tab(); system("pause");
    return;
}

//Delete Course
void Delete_Course(School_Year::Semester* &ySemester_Cur, School_Year::Semester::Subject* &Subject_Head)
{
    if (Subject_Head == nullptr)
    {
        Space_5_Tab(); cout<<"There are nothing to be deleted. Please Create One.";
        Space_5_Tab(); system("pause");
        return;
    }

    system("CLS");
    Show_Subject_Table(to_string(ySemester_Cur -> Term), Subject_Head);
    string user_Choose_Course = "";
    School_Year::Semester::Subject* Subject_Temp = new School_Year::Semester::Subject;
        
    cin.ignore();
    do
    {
        //Menu of User choice about School-Year they want to view
            Space_5_Tab(); cout<<"Which Course you want to Delete, Enter Course ID. Ex: PHY0001 "<<endl;
            Space_5_Tab(); cout<<"Note: If you dont want to choose any Course pls Enter 'N' "<<endl;
            Space_5_Tab(); cout<<"Enter Course ID: ";

            getline(cin,user_Choose_Course);


        if (user_Choose_Course == "N") return;

        Subject_Temp -> id_Subject = user_Choose_Course;

        //Check if the user choosed Year is existed - True is it not Duplicated which mean the Data is Incorrect
        if (Check_Subject_Duplicated(Subject_Head,Subject_Temp)) 
        {
            Space_5_Tab(); cout<<"Your input Course: "<<Subject_Temp -> id_Subject<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            Space_5_Tab(); system("pause");
            cout<<"\n";
        }
    } while (Check_Subject_Duplicated(Subject_Head,Subject_Temp));

    School_Year::Semester::Subject* Subject_Cur = find_Subject(Subject_Head,Subject_Temp);

    //Delete all element
    Delete_Element_Of_Subject(Subject_Cur,2);

    if (Subject_Cur == Subject_Head)
    {
        if (Subject_Cur -> Next == nullptr)
            {
                Subject_Head = nullptr;
                ySemester_Cur -> yearSemesterSubjectHead = Subject_Head;

                Space_5_Tab(); system("pause");
                return;
            }

        Subject_Head = Subject_Head -> Next;
        ySemester_Cur -> yearSemesterSubjectHead = Subject_Head;

        Space_5_Tab(); system("pause");
        return;
    }

    School_Year::Semester::Subject* Temp_Sub = Subject_Cur;

    Subject_Cur ->  Prev -> Next = Temp_Sub -> Next;

    delete Temp_Sub;

    Space_5_Tab(); system("pause");
    return;

}

//View_Semester
void View_Semester(string user_School_Year,School_Year::Semester* &Semester_Head)
{
    //Use a checking var to ignore line
    bool Check_Ignore = false;

    //Show Semster Table
    Showing_Semester:
    if (Semester_Head == nullptr) 
        {
            Space_5_Tab(); cout<<"Nothing being added"<<endl;
            Space_5_Tab(); system("Pause");
            return ;
        }
            else 
                {
                    Show_Semester_Table(user_School_Year,Semester_Head);
                }
        
        string user_Choose_Temp ="";
        int user_Choose_Semester;
        if (!Check_Ignore) cin.ignore();
    do
    {
            Space_7_Tab(); cout<<"   Which Semester you want to view info. Ex: 1/2/3 "; 
            cout<<"Note: If you dont want to choose any class pls Enter 'N' "<<endl;
            Space_13_Tab(); cout<<"Enter answer: ";

            getline(cin,user_Choose_Temp);

        if (user_Choose_Temp == "N") return;

        user_Choose_Semester = atoi ( user_Choose_Temp .c_str());

        //Check if the user choosed Year is existed - True is it not Duplicated which mean the Data is Incorrect
        if (Check_Semester_Duplicated(Semester_Head,user_Choose_Semester)) 
        {
            Space_5_Tab(); cout<<"Your input Semester: "<<user_Choose_Semester<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            Space_5_Tab(); system("pause");
            Check_Ignore = true;
            goto Showing_Semester;
        }
    } while (Check_Semester_Duplicated(Semester_Head,user_Choose_Semester));
    
    //Menu Course
    int user_Choose =  0;
    School_Year::Semester* Semester_Cur = find_Semester(Semester_Head,user_Choose_Semester);
    School_Year::Semester::Subject* Course_Head = Semester_Cur -> yearSemesterSubjectHead;

    while (user_Choose != 5)
    {
        cout<<endl<<endl;

        //Semester Table
        Show_Semester_Table(user_School_Year,Semester_Head);

        if (Course_Head != nullptr)
        {
            system("CLS");
            Show_Subject_Table(to_string(user_Choose_Semester),Course_Head);
        }

        Space_11_Tab(); cout<<"  Menu Functions To Control Course Elements In A Chosen Semester"<<endl;
        Space_11_Tab(); cout<<"    1: View Info Course In Semester: "<<user_Choose_Semester<<endl;
        Space_11_Tab(); cout<<"    2: Create Course List For Semester: "<<user_Choose_Semester<<endl;
        Space_11_Tab(); cout<<"    3: Adjust Course List In Semester: "<<user_Choose_Semester<<endl;
        Space_11_Tab(); cout<<"    4: Delete Course In Semester: "<<user_Choose_Semester<<endl;
        Space_11_Tab(); cout<<"    5: Back"<<endl;
        Space_11_Tab(); cout<<"    Your choice: "; 

        cin>>user_Choose;

        cout<<endl;

        //Switch user choose
        switch (user_Choose)
        {
        //View Course
            case 1:
            {
                //Declare
                    School_Year::Semester* Semester_Cur = find_Semester(Semester_Head,user_Choose_Semester);

                    //Functions View_SV_List
                    View_Course(to_string(user_Choose_Semester), Semester_Cur -> yearSemesterSubjectHead);


                continue;

                break;
            }

        //Create Course
            case 2:
            {
                //Ask user whether he want to import a csv or manual
                    int user_Prefer = 0;
                    Space_5_Tab(); cout<<"\t Which one do you prefer: Manual (1) or Quick Import a CSV File (2)"<<endl;
                    Space_5_Tab(); cout<<"Your answer: ";
                    cin>>user_Prefer;

                    switch (user_Prefer)
                        {
                        case 1:
                        {
                            //Declare
                            School_Year::Semester* Semester_Cur = find_Semester(Semester_Head,user_Choose_Semester);

                            //Functions Create_SV_List
                            Create_Course_Manual (Semester_Cur,Course_Head);

                            break;
                        }
                        
                        case 2:
                        {
                            //Notice and rule
                            Space_5_Tab(); cout<<"To import a CSV there is a rule: Course Id, Course Name, Teacher Name, Number of credits, Maximum student, Day of week (Mon/Tue/..), At time (S1/S2/S3...)"<<endl;
                            sleep_until( system_clock::now() + seconds(1) );
                            Space_5_Tab(); cout<<"Notice: If u havent Import in CSV_File/Course_Info.csv, now it's your time! then continue"<<endl;

                            Space_5_Tab(); system("pause");

                            //Declare
                            School_Year::Semester* Semester_Cur = find_Semester(Semester_Head,user_Choose_Semester);

                            //Functions Create_SV_List
                            Create_Course_Import (Semester_Cur,Course_Head);

                            break;
                        }
                        
                        default:
                            break;
                        }
                    
                    continue;

                    break;

            }
        
        case 3:
        {

            //Declare
            School_Year::Semester* Semester_Cur = find_Semester(Semester_Head,user_Choose_Semester);

            //Functions Adjust Course
            Adjust_Course(Semester_Cur,Course_Head);

            continue;

            break;
        }

        case 4:
        {

            //Declare
            School_Year::Semester* Semester_Cur = find_Semester(Semester_Head,user_Choose_Semester);

            //Functions Delete Course
            Delete_Course(Semester_Cur,Course_Head);

            continue;

            break;
        }

        default:
            break;
        }
    }
    Space_5_Tab(); cout<<"Ending Menu Semester"<<endl;
    Space_5_Tab(); system("pause");

}

//Create Semester
void Create_Semester(School_Year* &Year_Cur, School_Year::Semester* &Semester_Head)
{
    //Declare
    int user_input = 0;
    School_Year::Semester* Semester_Cur = Semester_Head;

    //Case head == null
    if (Semester_Head == nullptr)
    {
        //Input
        do
        {
            Space_5_Tab(); cout<<"Remember, there are only 3 semster per School Year. If you want to back, Enter 0"<<endl;
            Space_5_Tab(); cout<<"Enter term (1/2/3): ";
            cin>>user_input;

            cout<<endl;

            if (user_input == 0) 
            {
                Space_5_Tab(); system("pause");
                return;
            }

            if (!Check_Semester_Duplicated(Semester_Head,user_input)) 
            {
                Space_5_Tab(); cout<<"Your data has been duplicated. Pls retry."<<endl<<endl;
            }
    

        } while (!Check_Semester_Duplicated(Semester_Head,user_input));

        Semester_Head = new School_Year::Semester;
        Semester_Head -> Term = user_input;

        cin.ignore();
        Space_5_Tab(); cout<<"Enter Start Date For This Semester: "; 
        getline(cin,Semester_Head -> start_Date);
        Space_5_Tab(); cout<<"Enter End Date For This Semester: "; 
        getline(cin,Semester_Head -> end_Date);

        Year_Cur -> yearSemesterHead = Semester_Head;

        return;
    }


    while (Semester_Cur -> Next != nullptr) Semester_Cur = Semester_Cur -> Next;

    //Input
        do
        {
            Space_5_Tab(); cout<<"Remember, there are only 3 semster per School Year."<<endl;
            Space_5_Tab(); cout<<"Enter term (1/2/3): ";
            cin>>user_input;

            cout<<endl;
            if (!Check_Semester_Duplicated(Semester_Head,user_input)) 
            {
                Space_5_Tab(); cout<<"Your data has been duplicated. Pls retry."<<endl<<endl;
            }
            

        } while (!Check_Semester_Duplicated(Semester_Head,user_input));

    //One school year only contain 3 semester
     if (Check_Num_Semester(Semester_Head) == 3) 
        {
            Space_5_Tab(); cout<<"There enough 3 semester in this school year. Thanks";
            Space_5_Tab(); system("pause");
            return;
        }

    Semester_Cur -> Next = new School_Year::Semester;
    Semester_Cur -> Next -> Prev = Semester_Cur;
    Semester_Cur = Semester_Cur -> Next;
    Semester_Cur -> Term = user_input;

    //Adding Start date, End Date
    cin.ignore();
    Space_5_Tab(); cout<<"Enter Start Date For This Semester: "; 
    getline(cin,Semester_Cur -> start_Date);
    Space_5_Tab(); cout<<"Enter End Date For This Semester: "; 
    getline(cin,Semester_Cur -> end_Date);

    return;
}

//Adjust Semster
void Adjust_Semester(School_Year* Year_Cur, School_Year::Semester* &Semester_Head)
{
    if (Semester_Head == nullptr)
    {
        Space_5_Tab(); cout<<"There are nothing to be adjusted. Please Create One.";
        Space_5_Tab(); system("pause");
        return;
    }

    Show_Semester_Table(Year_Cur -> year, Semester_Head);

    string user_Choose_Semester = "";
    cin.ignore();
    do
    {
        Space_7_Tab(); cout<<"Which Semester you want to Adjust. Ex: 1/2/3. "; 
        cout<<"Note: If you dont want to choose any Term pls Enter 'N' "<<endl;
        Space_11_Tab(); cout<<"Enter answer: "; 
        getline(cin,user_Choose_Semester);

        if (user_Choose_Semester == "N") return;

        if (Check_Semester_Duplicated( Semester_Head,stoi(user_Choose_Semester) )) 
        {
            Space_5_Tab(); cout<<"Your input Semester: "<<user_Choose_Semester<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            Space_5_Tab(); system("pause");
            cout<<"\n";
        }

    } while (Check_Semester_Duplicated( Semester_Head,stoi(user_Choose_Semester) ));

    cout<<endl;
    School_Year::Semester* Semester_Cur = find_Semester(Semester_Head,stoi(user_Choose_Semester));

    do
    {
        Changes_Term:
        Show_Semester_Table(Year_Cur -> year, Semester_Head);
        
        Space_5_Tab(); cout<<"What do you want to change from "<<user_Choose_Semester<<" to ?. Ex: Semester 1 -> Semester 2"<<endl;
        Space_5_Tab(); cout<<"Note: There are only 3 semester from 1 -> 3. If you dont want to change pls Enter 'N' "<<endl;
        Space_5_Tab(); cout<<"Enter answer: ";

        getline(cin,user_Choose_Semester);

        if (user_Choose_Semester == "N") return;

        if (stoi(user_Choose_Semester) < 1 || stoi(user_Choose_Semester) > 3 ) 
        {
            Space_5_Tab(); cout<<"Your input Semester: "<<user_Choose_Semester<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            Space_5_Tab(); system("pause");
            cout<<"\n";
            goto Changes_Term;
        }

        if (!Check_Semester_Duplicated(Semester_Head,stoi(user_Choose_Semester) )) 
        {
            Space_5_Tab(); cout<<"Your input Semester: "<<user_Choose_Semester<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            Space_5_Tab(); system("pause");
            cout<<"\n";
        }
    } while (!Check_Semester_Duplicated(Semester_Head,stoi(user_Choose_Semester)));
    
    Semester_Cur -> Term = stoi(user_Choose_Semester);

    string user_Answer;
    Space_5_Tab(); cout<<"Wanna change Start Date, End Date of new Term? Enter (Y/N): ";
    getline(cin,user_Answer);
    
    if (user_Answer == "N") 
    {
        cout<<"\n";
        Space_5_Tab(); cout<<"Change Success"<<endl;

        Space_5_Tab(); system("pause");
        return;
    }

    Space_5_Tab(); cout<<"\nEnter Start Date: ";
    getline(cin,Semester_Cur -> start_Date);
    Space_5_Tab(); cout<<"\nEnter End Date: ";
    getline(cin,Semester_Cur -> end_Date);

    cout<<"\n";
    Space_5_Tab(); cout<<"Change Success"<<endl;

    Space_5_Tab(); system("pause");
    return;
}

//Delete Semster
void Delete_Semester(School_Year* &sYear_Cur, School_Year::Semester* &Semester_Head)
{
    if (Semester_Head == nullptr)
    {
        Space_5_Tab(); cout<<"There are nothing to be deleted. Please Create One.";
        Space_5_Tab(); system("pause");
        return;
    }

    Show_Semester_Table(sYear_Cur -> year, Semester_Head);
    
    string user_Choose_Semester = "";
        
        cin.ignore();
    do
    {
        //Menu of User choice about School-Year they want to view
            Space_5_Tab(); cout<<"Which Semester you want to Delete. Ex: 1/2/3"<<endl;
            Space_5_Tab(); cout<<"Note: If you dont want to choose any Semester pls Enter 'N' "<<endl;
            Space_5_Tab(); cout<<"Enter answer: ";

            getline(cin,user_Choose_Semester);

        if (user_Choose_Semester == "N") return;

        //Check if the user choosed Year is existed - True is it not Duplicated which mean the Data is Incorrect
        if (Check_Semester_Duplicated(Semester_Head,stoi(user_Choose_Semester))) 
        {
            Space_5_Tab(); cout<<"Your input Semester: "<<user_Choose_Semester<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            Space_5_Tab(); system("pause");
            cout<<endl;
        }

    } while (Check_Semester_Duplicated(Semester_Head,stoi(user_Choose_Semester)));

    School_Year::Semester* Semester_Cur = find_Semester(Semester_Head,stoi(user_Choose_Semester));

    //Delete all element
    Delete_Element_Of_Semester(Semester_Cur,2);

    if (Semester_Cur == Semester_Head)
    {
        if (Semester_Cur -> Next == nullptr)
            {
                Semester_Head = nullptr;
                sYear_Cur -> yearSemesterHead = Semester_Head;
                system("pause");
                return;
            }

        Semester_Head = Semester_Head -> Next;
        sYear_Cur -> yearSemesterHead = Semester_Head;
        system("pause");
        return;
    }

    School_Year::Semester* Temp_Semester = Semester_Cur;

    Semester_Cur ->  Prev -> Next = Temp_Semester -> Next;

    delete Temp_Semester;

    system("pause");

    return;
}

//View Year - ╰(*°▽°*)╯ 
//This contain Menu Classes of SChool-Year
void View_Year(School_Year* &sYear_Head)
{
    //Use a checking var to ignore line
    bool Check_Ignore = false;

    Showing_School_Year:
    //At first check if empty or not - ✔
    if (!Check_School_Year(sYear_Head)) 
        {
            Space_5_Tab(); cout<<"Nothing being added"<<endl;
            system("pause");
            return ;
        }
            else 
                {
                    Show_Year_Table(sYear_Head);
                }

    //Next step
        string user_choosed_Year = "";
        
        if (!Check_Ignore) cin.ignore();
    do
    {
        //Menu of User choice about School-Year they want to view
            Space_5_Tab(); cout<<"Which School-Year you want to view info. Ex: 2021-2022"<<endl;
            Space_5_Tab(); cout<<"Note: If you dont want to choose any year pls Enter 'N' "<<endl;
            Space_5_Tab(); cout<<"Enter answer: ";

            getline(cin,user_choosed_Year);

        if (user_choosed_Year == "N") return;

        //Declare
        const char* denim = "-"; //Use strtok - 👍
        char* temp = new char [user_choosed_Year.size()];

        // But it neeeded to convert string -> char* - 🔑
        strcpy(temp,user_choosed_Year.c_str());
        user_choosed_Year = strtok(temp, denim);

        //Check if the user choosed Year is existed - True is it not Duplicated which mean the Data is Incorrect
        if (Check_Year_Duplicated(sYear_Head,user_choosed_Year)) 
        {
            Space_5_Tab(); cout<<"Your input school-year: "<<user_choosed_Year<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            Space_5_Tab(); system("pause");
            Check_Ignore = true;
            goto Showing_School_Year;
        }

    } while (Check_Year_Duplicated(sYear_Head,user_choosed_Year));
    

    //Menu for classes in specific school-year - 📲
    int user_Choose = 0;
    School_Year* sYear_Cur = find_School_Year(sYear_Head,user_choosed_Year); // To locate the school year user is choosing
    School_Year::Year_Class* Classes_Head = sYear_Cur -> yearCLassHead; // To view or create. First is Declare
    School_Year::Semester* Semester_Head = sYear_Cur -> yearSemesterHead; //To view or create. First is Declare

    while (user_Choose != 9)
    {
        cout<<endl<<endl;

        //School year table
        Show_Year_Table(sYear_Head);

        //Classes table
        if (Classes_Head != nullptr && (user_Choose == 1 || user_Choose == 2 || user_Choose == 3 || user_Choose == 4) )
        {
            Show_Classes_Table(user_choosed_Year,Classes_Head);
        }
        
        //Semester table
        if (Semester_Head != nullptr && (user_Choose == 5 || user_Choose == 6 || user_Choose == 7 || user_Choose == 8) )
        {
            Show_Semester_Table(user_choosed_Year,Semester_Head);
        }

        Space_11_Tab(); cout<<"  Menu Functions To Control Classes/Semesters Elements"<<endl;
        Space_11_Tab(); cout<<"    1: View Info Classes in School-Year: "<<atoi(user_choosed_Year.c_str())<<"-"<<atoi(user_choosed_Year.c_str()) + 1<<endl;
        Space_11_Tab(); cout<<"    2: Create 1st Year Classes For: "<<atoi(user_choosed_Year.c_str())<<"-"<<atoi(user_choosed_Year.c_str()) + 1<<endl;
        Space_11_Tab(); cout<<"    3: Adjust A Class In School - Year: "<<atoi(user_choosed_Year.c_str())<<"-"<<atoi(user_choosed_Year.c_str()) + 1<<endl;
        Space_11_Tab(); cout<<"    4: Delete A Class In School - Year: "<<atoi(user_choosed_Year.c_str())<<"-"<<atoi(user_choosed_Year.c_str()) + 1<<endl;
        Space_11_Tab(); cout<<"    5: View Info Specific Semesters in School-Year: "<<atoi(user_choosed_Year.c_str())<<"-"<<atoi(user_choosed_Year.c_str()) + 1<<endl;
        Space_11_Tab(); cout<<"    6: Create Semesters For: "<<atoi(user_choosed_Year.c_str())<<"-"<<atoi(user_choosed_Year.c_str()) + 1<<endl;
        Space_11_Tab(); cout<<"    7: Adjust Semester For: "<<atoi(user_choosed_Year.c_str())<<"-"<<atoi(user_choosed_Year.c_str()) + 1<<endl;
        Space_11_Tab(); cout<<"    8: Delete Semester For: "<<atoi(user_choosed_Year.c_str())<<"-"<<atoi(user_choosed_Year.c_str()) + 1<<endl;
        Space_11_Tab(); cout<<"    9: Back"<<endl;
        Space_11_Tab(); cout<<"    Your choice: "; 

        cin>>user_Choose;

        cout<<endl;

        //Switch user_Choose
            switch (user_Choose)
            {
                //View Classes 
                case 1:
                {
                    //Declare
                    School_Year* sYear_Cur = find_School_Year(sYear_Head,user_choosed_Year);

                    //Functions View_Classes
                    View_Classes(user_choosed_Year,sYear_Cur -> yearCLassHead);

                    continue;

                    break;
                }

                //Create Classes
                case 2:
                {
                    //Declare
                    School_Year* sYear_Cur = find_School_Year(sYear_Head,user_choosed_Year);

                    //Functions Create_Classes
                    Create_Classes(sYear_Cur,Classes_Head);
                    
                    continue;

                    break;
                }
                
                //Adjust
                case 3:
                {
                    //Declare
                    School_Year* sYear_Cur = find_School_Year(sYear_Head,user_choosed_Year);

                    //Functions Adjust_Classes
                    Adjust_Classes(sYear_Cur,Classes_Head);

                    continue;

                    break;
                }

                //Delete
                case 4:
                {
                    //Declare
                    School_Year* sYear_Cur = find_School_Year(sYear_Head,user_choosed_Year);

                    //Functions Delete_Classes
                    Delete_Classes(sYear_Cur,Classes_Head);

                    continue;

                    break;
                }

                //View Semester
                case 5:
                {
                    //Declare
                    School_Year* sYear_Cur = find_School_Year(sYear_Head,user_choosed_Year);

                    //Functions View_Semester
                    View_Semester(user_choosed_Year,Semester_Head);

                    continue;

                    break;
                }

                //Create Semester
                case 6:
                {
                    //Declare
                    School_Year* sYear_Cur = find_School_Year(sYear_Head,user_choosed_Year);

                    //Functions Create Semester
                    Create_Semester(sYear_Cur,Semester_Head);
                    
                    continue;

                    break;
                }
                
                //Adjust Semester
                case 7:
                {
                    //Declare
                    School_Year* sYear_Cur = find_School_Year(sYear_Head,user_choosed_Year);

                    //Functions Adjust Semester
                    Adjust_Semester(sYear_Cur,Semester_Head);
                    
                    continue;

                    break;
                }

                //Delete Semester
                case 8:
                {
                    //Declare
                    School_Year* sYear_Cur = find_School_Year(sYear_Head,user_choosed_Year);

                    //Functions Adjust Semester
                    Delete_Semester(sYear_Cur,Semester_Head);
                    
                    continue;

                    break;
                }

                default:

                    break;
            }

    }

    Down_2_Line();
    Space_3_Tab(); cout<<"Ending Menu Classes..."<<endl;
    Space_3_Tab(); system("pause");
    
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
                Space_5_Tab(); cout<<"Enter School-Year (Ex: 2020-2021 or just 2021) : ";
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

        //Check if value is being duplicated or not?
        char* contain = "";
        cin.ignore();
        do
        {
            //Input
            Space_5_Tab();  cout<<"Enter School-Year (Ex: 2020-2021) : ";
            // cin.ignore();
            getline(cin,user_input);
            
            //Convert string -> char*
            char* input = new char [user_input.size()];
            strcpy( input,user_input.c_str() );

            //Strtok
            const char* denim = "-";
            contain = strtok(input,denim);

            //Print out remind user to enter value again
            if (!Check_Year_Duplicated(sYear_Head,contain)) 
                
                {
                    Space_5_Tab(); cout<<"Your data has been duplicated. Pls retry"<<endl<<endl;
                }

        } while ( !Check_Year_Duplicated(sYear_Head,contain) );

        //Check if Next year is havent existed
            while (sYear_Cur -> Next != nullptr) sYear_Cur = sYear_Cur -> Next;
            
            //Create Next Year and dont forget save the Prev
            sYear_Cur -> Next = new School_Year;
            sYear_Cur -> Next -> Prev = sYear_Cur;
            sYear_Cur = sYear_Cur -> Next;
        
        sYear_Cur -> year = contain;

        return;
}

//Adjust Year
void Adjust_Year(School_Year* &sYear_Head)
{
    if (sYear_Head == nullptr)
    {   
        Space_5_Tab(); cout<<"There are nothing to be adjusted. Please Create One.";
        Space_5_Tab(); system("pause");
        return;
    }

    bool Check_Ignore = false;
    string user_choosed_Year = "";
        
        if (!Check_Ignore) cin.ignore();
    do
    {
        //Menu of User choice about School-Year they want to view
           Space_5_Tab(); cout<<"Which School-Year you want to Adjust. Ex: 2021-2022 or 2021"<<endl;
           Space_5_Tab(); cout<<"Note: If you dont want to choose any year pls Enter 'N' "<<endl;
           Space_5_Tab(); cout<<"Enter answer: ";

            getline(cin,user_choosed_Year);

        if (user_choosed_Year == "N") return;

        //Declare
        const char* denim = "-"; //Use strtok - 👍
        char* temp = new char [user_choosed_Year.size()];

        // But it neeeded to convert string -> char* - 🔑
        strcpy(temp,user_choosed_Year.c_str());
        user_choosed_Year = strtok(temp, denim);

        //Check if the user choosed Year is existed - True is it not Duplicated which mean the Data is Incorrect
        if (Check_Year_Duplicated(sYear_Head,user_choosed_Year)) 
        {
            Space_5_Tab(); cout<<"Your input school-year: "<<user_choosed_Year<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            Space_5_Tab(); system("pause");
            cout<<"\n";
            Check_Ignore = true;
        }
    } while (Check_Year_Duplicated(sYear_Head,user_choosed_Year));

    cout<<"\n";
    School_Year* Year_Cur = find_School_Year(sYear_Head,user_choosed_Year);

    do
    {
        //Menu of User choice about School-Year they want to view
            Space_5_Tab(); cout<<"What do you want to change from "<<atoi((Year_Cur -> year).c_str()) << " - " << atoi((Year_Cur -> year).c_str()) + 1  <<" to ?. Ex: 2021-2022 -> 2022-2023"<<endl;
            Space_5_Tab(); cout<<"Note: If you dont want to change pls Enter 'N' "<<endl;
            Space_5_Tab(); cout<<"Enter answer: ";

            getline(cin,user_choosed_Year);

        if (user_choosed_Year == "N") return;

        //Declare
        const char* denim = "-"; //Use strtok - 👍
        char* temp = new char [user_choosed_Year.size()];

        // But it neeeded to convert string -> char* - 🔑
        strcpy(temp,user_choosed_Year.c_str());
        user_choosed_Year = strtok(temp, denim);

        //Check if the user choosed Year is existed - True is it not Duplicated which mean the Data is Incorrect
        if (!Check_Year_Duplicated(sYear_Head,user_choosed_Year)) 
        {
            Space_5_Tab(); cout<<"Your input school-year: "<<user_choosed_Year<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            Space_5_Tab(); system("pause");
            cout<<"\n";
            Check_Ignore = true;
        }
    } while (!Check_Year_Duplicated(sYear_Head,user_choosed_Year));

    //Assigned
    Year_Cur -> year = user_choosed_Year;

    cout<<"\n";
    Space_5_Tab(); cout<<"Change Success"<<endl;

    Space_5_Tab(); system("pause");
    return;
}

//Delete a Year
void Delete_Year(School_Year* &sYear_Head)
{
    if (sYear_Head == nullptr)
    {   
        Space_5_Tab(); cout<<"There are nothing to be deleted. Please Create One.";
        Space_5_Tab(); system("pause");
        return;
    }

    bool Check_Ignore = false;
    string user_choosed_Year = "";
        
        if (!Check_Ignore) cin.ignore();
    do
    {
        //Menu of User choice about School-Year they want to view
            Space_5_Tab(); cout<<"Which School-Year you want to Delete. Ex: 2021-2022 or 2021"<<endl;
            Space_5_Tab(); cout<<"Note: If you dont want to choose any year pls Enter 'N' "<<endl;
            Space_5_Tab(); cout<<"Enter answer: ";

            getline(cin,user_choosed_Year);

        if (user_choosed_Year == "N") return;

        //Declare
        const char* denim = "-"; //Use strtok - 👍
        char* temp = new char [user_choosed_Year.size()];

        // But it neeeded to convert string -> char* - 🔑
        strcpy(temp,user_choosed_Year.c_str());
        user_choosed_Year = strtok(temp, denim);

        //Check if the user choosed Year is existed - True is it not Duplicated which mean the Data is Incorrect
        if (Check_Year_Duplicated(sYear_Head,user_choosed_Year)) 
        {
            Space_5_Tab(); cout<<"Your input school-year: "<<user_choosed_Year<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            Space_5_Tab(); system("pause");
            Check_Ignore = true;
        }

    } while (Check_Year_Duplicated(sYear_Head,user_choosed_Year));


    School_Year* Year_Cur = find_School_Year(sYear_Head,user_choosed_Year);

    //Save for tommorrow
    Delete_Element_Of_Year(Year_Cur);

    if (Year_Cur == sYear_Head && Year_Cur -> Next == nullptr)
    {
        sYear_Head = nullptr;
        Space_5_Tab(); system("pause");
        return;
    }
    else if (Year_Cur == sYear_Head && Year_Cur -> Next != nullptr) 
        {
            sYear_Head = sYear_Head -> Next;
            sYear_Head -> Prev = nullptr;
            Space_5_Tab(); system("pause");
            return;
        }

    School_Year* Temp_Year = Year_Cur;

    Year_Cur -> Prev -> Next = Temp_Year -> Next;

    delete Temp_Year;

    Space_5_Tab(); system("pause");
    return;
}

//Menu School Year - ✍(◔◡◔)
void Menu_School_Year(School_Year* &sYear_Head)
{
    //First we need to clear screen and ask user which one they want to choose
    int user_Choose = 0;
    while (user_Choose != 5)
    {
        system("CLS");
        if (sYear_Head != nullptr)
        {
            Show_Year_Table(sYear_Head);
        }

        Space_11_Tab(); cout<<"   Menu Functions To Control School-Year Elements"<<endl;
        Space_11_Tab(); cout<<"       1: View info of a School - Year"<<endl;
        Space_11_Tab(); cout<<"       2: Create New School - Year"<<endl;
        Space_11_Tab(); cout<<"       3: Adjust A School - Year"<<endl;
        Space_11_Tab(); cout<<"       4: Delete A School - Year"<<endl;
        Space_11_Tab(); cout<<"       5: Back"<<endl;
        Space_11_Tab(); cout<<"       Your choice: "; 
        cin>>user_Choose;
        cout<<endl;

        //Better use switch
        switch (user_Choose)
        {
        
            case 1:
            {
                //In view Year there is a menu of classes
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
            
            case 3:
            {
                Adjust_Year(sYear_Head);

                continue;

                break;
            }

            case 4:
            {
                Delete_Year(sYear_Head);

                continue;

                break;
            }
            default:
                break;
        }

    }

    Space_3_Tab(); cout<<"Ending Menu School-Year"<<endl;
    Space_3_Tab(); system("pause");
    return ;
}

//Import CSV File To Staff Storage
void Read_Data_For_StudentMark(School_Year::Semester::Subject* &Subject_Cur,School_Year::Semester::Subject::Student_listMark* &Student_Head,string Name_File)
{
    finp.open(Name_File, ios::in);
    if (!finp.is_open()) 
    {
        cout<<"Please Check Your "<<Name_File<<" File"<<endl;
        return;
    }
    //Skip one line to access dir to data
    string s;
    getline(finp,s);
    
    //Declare Cur 
    School_Year::Semester::Subject::Student_listMark* Student_Cur = Student_Head;

    while (!finp.eof())
    {
        getline(finp,s);
        if (s == "") break;
        if (Student_Head == nullptr)
            {
                Student_Head = new School_Year::Semester::Subject::Student_listMark;

                char* input = new char [s.size()];
                strcpy(input,s.c_str());

                const char* denim = ",";
                int no , idStudent , midTermMark = 0, finalTermMark = 0 , otherMark = 0, totalMark = 0;

                Student_Head -> no = atoi(strtok(input,denim));
                Student_Head -> no = 0; //Automatically Update
                Student_Head -> idStudent = atoi(strtok(NULL,denim));
                Student_Head -> FullName = strtok(NULL,denim);
                Student_Head -> midTermMark = atof(strtok(NULL,denim));
                Student_Head -> finalTermMark = atof(strtok(NULL,denim));
                Student_Head -> otherMark = atof(strtok(NULL,denim));
                Student_Head -> totalMark = atof(strtok(NULL,denim));

                Subject_Cur -> yearSemesterSubStudent_ListHead = Student_Head;
                Student_Cur = Student_Head;
                continue;

            }
        while (Student_Cur -> Next != nullptr) Student_Cur = Student_Cur -> Next;

        Student_Cur -> Next = new School_Year::Semester::Subject::Student_listMark;
        Student_Cur -> Next -> Prev = Student_Cur;
        Student_Cur = Student_Cur -> Next;

        char* input = new char [s.size()];
        strcpy(input,s.c_str());

        const char* denim = ",";
        int no , idStudent , midTermMark = 0, finalTermMark = 0 , otherMark = 0, totalMark = 0;

        Student_Cur -> no = atoi(strtok(input,denim));
        Student_Cur -> no = Student_Cur -> Prev -> no + 1;
        Student_Cur -> idStudent = atoi(strtok(NULL,denim));
        Student_Cur -> FullName = strtok(NULL,denim);
        Student_Cur -> midTermMark = atof(strtok(NULL,denim));
        Student_Cur -> finalTermMark = atof(strtok(NULL,denim));
        Student_Cur -> otherMark = atof(strtok(NULL,denim));
        Student_Cur -> totalMark = atof(strtok(NULL,denim));
    }
    
    if (Student_Head == nullptr)
    {
        cout<<"Please Check Your"<<Name_File<<" File"<<endl;
        return;
    }
    finp.close();
}

//Export List of Student To Teacher
void Export_List_of_Student(School_Year* &sYear_Head)
{
//(ง •_•)ง
    //Ask user to choose school year that he want
    //Use a checking var to ignore line
    bool Check_Ignore = false;

    Showing_School_Year:
    //At first check if empty or not - ✔
    if (!Check_School_Year(sYear_Head)) 
        {
            cout<<"The School-Year Are Not Being Added. Please Try Again"<<endl;
            system("pause");
            return ;
        }
            else 
                {
                    Show_Year_Table(sYear_Head);
                }

    //Next step
        string user_choosed_Year = "";
        
        if (!Check_Ignore) cin.ignore();
    do
    {
        //Menu of User choice about School-Year they want to view
            cout<<"Which School-Year you want to choose. Ex: 2021-2022"<<endl;
            cout<<"Note: If you dont want to choose any year pls Enter 'N' "<<endl;
            cout<<"Enter answer: ";

            getline(cin,user_choosed_Year);

        if (user_choosed_Year == "N") return;

        //Declare
        const char* denim = "-"; //Use strtok - 👍
        char* temp = new char [user_choosed_Year.size()];

        // But it neeeded to convert string -> char* - 🔑
        strcpy(temp,user_choosed_Year.c_str());
        user_choosed_Year = strtok(temp, denim);

        //Check if the user choosed Year is existed - True is it not Duplicated which mean the Data is Incorrect
        if (Check_Year_Duplicated(sYear_Head,user_choosed_Year)) 
        {
            cout<<"Your input school-year: "<<user_choosed_Year<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            system("pause");
            Check_Ignore = true;
            goto Showing_School_Year;
        }

    } while (Check_Year_Duplicated(sYear_Head,user_choosed_Year));

    Check_Ignore = true;
//(ヘ･_･)ヘ┳━┳
    //Find year that user want
    School_Year* sYear_Cur = find_School_Year(sYear_Head,user_choosed_Year);
    //Setup Semester head to find semester user want
    School_Year::Semester* Semester_Head = sYear_Cur -> yearSemesterHead;

    //Use a checking var to ignore line
    Check_Ignore = false;

    //Show Semster Table
    Showing_Semester:
    if (Semester_Head == nullptr) 
        {
            cout<<"The Semester Are Not Being Added. Please Try Again"<<endl;
            system("Pause");
            return ;
        }
            else 
                {
                    Show_Semester_Table(user_choosed_Year,Semester_Head);
                }
        
        string user_Choose_Temp ="";
        int user_Choose_Semester;
    do
    {
            cout<<"Which Semester you want to choose. Ex: 1/2/3"<<endl;
            cout<<"Note: If you dont want to choose any class pls Enter 'N' "<<endl;
            cout<<"Enter answer: ";

            getline(cin,user_Choose_Temp);

        if (user_Choose_Temp == "N") return;

        user_Choose_Semester = atoi ( user_Choose_Temp .c_str());

        //Check if the user choosed Year is existed - True is it not Duplicated which mean the Data is Incorrect
        if (Check_Semester_Duplicated(Semester_Head,user_Choose_Semester)) 
        {
            cout<<"Your input Semester: "<<user_Choose_Semester<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            system("pause");
            Check_Ignore = true;
            goto Showing_Semester;
        }
    } while (Check_Semester_Duplicated(Semester_Head,user_Choose_Semester));

//ψ(._. )>
    //Find Semester user want
    School_Year::Semester* Semester_Cur = find_Semester(Semester_Head,user_Choose_Semester);
    //Set up Course head to figure out want course user want
    School_Year::Semester::Subject* Subject_Head = Semester_Cur -> yearSemesterSubjectHead;

    Showing_Course:
    if (Subject_Head == nullptr) 
        {
            cout<<"The Course Are Not Being Added. Please Try Again"<<endl;
            system("Pause");
            return ;
        }
            else 
                {
                    system("CLS");
                    Show_Subject_Table(to_string(Semester_Cur -> Term), Subject_Head);
                }

    Check_Ignore = false;
    string user_Choose_Course = "";
    School_Year::Semester::Subject* Subject_Temp = new School_Year::Semester::Subject;

    do
    {
        //Menu of User choice Course they want to view
            cout<<"Which Course you want to choose. Ex: PHY0001 "<<endl;
            cout<<"Note: If you dont want to choose any Course pls Enter 'N' "<<endl;
            cout<<"Enter Course ID: ";

            getline(cin,user_Choose_Course);


        if (user_Choose_Course == "N") return;

        Subject_Temp -> id_Subject = user_Choose_Course;

        //Check if the user choosed Subject is existed - True is it not Duplicated which mean the Data is Incorrect
        if (Check_Subject_Duplicated(Subject_Head,Subject_Temp)) 
        {
            cout<<"Your input Course: "<<Subject_Temp -> id_Subject<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            system("pause");
            Check_Ignore = true;
            goto Showing_Course;
        }
    } while (Check_Subject_Duplicated(Subject_Head,Subject_Temp));

    School_Year::Semester::Subject* Subject_Cur = find_Subject(Subject_Head,Subject_Temp);

    if (Subject_Cur -> yearSemesterSubStudent_ListHead == nullptr)
    {
        string user_choice;
        cout<<endl;
        cout<<"Your Student Hasnt Attemp This Course Yet, So List Of Student (No, Id_Student, Full_Name,Mid_Term_Mark, Final_Term_Mark, Other_Mark, Total_Mark) is Empty"<<endl;
        cout<<"Do You Want to Import a CSV File of Student List? "<<endl;
        cout<<"Enter (Y/N): ";
        getline(cin,user_choice);

        if (user_choice == "N" ) 
        {
            system("pause");
            return;
        }

        cout<<"Please enter your data in File: CSV_File/Staff_Input_JIC.csv"<<endl;
        cout<<"If u are done. ";
        system("pause");

        string Name_File = "./CSV_File/Staff_Input_JIC.csv";
        School_Year::Semester::Subject::Student_listMark* Score_Head = Subject_Cur -> yearSemesterSubStudent_ListHead;
        Read_Data_For_StudentMark(Subject_Cur,Score_Head,Name_File);
        sleep_until(system_clock::now() + seconds(1));

        if (Score_Head != nullptr)
        {
            cout<<"You Have Success Import a Input List of Student file. Here is data from your file"<<endl;
            cout<<endl;
            Show_ScoreBoard(Score_Head);
            cout<<endl;
            //Cmt
        }
    }

    //Export
    fout.open("./CSV_File/Student_List_For_Teacher.csv",ios::out);
    fout<<"No,ID,FullName,Mid,Final,Other,Total"<<endl;
    School_Year::Semester::Subject::Student_listMark* Score_Head = Subject_Cur -> yearSemesterSubStudent_ListHead;

    while (Score_Head != nullptr)
    {
        fout<<Score_Head -> no<<","<<Score_Head -> idStudent<<","<<Score_Head -> FullName<<","<<Score_Head -> midTermMark<<","<<Score_Head -> finalTermMark<<","<<Score_Head -> otherMark<<","<<Score_Head -> totalMark<<endl;
        Score_Head = Score_Head -> Next;
    }

    cout<<"Export Success"<<endl;

    //Delete after using temp_Csv
    Subject_Cur -> yearSemesterSubStudent_ListHead = nullptr;
    Delete_Element_Of_StudentList(Score_Head,2);

    Subject_Cur -> yearSemesterSubStudent_ListHead = nullptr;

    string user_Choice;
    
    cout<<"Continue Export ScoreBoard Of Other Course? Enter (Y/N): ";
    getline(cin,user_Choice);
    
    if (user_Choice == "Y") goto Showing_Course;
    system("pause");
    return;
}

//Import List Of Student To Staff
void Import_List_of_Student(School_Year* &sYear_Head)
{
//(ง •_•)ง
    //Ask user to choose school year that he want
    //Use a checking var to ignore line
    bool Check_Ignore = false;

    Showing_School_Year:
    //At first check if empty or not - ✔
    if (!Check_School_Year(sYear_Head)) 
        {
            cout<<"The School-Year Are Not Being Added. Please Try Again"<<endl;
            system("pause");
            return ;
        }
            else 
                {
                    Show_Year_Table(sYear_Head);
                }

    //Next step
        string user_choosed_Year = "";
        
        if (!Check_Ignore) cin.ignore();
    do
    {
        //Menu of User choice about School-Year they want to view
            cout<<"Which School-Year you want to choose. Ex: 2021-2022"<<endl;
            cout<<"Note: If you dont want to choose any year pls Enter 'N' "<<endl;
            cout<<"Enter answer: ";

            getline(cin,user_choosed_Year);

        if (user_choosed_Year == "N") return;

        //Declare
        const char* denim = "-"; //Use strtok - 👍
        char* temp = new char [user_choosed_Year.size()];

        // But it neeeded to convert string -> char* - 🔑
        strcpy(temp,user_choosed_Year.c_str());
        user_choosed_Year = strtok(temp, denim);

        //Check if the user choosed Year is existed - True is it not Duplicated which mean the Data is Incorrect
        if (Check_Year_Duplicated(sYear_Head,user_choosed_Year)) 
        {
            cout<<"Your input school-year: "<<user_choosed_Year<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            system("pause");
            Check_Ignore = true;
            goto Showing_School_Year;
        }

    } while (Check_Year_Duplicated(sYear_Head,user_choosed_Year));

    Check_Ignore = true;

//(ヘ･_･)ヘ┳━┳
    //Find year that user want
    School_Year* sYear_Cur = find_School_Year(sYear_Head,user_choosed_Year);
    //Setup Semester head to find semester user want
    School_Year::Semester* Semester_Head = sYear_Cur -> yearSemesterHead;

    //Use a checking var to ignore line
    //Check_Ignore = false;

    //Show Semster Table
    Showing_Semester:
    if (Semester_Head == nullptr) 
        {
            cout<<"The Semester Are Not Being Added. Please Try Again"<<endl;
            system("Pause");
            return ;
        }
            else 
                {
                    Show_Semester_Table(user_choosed_Year,Semester_Head);
                }
        
        string user_Choose_Temp ="";
        int user_Choose_Semester;
        if (!Check_Ignore) cin.ignore();
    do
    {
            cout<<"Which Semester you want to choose. Ex: 1/2/3"<<endl;
            cout<<"Note: If you dont want to choose any class pls Enter 'N' "<<endl;
            cout<<"Enter answer: ";

            getline(cin,user_Choose_Temp);

        if (user_Choose_Temp == "N") return;

        user_Choose_Semester = atoi ( user_Choose_Temp .c_str());

        //Check if the user choosed Year is existed - True is it not Duplicated which mean the Data is Incorrect
        if (Check_Semester_Duplicated(Semester_Head,user_Choose_Semester)) 
        {
            cout<<"Your input Semester: "<<user_Choose_Semester<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            system("pause");
            Check_Ignore = true;
            goto Showing_Semester;
        }
    } while (Check_Semester_Duplicated(Semester_Head,user_Choose_Semester));

//ψ(._. )>
    //Find Semester user want
    School_Year::Semester* Semester_Cur = find_Semester(Semester_Head,user_Choose_Semester);
    //Set up Course head to figure out want course user want
    School_Year::Semester::Subject* Subject_Head = Semester_Cur -> yearSemesterSubjectHead;

    Showing_Course:
    if (Subject_Head == nullptr) 
        {
            cout<<"The Course Are Not Being Added. Please Try Again"<<endl;
            system("Pause");
            return ;
        }
            else 
                {
                    system("CLS");
                    Show_Subject_Table(to_string(Semester_Cur -> Term), Subject_Head);
                }

    Check_Ignore = false;
    string user_Choose_Course = "";
    School_Year::Semester::Subject* Subject_Temp = new School_Year::Semester::Subject;

    do
    {
        //Menu of User choice Course they want to view
            cout<<"Which Course you want to choose. Ex: PHY0001 "<<endl;
            cout<<"Note: If you dont want to choose any Course pls Enter 'N' "<<endl;
            cout<<"Enter Course ID: ";

            getline(cin,user_Choose_Course);


        if (user_Choose_Course == "N") return;

        Subject_Temp -> id_Subject = user_Choose_Course;

        //Check if the user choosed Subject is existed - True is it not Duplicated which mean the Data is Incorrect
        if (Check_Subject_Duplicated(Subject_Head,Subject_Temp)) 
        {
            cout<<"Your input Course: "<<Subject_Temp -> id_Subject<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            system("pause");
            Check_Ignore = true;
            goto Showing_Course;
        }
    } while (Check_Subject_Duplicated(Subject_Head,Subject_Temp));

    School_Year::Semester::Subject* Subject_Cur = find_Subject(Subject_Head,Subject_Temp);

    cout<<"Make Sure Enter Data into File 'Student_List_For_Staff.csv' Before Import."<<endl;
    cout<<"Or If you Want to update the file 'Student_List_For_Staff.csv'. Now is your time."<<endl;
    
    sleep_until(system_clock::now() + seconds(1));

    system("pause");
    cout<<endl;

    string Name_File = "./CSV_File/Student_List_For_Staff.csv";
    School_Year::Semester::Subject::Student_listMark* Score_Head = Subject_Cur -> yearSemesterSubStudent_ListHead;
    Read_Data_For_StudentMark(Subject_Cur,Score_Head,Name_File);

    if (Score_Head != nullptr ) cout<<"Import Success"<<endl;

    string user_Choice;
    
    cout<<endl;
    cout<<"Continue Import ScoreBoard Of Other Course? Enter (Y/N): ";
    getline(cin,user_Choice);
    
    if (user_Choice == "Y") goto Showing_Course;
    system("pause");
    return;
}

//View ScoreBoard
void View_ScoreBoard_A_Course(School_Year* sYear_Head)
{
//(ง •_•)ง
    //Ask user to choose school year that he want
    //Use a checking var to ignore line
    bool Check_Ignore = false;

    Showing_School_Year:
    //At first check if empty or not - ✔
    if (!Check_School_Year(sYear_Head)) 
        {
            cout<<"The School-Year Are Not Being Added. Please Try Again"<<endl;
            system("pause");
            return ;
        }
            else 
                {
                    Show_Year_Table(sYear_Head);
                }

    //Next step
        string user_choosed_Year = "";
        
        if (!Check_Ignore) cin.ignore();
    do
    {
        //Menu of User choice about School-Year they want to view
            cout<<"Which School-Year you want to choose. Ex: 2021-2022 or 2021"<<endl;
            cout<<"Note: If you dont want to choose any year pls Enter 'N' "<<endl;
            cout<<"Enter answer: ";

            getline(cin,user_choosed_Year);

        if (user_choosed_Year == "N") return;

        //Declare
        const char* denim = "-"; //Use strtok - 👍
        char* temp = new char [user_choosed_Year.size()];

        // But it neeeded to convert string -> char* - 🔑
        strcpy(temp,user_choosed_Year.c_str());
        user_choosed_Year = strtok(temp, denim);

        //Check if the user choosed Year is existed - True is it not Duplicated which mean the Data is Incorrect
        if (Check_Year_Duplicated(sYear_Head,user_choosed_Year)) 
        {
            cout<<"Your input school-year: "<<user_choosed_Year<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            system("pause");
            Check_Ignore = true;
            goto Showing_School_Year;
        }

    } while (Check_Year_Duplicated(sYear_Head,user_choosed_Year));

    Check_Ignore = true;

//(ヘ･_･)ヘ┳━┳
    //Find year that user want
    School_Year* sYear_Cur = find_School_Year(sYear_Head,user_choosed_Year);
    //Setup Semester head to find semester user want
    School_Year::Semester* Semester_Head = sYear_Cur -> yearSemesterHead;

    //Use a checking var to ignore line
    //Check_Ignore = false;

    //Show Semster Table
    Showing_Semester:
    if (Semester_Head == nullptr) 
        {
            cout<<"The Semester Are Not Being Added. Please Try Again"<<endl;
            system("Pause");
            return ;
        }
            else 
                {
                    Show_Semester_Table(user_choosed_Year,Semester_Head);
                }
        
        string user_Choose_Temp ="";
        int user_Choose_Semester;
        if (!Check_Ignore) cin.ignore();
    do
    {
            cout<<"Which Semester you want to choose. Ex: 1/2/3"<<endl;
            cout<<"Note: If you dont want to choose any class pls Enter 'N' "<<endl;
            cout<<"Enter answer: ";

            getline(cin,user_Choose_Temp);

        if (user_Choose_Temp == "N") return;

        user_Choose_Semester = atoi ( user_Choose_Temp .c_str());

        //Check if the user choosed Year is existed - True is it not Duplicated which mean the Data is Incorrect
        if (Check_Semester_Duplicated(Semester_Head,user_Choose_Semester)) 
        {
            cout<<"Your input Semester: "<<user_Choose_Semester<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            system("pause");
            Check_Ignore = true;
            goto Showing_Semester;
        }
    } while (Check_Semester_Duplicated(Semester_Head,user_Choose_Semester));

//ψ(._. )>
    //Find Semester user want
    School_Year::Semester* Semester_Cur = find_Semester(Semester_Head,user_Choose_Semester);
    //Set up Course head to figure out want course user want
    School_Year::Semester::Subject* Subject_Head = Semester_Cur -> yearSemesterSubjectHead;

    Showing_Course:
    if (Subject_Head == nullptr) 
        {
            cout<<"The Course Are Not Being Added. Please Try Again"<<endl;
            system("Pause");
            return ;
        }
            else 
                {
                    system("CLS");
                    Show_Subject_Table(to_string(Semester_Cur -> Term), Subject_Head);
                }

    Check_Ignore = false;
    string user_Choose_Course = "";
    School_Year::Semester::Subject* Subject_Temp = new School_Year::Semester::Subject;

    do
    {
        //Menu of User choice Course they want to view
            cout<<"Which Course you want to choose. Ex: PHY0001 "<<endl;
            cout<<"Note: If you dont want to choose any Course pls Enter 'N' "<<endl;
            cout<<"Enter Course ID: ";

            getline(cin,user_Choose_Course);


        if (user_Choose_Course == "N") return;

        Subject_Temp -> id_Subject = user_Choose_Course;

        //Check if the user choosed Subject is existed - True is it not Duplicated which mean the Data is Incorrect
        if (Check_Subject_Duplicated(Subject_Head,Subject_Temp)) 
        {
            cout<<"Your input Course: "<<Subject_Temp -> id_Subject<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            system("pause");
            Check_Ignore = true;
            goto Showing_Course;
        }
    } while (Check_Subject_Duplicated(Subject_Head,Subject_Temp));

    School_Year::Semester::Subject* Subject_Cur = find_Subject(Subject_Head,Subject_Temp);

    cout<<endl;
    Show_ScoreBoard(Subject_Cur -> yearSemesterSubStudent_ListHead);
    
    string user_Choice;

    cout<<endl;
    cout<<"Continue View ScoreBoard Of Other Course? Enter (Y/N): ";
    getline(cin,user_Choice);
    
    if (user_Choice == "Y") goto Showing_Course;
    
    system("pause");
    return;
}

//Adjust Student Result
void Adjust_Student_Result(School_Year* sYear_Head)
{
   //(ง •_•)ง
    //Ask user to choose school year that he want
    //Use a checking var to ignore line
    bool Check_Ignore = false;

    Showing_School_Year:
    //At first check if empty or not - ✔
    if (!Check_School_Year(sYear_Head)) 
        {
            cout<<"The School-Year Are Not Being Added. Please Try Again"<<endl;
            system("pause");
            return ;
        }
            else 
                {
                    Show_Year_Table(sYear_Head);
                }

    //Next step
        string user_choosed_Year = "";
        
        if (!Check_Ignore) cin.ignore();
    do
    {
        //Menu of User choice about School-Year they want to view
            cout<<"Which School-Year you want to choose. Ex: 2021-2022"<<endl;
            cout<<"Note: If you dont want to choose any year pls Enter 'N' "<<endl;
            cout<<"Enter answer: ";
            getline(cin,user_choosed_Year);

        if (user_choosed_Year == "N") return;

        //Declare
        const char* denim = "-"; //Use strtok - 👍
        char* temp = new char [user_choosed_Year.size()];

        // But it neeeded to convert string -> char* - 🔑
        strcpy(temp,user_choosed_Year.c_str());
        user_choosed_Year = strtok(temp, denim);

        //Check if the user choosed Year is existed - True is it not Duplicated which mean the Data is Incorrect
        if (Check_Year_Duplicated(sYear_Head,user_choosed_Year)) 
        {
            cout<<"Your input school-year: "<<user_choosed_Year<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            system("pause");
            Check_Ignore = true;
            goto Showing_School_Year;
        }

    } while (Check_Year_Duplicated(sYear_Head,user_choosed_Year));

    Check_Ignore = true;

//(ヘ･_･)ヘ┳━┳
    //Find year that user want
    School_Year* sYear_Cur = find_School_Year(sYear_Head,user_choosed_Year);
    //Setup Semester head to find semester user want
    School_Year::Semester* Semester_Head = sYear_Cur -> yearSemesterHead;

    //Use a checking var to ignore line
    //Check_Ignore = false;

    //Show Semster Table
    Showing_Semester:

    if (Semester_Head == nullptr) 
        {
            cout<<"The Semester Are Not Being Added. Please Try Again"<<endl;
            system("Pause");
            return ;
        }
            else 
                {
                    Show_Semester_Table(user_choosed_Year,Semester_Head);
                }
        
        string user_Choose_Temp ="";
        int user_Choose_Semester;
        if (!Check_Ignore) cin.ignore();
    do
    {
            cout<<"Which Semester you want to choose. Ex: 1/2/3"<<endl;
            cout<<"Note: If you dont want to choose any class pls Enter 'N' "<<endl;
            cout<<"Enter answer: ";

            getline(cin,user_Choose_Temp);

        if (user_Choose_Temp == "N") return;

        user_Choose_Semester = atoi ( user_Choose_Temp .c_str());

        //Check if the user choosed Year is existed - True is it not Duplicated which mean the Data is Incorrect
        if (Check_Semester_Duplicated(Semester_Head,user_Choose_Semester)) 
        {
            cout<<"Your input Semester: "<<user_Choose_Semester<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            system("pause");
            Check_Ignore = true;
            goto Showing_Semester;
        }
    } while (Check_Semester_Duplicated(Semester_Head,user_Choose_Semester));

//ψ(._. )>
    //Find Semester user want
    School_Year::Semester* Semester_Cur = find_Semester(Semester_Head,user_Choose_Semester);
    //Set up Course head to figure out want course user want
    School_Year::Semester::Subject* Subject_Head = Semester_Cur -> yearSemesterSubjectHead;

    Showing_Course:
    if (Subject_Head == nullptr) 
        {
            cout<<"The Course Are Not Being Added. Please Try Again"<<endl;
            system("Pause");
            return ;
        }
            else 
                {
                    system("CLS");
                    Show_Subject_Table(to_string(Semester_Cur -> Term), Subject_Head);
                }

    Check_Ignore = false;
    string user_Choose_Course = "";
    School_Year::Semester::Subject* Subject_Temp = new School_Year::Semester::Subject;

    do
    {
        //Menu of User choice Course they want to view
            cout<<"Which Course you want to choose. Ex: PHY0001 "<<endl;
            cout<<"Note: If you dont want to choose any Course pls Enter 'N' "<<endl;
            cout<<"Enter Course ID: ";

            getline(cin,user_Choose_Course);


        if (user_Choose_Course == "N") return;

        Subject_Temp -> id_Subject = user_Choose_Course;

        //Check if the user choosed Subject is existed - True is it not Duplicated which mean the Data is Incorrect
        if (Check_Subject_Duplicated(Subject_Head,Subject_Temp)) 
        {
            cout<<"Your input Course: "<<Subject_Temp -> id_Subject<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            system("pause");
            Check_Ignore = true;
            goto Showing_Course;
        }
    } while (Check_Subject_Duplicated(Subject_Head,Subject_Temp));

    School_Year::Semester::Subject* Subject_Cur = find_Subject(Subject_Head,Subject_Temp);
    
    School_Year::Semester::Subject::Student_listMark* Score_Head = Subject_Cur -> yearSemesterSubStudent_ListHead;

    if (Score_Head == nullptr)
    {
        cout<<"There are nothing to be adjusted. Please Create One.";
        system("pause");
        return;
    }

    Show_ScoreBoard(Score_Head);
    School_Year::Semester::Subject::Student_listMark* Temp_St = nullptr;
    string user_Choice;
     do
    {
        delete Temp_St;
        Temp_St = new School_Year::Semester::Subject::Student_listMark;
        
        cout<<"Enter ID Student You Want To Change? (If not Enter 'N'): "<<endl;
        getline(cin,user_Choice);
        
        if (user_Choice == "N") return;

        Temp_St -> idStudent = atoi (user_Choice.c_str());

        if (Check_IdStu_Course_Dup(Score_Head,Temp_St)) 
        {
            cout<<"There arent any student match with your info. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            system("pause");
        }
    } while (Check_IdStu_Course_Dup(Score_Head,Temp_St));

    School_Year::Semester::Subject::Student_listMark* Score_Cur = find_Student_ScoreBoard(Score_Head,Temp_St);

    int user_Change;
    do
    {
        system("CLS");
        Show_Specific_StuResult(Score_Head,Score_Cur);

        cout<<" What do you want to change?"<<endl;
        cout<<"     1: Mid-Term Mark."<<endl;
        cout<<"     2: Final-Mark."<<endl;
        cout<<"     3: Other Mark."<<endl;
        cout<<"     4: Total."<<endl;
        cout<<"     5: Back."<<endl;
        cout<<"     Your Choice: ";
        cin>>user_Change;
        
            delete Temp_St;
            Temp_St = new School_Year::Semester::Subject::Student_listMark;

            switch (user_Change)
            {
                case 1:
                {   
                    cout<<"What Do You Want To Change Mid-Term Mark, From "<<Score_Cur -> midTermMark<<" to ?"<<endl;
                    cout<<"Enter New Mid-Term Mark: ";
                    cin>>Temp_St -> midTermMark;

                    Score_Cur -> midTermMark = Temp_St -> midTermMark;

                    break;
                }
                case 2:
                {   
                    cout<<"What Do You Want To Change Final Mark, From "<<Score_Cur -> finalTermMark<<" to ?"<<endl;
                    cout<<"Enter New Final Mark: ";
                    cin>>Temp_St -> finalTermMark;

                    Score_Cur -> finalTermMark = Temp_St -> finalTermMark;

                    break;
                }

                case 3:
                {   
                    cout<<"What Do You Want To Change Other Mark, From "<<Score_Cur -> otherMark<<" to ?"<<endl;
                    cout<<"Enter New Other Mark: ";
                    cin>>Temp_St -> otherMark;

                    Score_Cur -> otherMark = Temp_St -> otherMark;

                    break;
                }

                case 4:
                {
                    cout<<"What Do You Want To Change Total Mark, From "<<Score_Cur ->totalMark<<" to ?"<<endl;
                    cout<<"Enter New Total Mark: ";
                    cin>>Temp_St ->totalMark;

                    Score_Cur ->totalMark = Temp_St ->totalMark;
                }
            
            default:
                break;
            }
    } while (user_Change != 5);
    

    cout<<"Change Success"<<endl;  
    system("pause");
    ////
}

//Adding Course Res Student To Whole Term Result Student
void Adding_Student_Whole_Term_Result(School_Year::Semester::Subject::Student_listMark* Student_Cur, School_Year::Semester* &Term_Cur, int credit)
{
    School_Year::Semester::Student_listMark* Whole_Term_Head = Term_Cur -> yearSemesterStudent_listMarkHead;
    School_Year::Semester::Student_listMark* Whole_Term_Cur = Whole_Term_Head;
    if (Whole_Term_Head == nullptr)
    {
        Whole_Term_Head = new School_Year::Semester::Student_listMark;

        Whole_Term_Head -> no = 1;
        Whole_Term_Head -> fullName = Student_Cur -> FullName;
        Whole_Term_Head -> totalCredit = credit;
        Whole_Term_Head -> averageMark = Student_Cur -> totalMark;
        Whole_Term_Head -> GPA = Student_Cur -> totalMark * credit;
        Whole_Term_Head -> idStudent = Student_Cur -> idStudent;
        Whole_Term_Head -> count_Course_Attempt ++;

        Term_Cur -> yearSemesterStudent_listMarkHead = Whole_Term_Head;
        return;
    }

    while (Whole_Term_Cur -> Next != nullptr) Whole_Term_Cur = Whole_Term_Cur -> Next;

    Whole_Term_Cur -> Next = new School_Year::Semester::Student_listMark;
    Whole_Term_Cur -> Next -> Prev = Whole_Term_Cur;
    Whole_Term_Cur = Whole_Term_Cur -> Next;

    Whole_Term_Cur -> no = Whole_Term_Cur -> Prev -> no + 1;
    Whole_Term_Cur -> fullName = Student_Cur -> FullName;
    Whole_Term_Cur -> totalCredit = credit;
    Whole_Term_Cur -> averageMark = Student_Cur -> totalMark;
    Whole_Term_Cur -> GPA = Student_Cur -> totalMark * credit;
    Whole_Term_Cur -> idStudent = Student_Cur -> idStudent;
    Whole_Term_Cur -> count_Course_Attempt ++;

    return;
}

//Update Student Result To OverView Term Score
void Update_Student_Result_Of_A_Semester(School_Year* &sYear_Head)
{    
    //Year
    while (sYear_Head != nullptr)
    {
        //Semester
        School_Year::Semester* Semester_Head = sYear_Head -> yearSemesterHead;
            
            while (Semester_Head != nullptr)
            {
                //Update status of mark for the semester mark
                School_Year::Semester::Student_listMark* List_Mark_Head = Semester_Head -> yearSemesterStudent_listMarkHead;
                
                while (List_Mark_Head != nullptr)
                {
                    List_Mark_Head -> averageMark = 0;
                    List_Mark_Head -> count_Course_Attempt = 0;
                    List_Mark_Head -> GPA = 0;
                    List_Mark_Head -> totalCredit = 0;

                    List_Mark_Head = List_Mark_Head -> Next;
                }

                //Subject
                School_Year::Semester::Subject* Course_Head = Semester_Head -> yearSemesterSubjectHead;

                while (Course_Head != nullptr)
                {
                    School_Year::Semester::Subject::Student_listMark* Student_Res_Head = Course_Head -> yearSemesterSubStudent_ListHead;
                        while (Student_Res_Head != nullptr)
                        {
                            if (Compare_Result_Of_Whole_term(Student_Res_Head,Semester_Head -> yearSemesterStudent_listMarkHead) == nullptr)
                            {
                                Adding_Student_Whole_Term_Result(Student_Res_Head, Semester_Head, Course_Head -> number_Of_Credit);
                            }
                            else 
                            {
                                School_Year::Semester::Student_listMark* Term_Result = Compare_Result_Of_Whole_term(Student_Res_Head,Semester_Head -> yearSemesterStudent_listMarkHead);
                                
                                Term_Result -> count_Course_Attempt ++;
                                Term_Result -> totalCredit += Course_Head -> number_Of_Credit;
                                Term_Result -> GPA += Student_Res_Head -> totalMark * Course_Head -> number_Of_Credit;
                                Term_Result -> averageMark += Student_Res_Head -> totalMark;
                            
                            }

                            Student_Res_Head = Student_Res_Head -> Next;
                        }

                    //Move Next
                    Course_Head = Course_Head -> Next;
                }

                //Last update for mark each student
                School_Year::Semester::Student_listMark* Term_Result_Head = Semester_Head -> yearSemesterStudent_listMarkHead;
                while (Term_Result_Head != nullptr)
                {
                    Term_Result_Head -> averageMark = Term_Result_Head -> averageMark / Term_Result_Head -> count_Course_Attempt; //

                    Term_Result_Head -> GPA = Term_Result_Head -> GPA / Term_Result_Head ->totalCredit;

                        //Evaluate The GPA
                        if (Term_Result_Head -> GPA >= 9.5) Term_Result_Head -> GPA = 4;
                        else
                            if (Term_Result_Head -> GPA >= 8.5 && Term_Result_Head -> GPA <= 9.4) Term_Result_Head -> GPA = 4;
                            else 
                                if (Term_Result_Head -> GPA >= 8 && Term_Result_Head -> GPA <= 8.4) Term_Result_Head -> GPA = 3.5;
                                else 
                                    if (Term_Result_Head -> GPA >= 7 && Term_Result_Head -> GPA <= 7.9) Term_Result_Head -> GPA = 3;
                                else 
                                    if (Term_Result_Head -> GPA >= 6.5 && Term_Result_Head -> GPA <= 6.9) Term_Result_Head -> GPA = 2.5;
                                else 
                                    if (Term_Result_Head -> GPA >= 5.5 && Term_Result_Head -> GPA <= 6.4) Term_Result_Head -> GPA = 2;
                                else 
                                    if (Term_Result_Head -> GPA >= 5 && Term_Result_Head -> GPA <= 5.4) Term_Result_Head -> GPA = 1.5;
                                else 
                                    if (Term_Result_Head -> GPA >= 4 && Term_Result_Head -> GPA <= 4.9) Term_Result_Head -> GPA = 1;
                                else 
                                    if ( Term_Result_Head -> GPA < 4) Term_Result_Head -> GPA = 0;

                    Term_Result_Head = Term_Result_Head -> Next;
                }
                
                // If u want to show
                // cout<<"Student List Term Mark"<<endl;
                // Term_Result_Head = Semester_Head -> yearSemesterStudent_listMarkHead;
                // cout<<"No,Id,Name,Credit,Average,GPA"<<endl;
                // while (Term_Result_Head != nullptr)
                // {
                //     cout<<Term_Result_Head -> no<<" "<<Term_Result_Head -> idStudent<<" "<<Term_Result_Head -> fullName<<" "<<Term_Result_Head -> totalCredit<<" "<<Term_Result_Head -> averageMark<<" "<<Term_Result_Head -> GPA;
                //     cout<<endl;
                //     Term_Result_Head = Term_Result_Head -> Next;
                // }

                //Move Next
                Semester_Head = Semester_Head -> Next;
            }

        //Move Next
        sYear_Head = sYear_Head -> Next;
    }

    cout<<"Update Success"<<endl;
    system("pause");
    return;
}

//Menu ScoreBoard
void Menu_ScoreBoard(School_Year* sYear_Head)
{
    //Still On going
    if (sYear_Head == nullptr)
    {
        cout<<"Nothing has been added. Please Implement Function 1 Of Staff"<<endl;
        system("pause");
        return;
    }
    int user_Choose = 0;
    while (user_Choose != 5)
    {
        system("CLS");
        cout<<endl<<endl;
        cout<<"            Menu Functions To Control In/Outcome Data Of Students"<<endl;
        cout<<"             1: Export A List Of Student In a Course To Teacher"<<endl;
        cout<<"             2: Import ScoreBoard Of a Course For Staff"<<endl;
        cout<<"             3: View The ScoreBoard Of A Course"<<endl;
        cout<<"             4: Update Student Result"<<endl;
        cout<<"             5: Back"<<endl;
        cout<<"             Your choice: "; 
        cin>>user_Choose;
        cout<<endl;

        //Better use switch
        switch (user_Choose)
        {
        
            case 1:
            {
                //Export list to csv
                Export_List_of_Student(sYear_Head);
                continue;

                break;
            }

             case 2:
            {
                //Import list to csv
                Import_List_of_Student(sYear_Head);
                continue;

                break;
            }

            case 3:
            {
                //View Score Board
                View_ScoreBoard_A_Course(sYear_Head);
                continue;

                break;
            }

            case 4:
            {
                //Adjut Student Result
                Adjust_Student_Result(sYear_Head);
                continue;
            }
            default:
                system("pause");
                break;
        }

    }

    //To Finish Menu Need Update Student Res In Each Course To Term Mark
    Update_Student_Result_Of_A_Semester(sYear_Head);
    cout<<"Ending Menu ScoreBoard"<<endl;

    return ;
}

//Global Menu
void Primal_Menu(School_Year* &sYear_Head)
{
    int user_Choose = 0;
    while (user_Choose != 6)
    {
        system("CLS");
        if (sYear_Head != nullptr)
        {
            Show_Year_Table(sYear_Head);
        }
        
        Space_11_Tab(); cout<<"  Wellcome To Course Registration (Staff Functions)"<<endl;
        Space_11_Tab(); cout<<"      1: Create/Adjust Element Of Moodle"<<endl;
        Space_11_Tab(); cout<<"      2: Import/Export ScoreBoard "<<endl;
        Space_11_Tab(); cout<<"      3: Update Registration Status\n";
        Space_11_Tab(); cout<<"      4: Register a student account"<<endl;
        Space_11_Tab(); cout<<"      5: Register a staff account"<<endl;
        Space_11_Tab(); cout<<"      6: Back"<<endl;
        Space_11_Tab(); cout<<"      Your choice: "; 
        cin>>user_Choose;
        cout<<endl;

        //Better use switch
        switch (user_Choose)
        {
            case 1:
            {
                Menu_School_Year(sYear_Head);
                continue;
                break;
            }

            case 2:
            {
                //Export_List_of_Student(sYear_Head);
                Menu_ScoreBoard(sYear_Head);
                continue;
                break;
            }
            case 3:
            {
                update_registration_status(sYear_Head);
                continue;
                break;
            }

            case 4:
            {   
                newStudent:
                string studentUsername, studentPass, studentPassRetype;
                cout << "Enter student username: ";
                cin.ignore(1000, '\n');
                getline(cin, studentUsername);
                
                cout << "\nEnter password: ";
                studentPass = encryptPasswordInput();
                cout << "Retype password: ";
                studentPassRetype = encryptPasswordInput();

                while (!requestPassword(studentPass, studentPassRetype)) {
                    cout << "Please re-enter!\n";
                    cout << "Enter password: ";
                    studentPass = encryptPasswordInput();
                    cout << "Retype password: ";
                    studentPassRetype = encryptPasswordInput();
                }
                
                bool accountCreated = false;
                appendAccount(studentUsername, studentPass, 2, accountCreated);

                if (!accountCreated) goto newStudent;

                cout << "Account has been created! Please finish the profile:\n";

                Profile newProfile;

                cout << "Student ID: ";
                getline(cin, newProfile.studentID);
                cout << "First name: ";
                getline(cin, newProfile.firstName);
                cout << "Last name: ";
                getline(cin, newProfile.lastName);
                cout << "Gender: ";
                getline(cin, newProfile.gender);
                cout << "Date of Birth (DoB): ";
                getline(cin, newProfile.DoB);
                cout << "Social ID: ";
                getline(cin, newProfile.socialID);

                AppendStudentProfile(newProfile);

                break;
            }

            case 5:
            {
                string staffUsername, staffPass, staffPassRetype;
                cout << "Enter staff username: ";
                cin.ignore(1000, '\n');
                getline(cin, staffUsername);
                
                cout << "\nEnter password: ";
                staffPass = encryptPasswordInput();
                cout << "Retype password: ";
                staffPassRetype = encryptPasswordInput();

                while (!requestPassword(staffPass, staffPassRetype)) {
                    cout << "Please re-enter!\n";
                    cout << "Enter password: ";
                    staffPass = encryptPasswordInput();
                    cout << "Retype password: ";
                    staffPassRetype = encryptPasswordInput();
                }

                bool accountCreated = false;
                appendAccount(staffUsername, staffPass, 1, accountCreated);
            }

            default:
                system("pause");
                break;
        }

    }

    cout<<"Ending Menu Staff"<<endl;

    return ;
}

// Student Want to View His Score
void forStudent_ToView_ScoreBoard_Of_A_Semester(School_Year* sYear_Head)
{
    if (sYear_Head == nullptr)
    {
        cout<<"The School Staff Hasnt Publish The ScoreBoard Yet. Please Try Again"<<endl;
        system("pause");
        return;
    }
    
    // Update_Student_Result_Of_A_Semester(sYear_Head);

    int user_Choose = 0;
    while (user_Choose != 3)
    {
        system("CLS");
        cout<<"         Wellcome to course registration (Beta Ver)"<<endl;
        cout<<"             1: View ScoreBoard Of Each Course In A Specific Semester"<<endl;
        cout<<"             2: View A Overall ScoreBoard In A Specific Semseter "<<endl;
        cout<<"             3: Back"<<endl;
        cout<<"             Your choice: "; 
        cin>>user_Choose;
        cout<<endl;

        if (user_Choose == 3) break;
        
            bool Check_Ignore = false;

            Showing_School_Year:
            //At first check if empty or not - ✔
            if (!Check_School_Year(sYear_Head)) 
                {
                    cout<<"The School-Year Are Not Being Added. Please Try Again"<<endl;
                    system("pause");
                    return ;
                }
                    else 
                        {
                            Show_Year_Table(sYear_Head);
                        }

            //Next step
                string user_choosed_Year = "";
                
                if (!Check_Ignore) cin.ignore();
            do
            {
                //Menu of User choice about School-Year they want to view
                    cout<<"Which School-Year you want to choose. Ex: 2021-2022 or 2021"<<endl;
                    cout<<"Note: If you dont want to choose any year pls Enter 'N' "<<endl;
                    cout<<"Enter answer: ";

                    getline(cin,user_choosed_Year);

                if (user_choosed_Year == "N") return;

                //Declare
                const char* denim = "-"; //Use strtok - 👍
                char* temp = new char [user_choosed_Year.size()];

                // But it neeeded to convert string -> char* - 🔑
                strcpy(temp,user_choosed_Year.c_str());
                user_choosed_Year = strtok(temp, denim);

                //Check if the user choosed Year is existed - True is it not Duplicated which mean the Data is Incorrect
                if (Check_Year_Duplicated(sYear_Head,user_choosed_Year)) 
                {
                    cout<<"Your input school-year: "<<user_choosed_Year<<" is Incorrect. Please try again."<<endl;
                    
                    //Enter any key to continue and go back to  "Showing_School_Year"
                    system("pause");
                    Check_Ignore = true;
                    goto Showing_School_Year;
                }

            } while (Check_Year_Duplicated(sYear_Head,user_choosed_Year));

                Check_Ignore = true;

        //(ヘ･_･)ヘ┳━┳
            //Find year that user want
            School_Year* sYear_Cur = find_School_Year(sYear_Head,user_choosed_Year);
            //Setup Semester head to find semester user want
            School_Year::Semester* Semester_Head = sYear_Cur -> yearSemesterHead;

            //Use a checking var to ignore line
            //Check_Ignore = false;

            //Show Semster Table
            Showing_Semester:
            if (Semester_Head == nullptr) 
                {
                    cout<<"The Semester Are Not Being Added. Please Try Again"<<endl;
                    system("Pause");
                    return ;
                }
                    else 
                        {
                            Show_Semester_Table(user_choosed_Year,Semester_Head);
                        }
                
                string user_Choose_Temp ="";
                int user_Choose_Semester;
                if (!Check_Ignore) cin.ignore();
            do
            {
                    cout<<"Which Semester you want to choose. Ex: 1/2/3"<<endl;
                    cout<<"Note: If you dont want to choose any class pls Enter 'N' "<<endl;
                    cout<<"Enter answer: ";

                    getline(cin,user_Choose_Temp);

                if (user_Choose_Temp == "N") return;

                user_Choose_Semester = atoi ( user_Choose_Temp .c_str());

                //Check if the user choosed Year is existed - True is it not Duplicated which mean the Data is Incorrect
                if (Check_Semester_Duplicated(Semester_Head,user_Choose_Semester)) 
                {
                    cout<<"Your input Semester: "<<user_Choose_Semester<<" is Incorrect. Please try again."<<endl;
                    
                    //Enter any key to continue and go back to  "Showing_School_Year"
                    system("pause");
                    Check_Ignore = true;
                    goto Showing_Semester;
                }
            } while (Check_Semester_Duplicated(Semester_Head,user_Choose_Semester));

        //ψ(._. )>
            //Find Semester user want
            School_Year::Semester* Semester_Cur = find_Semester(Semester_Head,user_Choose_Semester);
            
            cout<<endl;
            cout<<"Enter Your Student ID: ";
            int Student_ID;
            cin>>Student_ID;

            cout<<endl;
            switch (user_Choose)
            {
                case 1:
                {
                    School_Year::Semester::Subject* Course_Head = Semester_Cur -> yearSemesterSubjectHead;
                    while (Course_Head != nullptr)
                    {
                        cout<<"Course: "<<Course_Head -> name_Subject<<endl;

                            School_Year::Semester::Subject::Student_listMark* Res_Head = Course_Head -> yearSemesterSubStudent_ListHead;

                            School_Year::Semester::Subject::Student_listMark* Res_User_Choose = new  School_Year::Semester::Subject::Student_listMark;

                            Res_User_Choose -> idStudent = Student_ID;
                            
                            School_Year::Semester::Subject::Student_listMark* Res_Cur = find_Student_ScoreBoard(Res_Head,Res_User_Choose);

                            Show_Specific_StuResult(Res_Head,Res_Cur);

                            cout<<endl;

                        Course_Head = Course_Head -> Next;
                    } 
                    system("pause");
                    break;
                }
            
                case 2:
                {
                    School_Year::Semester::Student_listMark* Res_Term_Mark_Head = Semester_Cur -> yearSemesterStudent_listMarkHead;

                    School_Year::Semester::Student_listMark* Res_Term_Temp = new School_Year::Semester::Student_listMark;

                    Res_Term_Temp -> idStudent = Student_ID;

                    Show_Specific_TermMark_Of_Student(Res_Term_Mark_Head,Res_Term_Temp);
                    cout<<endl;

                    system("pause");
                    break;
                }

                default:
                    break;
            }
    }
    cout<<endl;
    cout<<"Ending Menu ViewScoreBoard Student"<<endl;

    return ;
}

//Update the registration of status
void update_registration_status(School_Year* sYear_Head) {
    FILE *status;
    int res_status;
    if(registration_status()) {
        cout<<"Course Registration is OPEN, do you want to CLOSE it?\n";
        if(YOrN()==0) {
            status = fopen("Registration Status.txt", "a");
            fscanf(status, "%d", &res_status);
            res_status = 0;
            fclose(status);
        }
        else{
            cout<<"     Going back.\n";
            sleep_until(system_clock::now() + seconds(1));
            Primal_Menu(sYear_Head);
        }
    }
    else {
        cout<<"Course Registration is CLOSED, do you want to OPEN it?\n";
        if(YOrN()==0) {
            status = fopen("Registration Status.txt", "a");
            fscanf(status, "%d", &res_status);
            res_status = 1;
            fclose(status);
        }
        else
        {
            cout<<"     Going back.\n";
            sleep_until(system_clock::now() + seconds(1));
            Primal_Menu(sYear_Head);
        }
    }
}
