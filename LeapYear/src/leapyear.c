#include "../inc/leapyear.h"

#define YEARS_IN_A_CENTURY 100
#define CENTURIES 21

bool leapYear(int year) {
    //this is the formula from the textbook:
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ) {
        return true;
    } else {
        return false;
    }
}

void leapYearTable() {
    int concatYear;

    printf("THE LEAP YEARS PER CENTURY REPORT: \n");
    //show all leap years in the range of years 1-2022 in the table
    for (int century=0;century<CENTURIES;century++) {
        //add 1 to century to make it user-readable
        printf("Century #%d: ", century+1);
        for (int year=1;year<=YEARS_IN_A_CENTURY;year++){
            //multiply century*100 and add the year to create the real number of the year
            concatYear = (century*YEARS_IN_A_CENTURY)+year;
            if (leapYear(concatYear)) {
                printf("%5d", concatYear);
            }
        }
        printf("\n");
    }
}
