#include <stdio.h>
#include <string.h>
#include "schoolclass.h"
#include "schoolroom.h"

#define NUM_STUDENTS 2

typedef struct {
    SchoolClass classes[20];
    SchoolRoom rooms[20];
} School;

int main() {
    School school;

    school.classes[0].classNumber = 9;
    school.classes[0].classLetter = 'A';

    school.classes[0].classTeacher.birthYear = 1980;
    strcpy(school.classes[0].classTeacher.firstName, "Александър");
    strcpy(school.classes[0].classTeacher.middleName, "Димитров");
    strcpy(school.classes[0].classTeacher.lastName, "Димитров");

    school.classes[0].students[0].birthYear = 2010;
    strcpy(school.classes[0].students[0].firstName, "Александър");
    strcpy(school.classes[0].students[0].middleName, "Димитров");
    strcpy(school.classes[0].students[0].lastName, "Димитров");

    school.classes[0].students[1].birthYear = 2010;
    strcpy(school.classes[0].students[1].firstName, "Александър");
    strcpy(school.classes[0].students[1].middleName, "Димитров");
    strcpy(school.classes[0].students[1].lastName, "Димитров");


    printf("Клас: %d%c\n", school.classes[0].classNumber, school.classes[0].classLetter);

    printf("Класен ръководител: ");
    printf("%s ", school.classes[0].classTeacher.firstName);
    printf("%s ", school.classes[0].classTeacher.middleName);
    printf("%s ", school.classes[0].classTeacher.lastName);
    printf(", %d\n", school.classes[0].classTeacher.birthYear);

    printf("Ученици:\n");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("%s ", school.classes[0].students[i].firstName);
        printf("%s ", school.classes[0].students[i].middleName);
        printf("%s ", school.classes[0].students[i].lastName);
        printf(", %d\n", school.classes[0].students[i].birthYear);
    } 
    return 0;
}
