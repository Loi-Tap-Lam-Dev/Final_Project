#include "lib.h"
#include "Read_Data.cpp"
int main() {
    
    Year* yearHead = nullptr;

    readFileYear(yearHead);
    displayFile(yearHead);
    return 0;
}