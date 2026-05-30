//program that enters student info (number, name, avr_grade) into a binary file and then reads the file and prints the info without writing the number of students in the file
#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void write_3(const void *filename) {
    FILE *file = fopen(filename, "wb");
    if (file  == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    Student students[3] = {
        {1, "Alex", 85.5},
        {2, "Eli", 90.0},
        {3, "Teo", 78.0}
    };

    fwrite(students, sizeof(Student), 3, file);
    fclose(file);
}

void write_4(const void *filename) {
    FILE *file = fopen(filename, "wb");
    if (file  == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    Student students[4] = {
        {1, "Alex", 85.5},
        {2, "Eli", 90.0},
        {3, "Teo", 78.0},
        {4, "Mitko", 92.0}
    };

    fwrite(students, sizeof(Student), 4, file);
    fclose(file);
}

void read(const void *filename) {
    FILE *file = fopen(filename, "rb");
    if (file  == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long fileBytes = ftell(file);
    int studentCount = fileBytes/sizeof(Student);

    fseek(file, 0, SEEK_SET);

    Student * student = malloc(sizeof(Student) * studentCount);
    fread(student, sizeof(Student), studentCount, file);

    for (int i = 0; i < studentCount; i++) {
        printf("Number: %d, Name: %s, Average Grade: %.2f\n", student[i].number, student[i].name, student[i].avr_grade);
    }

    fclose(file);
}

int main(void) {
    const char *filename = "students.bin";

    write_3(filename);
    read(filename);

    write_4(filename);
    read(filename);

    return 0;
}