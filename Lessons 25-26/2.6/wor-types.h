#ifndef WOR_TYPES_H
#define WOR_TYPES_H

#define MAX_NAME_LENGTH 101

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee {
    char name[MAX_NAME_LENGTH];
    int subC;
    struct Employee** subs;
} Employee;

typedef FILE File;

Employee* create(const char* name, int subNum);
void freeEmp(Employee* emp);

void serialize(Employee* emp, FILE* file);
Employee* deserialize(FILE* file);

void printEmp(Employee* emp);

#endif