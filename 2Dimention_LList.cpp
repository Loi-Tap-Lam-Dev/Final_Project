#include <iostream>
#include <fstream>
#include <string>

using namespace std;
fstream finp, fout;

struct Year
{
    string data;
    struct Class 
    {
        string data;
        Class* CLass_pNext = nullptr;
    };
    Class* Class_Head;
    Year* Year_pNext = nullptr;    
};


// 2 Dimentions Linked List;

int main()
{

    finp.open("Temp_in.csv",ios::in);
    fout.open("Temp_out.csv",ios::out);

    Year* Year_pHead = new Year;
    Year* Year_pCur = Year_pHead;

    int n, m; //Represent for Num of School year and classes
    cout<<"How many school years are there?. Enter n: "; 
    cin>>n;
    cout<<"How many classes are there each school year?. Enter m: ";
    cin>>m;

    for (int i = 0; i < n; i++)
    {
        //Enter YEar
        //cout<<"Enter School Year: ";
        
        getline(finp, Year_pCur -> data, ',');
        //finp>>Year_pCur -> data;

        // Declare Class
        Year :: Class* Class_pHead = new Year :: Class;
        Year :: Class* Class_pCur = Class_pHead;
        
        //Enter Class
        for (int j = 0; j < m; j++)
        {
            //cout<<"Class of School Year "<<Year_pCur -> data<<": ";
            
            if (j == m - 1) 
                {
                    getline(finp,Class_pCur -> data);
                    continue;
                }
            getline(finp,Class_pCur -> data, ',');
            //finp>>Class_pCur -> data;

            //Move to the next class
            Class_pCur -> CLass_pNext = new Year::Class;
            Class_pCur = Class_pCur ->CLass_pNext;
        }

        //Set up Class_pHead belong to the year
        Year_pCur -> Class_Head = Class_pHead;
        
        if (i == n - 1) continue;

        //Create new one and move to the next year
        Year_pCur -> Year_pNext = new Year;
        Year_pCur = Year_pCur -> Year_pNext;
    }



    //Display
    //fout<<"School Year"<<endl;
    for (Year_pCur = Year_pHead; Year_pCur != nullptr; Year_pCur = Year_pCur -> Year_pNext)
    {
        //fout year
        fout<<Year_pCur -> data<<",";

        Year :: Class* Class_pCur;
        //fout Class
        for (Class_pCur = Year_pCur -> Class_Head;
                Class_pCur != nullptr; 
                    Class_pCur = Class_pCur ->CLass_pNext)
        {
            fout<<Class_pCur -> data<<",";
        }
        fout<<endl;
    }

    //Delete
    
    while (Year_pHead != nullptr)
    {
        Year_pCur = Year_pHead;
        Year :: Class* Class_pCur = Year_pCur -> Class_Head;
        while (Class_pCur != nullptr)
        {
            Year :: Class* Class_pTemp = Class_pCur;
            Class_pCur = Class_pCur -> CLass_pNext;
            delete Class_pTemp;
        }
        Year_pHead = Year_pHead -> Year_pNext;
        delete Year_pCur;
    }

    finp.close();
    fout.close();
    return 0;
}