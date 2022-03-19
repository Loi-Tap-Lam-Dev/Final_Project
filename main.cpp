#include "lib.h"
#include "Read_Data.cpp"
int main() {
    
    Year* yearHead = nullptr;

    readFileYear(yearHead);

    cout<<yearHead -> nameYear<<": ";
    cout<<endl<<"   ";
    for (Year::Class* year_Class_Cur = yearHead -> yearCLassHead; year_Class_Cur -> clNext != nullptr; year_Class_Cur = year_Class_Cur -> clNext)
    {
        cout<<year_Class_Cur -> nameClass<<" ";
        cout<<endl<<"       ";
            for (Year::Class::SV_List* year_Class_Sv_Cur = year_Class_Cur -> yearClassSV_ListHead;
                year_Class_Sv_Cur -> svNext != nullptr; year_Class_Sv_Cur = year_Class_Sv_Cur -> svNext)
                {
                    cout<<year_Class_Sv_Cur -> no<<" "<<year_Class_Sv_Cur -> idStudent<<" "<<year_Class_Sv_Cur -> socialID<<" "<<year_Class_Sv_Cur -> firstName<<" "<<
                    year_Class_Sv_Cur -> lastName<<" "<< year_Class_Sv_Cur -> gender<<" "<<year_Class_Sv_Cur -> dateOfBirth<<endl<<"        ";
                }
        cout<<endl<<"   ";
    }
    return 0;
}