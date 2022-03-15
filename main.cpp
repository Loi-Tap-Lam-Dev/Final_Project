#include "lib.h"
#include "Read_Data.cpp"
int main() {
    
    Year* yearHead = new Year;

    readFileYear(yearHead);

    cout<<yearHead -> nameYear;
    return 0;
}