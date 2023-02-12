#include "../inc/studentRecord.h"

void createStudentRecord(struct StudentRecord *student) {
    //there is no validation, assume people are entering reasonable input

    //take input to fill info for each student
    printf("Please enter the Student ID: ");
    scanf("%i", &student->studentID);

    printf("Please enter the last name for Student #%i: ", student->studentID);
    //no need to use & for strings because the variable points to a character array anyway, doesn't need the address
    scanf("%s", student->lastName);

    printf("Please enter the first name for Student #%i: ", student->studentID);
    scanf("%s", student->firstName);

    //take input for each of a students courses and store it in their record
    for (int i=0;i<NUM_COURSES;i++) {
        createCourseRecord(&student->courseRecords[i]);
    }

    //calculate the average
    student->averageMark = calculateAverage(student);
}

//could move this into the createStudentRecord function
void createCourseRecord(struct CourseRecord *course){
    printf("Please enter the course name: ");
    scanf("%s", course->courseName);

    printf("Please enter the mark for %s: ", course->courseName);
    scanf("%f", &course->mark);
}

float calculateAverage(struct StudentRecord *student){
    float marks = 0;

    for (int i=0;i<NUM_COURSES;i++) {
        marks += student->courseRecords[i].mark;
    }

    return (marks/NUM_COURSES);
}

void printReportCard(struct StudentRecord *student){
    //this function is called for each student to print their info
    printf("\n\nStudent: ID:%i Name: %s, %s\n", student->studentID, student->lastName, student->firstName);
    printf("---------------------------------------------------\n\n");

    for (int i=0;i<NUM_COURSES;i++) {
        printf("Course name: %s  Course mark: %.0f\n", student->courseRecords[i].courseName, student->courseRecords[i].mark);
    }

    printf("\nGrade Average: %.1f", student->averageMark);
}
