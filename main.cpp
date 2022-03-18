#include "lib.h"
#include "Read_Data.cpp"
int main() {
    
    Year* yearHead = new Year;

    readFileYear(yearHead);

    for (Year* year_Cur = yearHead; year_Cur -> yNext != nullptr; year_Cur = year_Cur -> yNext)
    {
        cout<<"Year: "<<year_Cur -> nameYear<<". Class: ";
        for (Year::Class* class_Cur = year_Cur -> yearCLassHead; class_Cur != nullptr; class_Cur = class_Cur ->clNext)
        {
            cout<<class_Cur -> nameClass<<" ";
        }
        cout<<endl;
    }
    return 0;
}