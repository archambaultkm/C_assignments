//
// Created by Kaitlyn Archambault on 2022-10-14.
//

#ifndef ASSIGN3_STUDENTRECORD_H
#define ASSIGN3_STUDENTRECORD_H

#define NUM_STUDENTS 3
#define NUM_COURSES 5

#include <stdio.h>
#include <string.h>

struct CourseRecord {
    char courseName[21];
    float mark;
};

struct StudentRecord {
    int studentID;
    char lastName[21];
    char firstName[21];
    struct CourseRecord courseRecords[5];
    float averageMark;
};

void createStudentRecord(struct StudentRecord *);
void createCourseRecord(struct CourseRecord *);
float calculateAverage(struct StudentRecord *);
void printReportCard(struct StudentRecord *);

#endif //ASSIGN3_STUDENTRECORD_H
