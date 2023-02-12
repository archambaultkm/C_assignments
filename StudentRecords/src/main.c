#include "../inc/studentRecord.h"

int main() {
    //create 3 student records
    struct StudentRecord students[NUM_STUDENTS];

    for (int i=0;i<NUM_STUDENTS;i++) {
        //the location needs to be passed into the function with & so that
        // the pointer used inside the function changes the source values
        createStudentRecord(&students[i]);
    }

    //print out their report cards
    printf("***************************REPORT CARDS***************************\n\n");
    for (int i=0;i<NUM_STUDENTS;i++) {
        printReportCard(&students[i]);
    }

    return 0;
}
