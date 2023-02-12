//Author: Kaitlyn Archambault
//Date: September 23 2022
#include <stdio.h>

int main(void)
{
    int column;
    int row;
    int product;
    int columnReverse = 10;
    int rowReverse = 10;
    int productReverse;

    //multiplication table for n=1-10 using nested for loops
    //print a header line for all columns:
    printf("  N   1   2   3   4   5   6   7   8   9  10 \n");
    //process and print multiplication using nested for loops:
    for (row=1;row<11;row++) {
        printf("%3d ", row);
        for (column=1;column<11;column++){
            product = row*column;
            printf("%3d ", product);
        }
        printf("\n");
    }

    //blank line to distinguish tables
    printf("\n");

    //multiplication table for n = 10-1 using some variant of while loops
    //print a header line again:
    printf("  N  10   9   8   7   6   5   4   3   2   1\n");
    //process and print multiplication using while loops:
    while (rowReverse>0) {
        printf("%3d ", rowReverse);
        while (columnReverse > 0) {
            productReverse = rowReverse*columnReverse;
            printf("%3d ", productReverse);
            columnReverse--;
        }
        rowReverse--;
        columnReverse = 10;
        printf("\n");
    }
    return 0;
}