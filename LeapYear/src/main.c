#include "../inc/leapyear.h"

int main() {
    //setting this to 5 doesn't seem to actually limit the input to 5 characters?
    char input[5];
    int year;

    printf("Leap Checker!\n");

    do {
        printf("Enter a year to test (Enter 'N' to quit): \n");
        scanf("%s", input);

        //need to provide a special case for 0, to differentiate from atoi
        // returning a zero due to bad input below
        if (strcmp(input, "0") == 0) {
            printf("0 isn't a year!");
            //also provide a special case for N, so it doesn't
            // print an unnecessary invalid input line
        } else if (strcmp(input, "N") == 0) {
            printf("\n");
        } else {
            year = atoi(input);
            //make sure the number isn't negative:
            if (year > 0) {
                if (leapYear(year)) {
                    printf("%d IS a leap year!\n", year);
                } else {
                    printf("%d IS NOT a leap year!\n", year);
                }
                //this should catch anything atoi wasn't able to convert
                // to an int (floating points and words):
            } else {
                printf("Sorry that input is invalid..\n");
            }
        }
    //exit the loop when a user enters "N" at index 0
    } while (input[0] != 'N');

    printf("Quitting...\n");
    //print out a table of all leap years from year 1-2022:
    leapYearTable();
    return 0;
}
